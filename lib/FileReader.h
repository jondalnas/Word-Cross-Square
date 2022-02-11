#pragma once

#include <string>
#include <vector>

namespace FileReader {
	void readFile(const char* fileName, uint8_t wordLength, std::vector<std::string*>* wordMatch);
}