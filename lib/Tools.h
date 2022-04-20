#pragma once

#include <string>
#include <vector>

namespace Tools {
    void removeDuplicateWords(std::vector<std::string*>* words, std::vector<std::string*>* out);

    int binarySearchWords(std::vector<std::string*>* array, uint64_t start, uint64_t end, std::string* word);

    uint64_t convCharPtrToNum(const char* num);

    uint64_t convCharPtrToNums(const char* num, uint64_t** nums);
}