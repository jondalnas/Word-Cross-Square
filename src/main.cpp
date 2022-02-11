#include <stdio.h>
#include <iostream>
#include <vector>

#include "FileReader.h"
#include "Error.h"
#include "Tools.h"
#include "WordChecker.h"

int main(int numArgs, char** args) {
	if (numArgs < 3) {
		Errors::tooFewArgumentsError();
		return 0;
	}

	uint64_t wordLength = Tools::convCharPtrToNum(args[1]);
	uint64_t matchLocation = Tools::convCharPtrToNum(args[2]);

	//Read file
	std::vector<std::string*> wordMatches;
	FileReader::readFile("dic/Danish.dic", wordLength, &wordMatches);

	//Delete duplicates
	std::vector<std::string*> wordMatchesNoDup;
	Tools::removeDuplicateWords(&wordMatches, &wordMatchesNoDup);

	//Process words
	std::vector<WordChecker::wordPair_t> pairs = WordChecker::checkWord(&wordMatchesNoDup, matchLocation);
	for (uint64_t i = 0; i < pairs.size(); i++) {
		WordChecker::wordPair_t pair = pairs[i];
		
		WordChecker::printWord(pair.word0);
		printf(" ");
		WordChecker::printWord(pair.word1);
		printf("\n");
		
		//std::cout << *(wordMatchesNoDup[pair.index0]) << " " << *(wordMatchesNoDup[pair.index1]) << std::endl;
	}

	//Delete words
	for (uint64_t i = 0; i < wordMatches.size(); i++) {
		delete wordMatches.at(i);
	}
}