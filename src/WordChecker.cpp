#include "WordChecker.h"

namespace WordChecker {
    std::vector<wordPair_t> checkWord(std::vector<std::string*>* words, uint8_t charMatchLocation) {
        std::vector<wordPair_t> res;
        for (uint64_t i = 0; i < words->size(); i++) {
            auto char0 = words->at(i)->at(charMatchLocation); //Char match of first string

            if (words->at(0) == 0 || words->at(1) == 0 || words->at(2) == 0 || words->at(3) == 0 || words->at(4) == 0)
                printf("Hoi");

            for (uint64_t u = i + 1; u < words->size(); u++) {
                auto char1 = words->at(u)->at(charMatchLocation); //Char match of first string
                
                if (char0 == char1) {
                    res.push_back({words->at(i), words->at(u)});
                }
            }
        }

        return res;
    }

    void printChar(uint8_t c) {
        if (c == 26 + 1) {
            //Æ
            printf("ae");
        } else if (c == 27 + 1) {
            //Ø
            printf("oe");
        } else if (c == 28 + 1) {
            //Å
            printf("aa");
        } else {
            printf("%c", c + 'a' - 1);
        }
    }

    void printWord(std::string* word) {
        for (uint64_t i = 0; i < word->size(); i++) {
            printChar(word->at(i));
        }
    }
}