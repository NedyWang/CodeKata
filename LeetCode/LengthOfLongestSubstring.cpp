//
// Created by root on 11/29/17.
//

#include <iostream>
#include <vector>

/**
 * Given a string, find the length of the longest substring without repeating characters.
 * Examples:
 * Given "abcabcbb", the answer is "abc", which the length is 3.
 * Given "bbbbb", the answer is "b", with the length of 1.
 * Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
 */

ssize_t lengthOfLongestSubstring(std::string s)
{
    if (s.size() <= 1) {
        return s.size();
    }

    std::vector<int> last_position(256, -1);
    int start = -1;
    ssize_t max_len = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (last_position[s[i]] > start) {
            start = last_position[s[i]];
        }
        last_position[s[i]] = i;
        max_len = std::max(max_len, i - start);
    }
    return max_len;
}
