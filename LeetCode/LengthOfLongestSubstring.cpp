//
// Created by root on 11/29/17.
//

#include <iostream>
#include <vector>

/*
 * Given a string, find the length of the longest substring without repeating characters.
 * Examples:
 * Given "abcabcbb", the answer is "abc", which the length is 3.
 * Given "bbbbb", the answer is "b", with the length of 1.
 * Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
 */


int lengthOfLongestSubstring(std::string s) {
    if (s.size() <= 1)
        return s.size();

    std::vector<int> hash(256, -1);
    int max_len = 0;
    int start = -1;
    for (int i = 0; i < s.size(); ++i) {
        if (hash[s[i]] > start) {
            start = hash[s[i]];
        }
        hash[s[i]] = i;
        max_len = std::max(max_len, i - start);
    }
    return max_len;
}
