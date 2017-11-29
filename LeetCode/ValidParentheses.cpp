//
// Created by root on 11/29/17.
//

/*
 * Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
 * The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
 */

#include <string>
#include <stack>
#include <map>

bool isValid(std::string s) {
    if (s.size() <= 1 || s.size() % 2 == 1) {
        return false;
    }

    std::stack<char> bank;
    std::map<char, int> hash_map;
    hash_map['('] = 1;
    hash_map['['] = 2;
    hash_map['{'] = 3;
    hash_map[')'] = -1;
    hash_map[']'] = -2;
    hash_map['}'] = -3;

    for (auto element: s) {
        if (hash_map[element] > 0) {
            bank.push(element);
        } else {
            if (bank.empty()) {
                return false;
            }
            char ch = bank.top();
            bank.pop();
            if (hash_map[ch] + hash_map[element] != 0) {
                return false;
            }
        }
    }
    return bank.empty();
}
