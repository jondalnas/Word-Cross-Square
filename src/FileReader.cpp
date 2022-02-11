#include "FileReader.h"

#include <fstream>
#include <cstring>

namespace FileReader {
	void readFile(const char* fileName, uint8_t wordLength, std::vector<std::string*>* wordMatches) {
		std::ifstream inputFile(fileName);

		std::string line;
		while(getline(inputFile, line)) {
			if (line.size() <= wordLength) continue; //Too short

			std::string* word = new std::string();
			uint8_t wordLen = 0;
			for (uint8_t i = 0; i < line.size(); i++) {
				uint8_t c = static_cast<uint8_t>(line.at(i));

				if (c == '/' || c == 0) break; //End of word line

				if (c == 0xC3) continue; //Escape sequence for æøå

				//Check for upper case ÆØÅ
				if (c == 134 || c == 134 + 32) {
					c = 26 + 1;
				} else if (c == 152 || c == 152 + 32) {
					c = 27 + 1;
				} else if (c == 133 || c == 133 + 32) {
					c = 28 + 1;
				} else {
					c = std::tolower(c) - 'a' + 1;
				}

				word->push_back(c);
				wordLen++;
				
				if (wordLen > wordLength) goto next; //Too long
			}

			if (wordLen != wordLength) continue; //Too short

			wordMatches->push_back(word);

			next:;
		}
	}
}