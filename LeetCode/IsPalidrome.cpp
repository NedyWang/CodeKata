//
// Created by root on 11/29/17.
//

/**
 * Determine whether an integer is a palindrome. Do this without extra space.
 */

bool isPalindrome(int x) {
    if (x < 0 || (x != 0 && x % 10 == 0)) return false;
    int right = 0;
    while (x > right) {
        right = right * 10 + x % 10;
        x /= 10;
    }
    return (x == right || x == right / 10);
}
