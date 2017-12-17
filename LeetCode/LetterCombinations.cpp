//
// Created by root on 11/29/17.
//


#include <string>
#include <vector>
#include <queue>
#include <iostream>

std::vector<std::string> letterCombinations(std::string digits)
{
    std::vector<std::string> res;
    if (digits.empty()) {
        return res;
    }
    std::queue<std::string> str_queue;
    std::string dict[] = {"abc", "def", "ghi","jkl","mno","pqrs","tuv","wxyz"};

    for (auto ch: dict[digits[0] - '2']) {
        str_queue.push(std::string(1, ch));
    }

    for (int i = 1; i < digits.size(); ++ i) {
        auto size = str_queue.size();
        for (int k = 0; k < size; ++ k) {
            for (auto ch: dict[digits[i] - '2']) {
                str_queue.push(str_queue.front() + ch);
            }
            str_queue.pop();
        }
    }

    while (!str_queue.empty()) {
        res.push_back(std::move(str_queue.front()));
        str_queue.pop();
    }
    return res;
}
