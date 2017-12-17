//
// Created by root on 11/29/17.
//


#include <string>
#include <vector>
#include <queue>
#include <iostream>

std::vector<std::string> letterCombinations(std::string digits) {
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
            std::string str = std::move(str_queue.front());
            str_queue.pop();
            for (auto ch: dict[digits[i] - '2']) {
                str_queue.push(str + ch);
            }
        }
    }

    while (!str_queue.empty()) {
        res.push_back(std::move((str_queue.front())));
        str_queue.pop();
    }
    return res;
}
