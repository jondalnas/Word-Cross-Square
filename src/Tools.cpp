#include "Tools.h"

#include <cstring>

namespace Tools {
    void removeDuplicateWords(std::vector<std::string*>* words, std::vector<std::string*>* out) {
        for (uint64_t i = 0; i < words->size(); i++) {
            std::string* word = words->at(i);
            if (!binarySearchWords(out, 0, out->size(), word)) {
                out->push_back(word);
            }
        }
    }

    int binarySearchWords(std::vector<std::string*>* array, uint64_t start, uint64_t end, std::string* word) {
        if (start == end) return 0; //If start = end, then we have hit the last result and should return

        uint64_t mid = start + (end - start) / 2;

        auto res = strcmp(array->at(mid)->c_str(), word->c_str());
        if (res == 0) {
            return 1; //Match
        } else if (res < 0) {
            //mid < word, move to last half
            if (mid == end) return 0;
            return binarySearchWords(array, mid + 1, end, word);
        } else {
            //mid > word, move to first half
            if (mid == start) return 0;
            return binarySearchWords(array, start, mid - 1, word);
        }
    }
    
    uint64_t convCharPtrToNum(char* num) {
        uint64_t res = 0;
        char curr;
        for (uint8_t i = 0; (curr = num[i]); i++) {
            res *= 10;
            res += curr - '0';
        }

        return res;
    }
}