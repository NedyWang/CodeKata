//
// Created by root on 11/29/17.
//

#include <iostream>
#include <vector>

/**
 *Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.
 * Example:
 * Input: "babad"
 * Output: "bab"
 * Note: "aba" is also a valid answer.
 */

std::string longestPalindrome(std::string s) {
    if (s.size() <= 1) return s;
    int start = 0;
    int max_len = 1;
    for (int mid = 0; mid < s.size();) {
        if (max_len >= s.size() - mid) break;
        int left, right;

        left = right = mid;
        while (right < s.size() - 1 && s[right] == s[right + 1]) ++right;

        mid = right + 1;
        while (left > 0 && right < s.size() - 1 && s[left - 1] == s[right + 1]) {
            --left;
            ++right;
        }
        if (right - left > max_len) {
            max_len = right - left;
            start = left;
        }
    }
    return s.substr(start, max_len);
}
