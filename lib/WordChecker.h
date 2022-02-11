#pragma once

#include <stdint.h>
#include <vector>
#include <string>

namespace WordChecker {
    typedef struct {
        std::string *word0, *word1;
    } wordPair_t;
    
    std::vector<wordPair_t> checkWord(std::vector<std::string*>* words, uint8_t charMatchLocation);

    void printChar(uint8_t c);
    void printWord(std::string* str);
}