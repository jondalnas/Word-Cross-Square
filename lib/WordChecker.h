#pragma once

#include <stdint.h>
#include <vector>
#include <string>

namespace WordChecker {
    typedef struct {
        std::string *word0, *word1;
    } wordPair_t;
    
    std::vector<wordPair_t> checkWord(std::vector<std::string*>* words, uint8_t charMatchLocation);
    std::vector<std::vector<std::string*>> checkWord(std::vector<std::string*>* words, uint64_t* charMatchLocation, uint64_t numMatches);

    void printChar(uint8_t c);
    void printWord(std::string* str);
}