//
// Created by root on 11/29/17.
//

/*
 * Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
 *
 * For example, given n = 3, a solution set is:
 * [
 *   "((()))",
 *   "(()())",
 *   "(())()",
 *   "()(())",
 *   "()()()"
 * ]
 *
 */

#include <string>
#include <vector>

void do_generateParenthesis(std::vector<std::string> &result, std::string str, int n, int m) {
    if (n == 0 && m == 0) {
        result.push_back(str);
        return;
    }

    if (n > 0) {
        do_generateParenthesis(result, str + "(", n - 1, m + 1);
    }

    if (m > 0) {
        do_generateParenthesis(result, str + ")", n, m - 1);
    }
}

std::vector<std::string> generateParenthesis(int n) {
    std::vector<std::string> result;
    do_generateParenthesis(result, "", n, 0);
    return result;
}
