//
// Created by root on 11/30/17.
//

/*
 * Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
 *
 * If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).
 *
 * The replacement must be in-place, do not allocate extra memory.
 *
 * Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
 * 1,2,3 → 1,3,2
 * 3,2,1 → 1,2,3
 * 1,1,5 → 1,5,1
 */
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

void nextPermutation(vector<int>& nums) {
    unsigned long k;
    for (k = nums.size() - 2; k >= 0; --k) {
        if (nums[k] < nums[k+1]) {
            break;
        }
    }

    if (k == -1) {
        std::reverse(nums.begin(), nums.end());
        return;
    }

    unsigned long l;
    for (l = nums.size() - 1; l > k; --l) {
        if (nums[l] > nums[k]) {
            break;
        }
    }
    std::swap(nums[l], nums[k]);
}

void unitTestNextPermutation() {
    int array[] = {1, 2, 3, 4, 5};
    vector<int> data(array, array + sizeof(array)/sizeof(array[0]));

    for (auto i = 0; i < 10; ++i) {
        nextPermutation(data);
        for (auto item: data) {
            cout << item << " ";
        }
        cout << endl;
    }
}
