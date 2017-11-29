//
// Created by root on 11/29/17.
//


#include <string>
#include <vector>
#include <queue>

std::vector<std::string> letterCombinations(std::string digits) {
    std::vector<std::string> res;
    if (digits.size() == 0) {
        return res;
    }
    std::queue<std::string> str_queue;
    std::string dict[] = {"abc", "def", "ghi","jkl","mno","pqrs","tuv","wxyz"};

    for (int j = 0; j < dict[digits[0] - '2'].size(); ++j) {
        std::string tmp(1, dict[digits[0] - '2'][j]);
        str_queue.push(tmp);
    }

    for (int i = 1; i < digits.size(); ++ i) {
        int size = str_queue.size();
        for (int k = 0; k < size; ++ k) {
            std::string str = str_queue.front();
            str_queue.pop();
            for (int j = 0; j < dict[digits[i] - '2'].size(); ++j) {
                str_queue.push(str + dict[digits[i] - '2'][j]);
            }
        }
    }

    while (!str_queue.empty()) {
        res.push_back(str_queue.front());
        str_queue.pop();
    }
    return res;
}
