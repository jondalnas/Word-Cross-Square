#include <stdio.h>
#include <iostream>
#include <vector>

#include "FileReader.h"
#include "Error.h"
#include "Tools.h"
#include "WordChecker.h"

int main(int numArgs, char** args) {
	if (numArgs < 4) {
		Errors::tooFewArgumentsError();
		return 0;
	}

	uint64_t wordLength = Tools::convCharPtrToNum(args[2]);

	uint64_t* matchLocations;
	uint64_t numMathces = Tools::convCharPtrToNums(args[3], &matchLocations);

	//Read file
	std::vector<std::string*> wordMatches;
	FileReader::readFile(args[1], wordLength, &wordMatches);

	//Delete duplicates
	std::vector<std::string*> wordMatchesNoDup;
	Tools::removeDuplicateWords(&wordMatches, &wordMatchesNoDup);

	//Process words
	std::vector<std::vector<std::string*>> matches = WordChecker::checkWord(&wordMatchesNoDup, matchLocations, numMathces);
	for (uint64_t i = 0; i < matches.size(); i++) {
		std::vector<std::string*> match = matches[i];
		
		for (auto j = 0; j < numMathces * 2; j++) {
			WordChecker::printWord(match[j]);
			printf(" ");
		}
		printf("\n");
		
		//std::cout << *(wordMatchesNoDup[pair.index0]) << " " << *(wordMatchesNoDup[pair.index1]) << std::endl;
	}

	//Delete words
	for (uint64_t i = 0; i < wordMatches.size(); i++) {
		delete wordMatches.at(i);
	}

	free(matchLocations);
}