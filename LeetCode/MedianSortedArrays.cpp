//
// Created by root on 11/29/17.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;


/**
*There are two sorted arrays nums1 and nums2 of size m and n respectively.
* Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
*
* Example 1:
* nums1 = [1, 3]
* nums2 = [2]
*
* The median is 2.0
* Example 2:
* nums1 = [1, 2]
* nums2 = [3, 4]
*
* The median is (2 + 3)/2 = 2.5
*/

int get_kth(vector<int> &array_a, vector<int> &array_b, unsigned long k) {
    if (array_a.size() > array_b.size()) {
        return get_kth(array_b, array_a, k);
    }

    if (array_a.empty()) {
        return array_b[k - 1];
    }

    if (k == 1) {
        return min(array_a[0], array_b[0]);
    }

    auto index_a = min(k / 2, array_a.size());
    auto index_b = k - index_a;
    if (array_a[index_a - 1] < array_b[index_b - 1]) {
        vector<int> array_a_slice(array_a.begin() + index_a, array_a.end());
        return get_kth(array_a_slice, array_b, k - index_a);
    } else if (array_a[index_a - 1] > array_b[index_b - 1]) {
        vector<int> array_b_slice(array_b.begin() + index_b, array_b.end());
        return get_kth(array_a, array_b_slice, k - index_b);
    } else
        return array_a[index_a - 1];
}


double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    unsigned long totalNum = nums1.size() + nums2.size();
    if (totalNum & 0x01)
        return get_kth(nums1, nums2, totalNum / 2 + 1);
    else
        return double(get_kth(nums1, nums2, totalNum / 2) + get_kth(nums1, nums2, totalNum / 2 + 1)) / 2;
}

int getKth(int *begin_A, int *end_A, int *begin_B, int *end_B, unsigned long k)
{
    auto len_A = (end_A - begin_A)/sizeof(int);
    auto len_B = (end_B - begin_B)/sizeof(int);

    if (len_A > len_B) {
        return getKth(begin_B, end_B, begin_A, end_A, k);
    }

    if (len_A == 0) {
        return *(begin_B + k);
    }

    if (k == 1) {
        return std::min(*begin_A, *begin_B);
    }

    auto nth_A = std::min(len_A, k >> 1);
    auto nth_B = k - nth_A;

    if (*(begin_A + nth_A - 1) == *(begin_B + nth_B - 1)) {
        return *(begin_A + nth_A - 1);
    } else if (*(begin_A + nth_A - 1) < *(begin_B + nth_B - 1)) {
        return getKth(begin_A + nth_A, end_A, begin_B, end_B, nth_B);
    } else {
        return getKth(begin_A, end_A, begin_B + nth_B, end_B, nth_A);
    }
}
