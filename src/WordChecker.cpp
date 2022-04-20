#include "WordChecker.h"

namespace WordChecker {
    std::vector<wordPair_t> checkWord(std::vector<std::string*>* words, uint8_t charMatchLocation) {
        std::vector<wordPair_t> res;
        for (uint64_t i = 0; i < words->size(); i++) {
            auto char0 = words->at(i)->at(charMatchLocation); //Char match of first string

            for (uint64_t u = i + 1; u < words->size(); u++) {
                auto char1 = words->at(u)->at(charMatchLocation); //Char match of first string
                
                if (char0 == char1) {
                    res.push_back({words->at(i), words->at(u)});
                }
            }
        }

        return res;
    }

    std::vector<std::vector<std::string*>> checkWord(std::vector<std::string*>* words, uint64_t* charMatchLocation, uint64_t numMatches) {
        std::vector<std::vector<std::string*>> res;
        uint64_t wordIndicies[numMatches*2];
        
        for (auto i = 0; i < numMatches*2; i++) {
            wordIndicies[i] = 0;
        }

        while (1) {
            bool shouldAdd = true;
            for (auto row = 0; row < numMatches && shouldAdd; row++) {
                std::string *rowWord = words->at(wordIndicies[row]);
                for (auto col = 0; col < numMatches && shouldAdd; col++) {
                    std::string *colWord = words->at(wordIndicies[col + numMatches]);

                    if (rowWord->at(charMatchLocation[col]) != colWord->at(charMatchLocation[row])) shouldAdd = false;
                }
            }
            if (shouldAdd) {
                std::vector<std::string*> matchedWords;
                for (auto i = 0; i < numMatches*2; i++) {
                    matchedWords.push_back((*words)[wordIndicies[i]]);
                }
                res.push_back(matchedWords);
            }

            //Update word indicies
            wordIndicies[0]++;
            for (auto i = 0; i < numMatches*2; i++) {
                if (wordIndicies[i] >= words->size()) {
                    if (i == numMatches * 2 - 1) return res;

                    wordIndicies[i+1]++;
                    wordIndicies[i] = 0;
                }
            }
        }
    }

    void printChar(uint8_t c) {
        if (c == 0x80) {
            //Æ
            printf("æ");
        } else if (c == 0x81) {
            //Ø
            printf("ø");
        } else if (c == 0x82) {
            //Å
            printf("å");
        } else {
            printf("%c", c);
        }
    }

    void printWord(std::string* word) {
        for (uint64_t i = 0; i < word->size(); i++) {
            printChar(word->at(i));
        }
    }
}