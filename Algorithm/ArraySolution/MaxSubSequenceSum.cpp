//
// Created by root on 11/24/17.
//

#include <exception>
#include <iostream>

//int max_sub_sequence_sum(int data[], int length) {
//    if (data == nullptr || length < 0) {
//        throw std::exception();
//    }
//
//    if (length == 0) return data[0];
//
//    int current_sum = data[0];
//    int max_sum = data[0];
//
//    for (int i = 1; i < length; ++i) {
//        current_sum += data[i];
//
//        if (current_sum < 0) {
//            current_sum = data[i];
//        }
//        else {
//            if (current_sum > max_sum) {
//                if (current_sum < data[i]) {
//                    current_sum = data[i];
//                }
//                max_sum = current_sum;
//            }
//        }
//    }
//    return max_sum;
//}


int maxSum(int *A, const int length) {
    int nStart = A[length - 1];
    int nAll = A[length - 1];

    for (int i = length - 2; i >= 0; --i) {
        nStart = std::max(A[i], A[i] + nStart);
        nAll = std::max(nStart, nAll);
    }
    return nAll;
}

void unitTestMaxSum() {
    int data[] = {1,2,3,4,5};
    std::cout << maxSum(data, 5) << std::endl;

    int data_2[] = {-2, 1, 2, 4, 5};
    std::cout << maxSum(data_2, 5) << std::endl;

    int data_3[] = {1, 2, -3, 4, 5};
    std::cout << maxSum(data_3, 5) << std::endl;

    int data_4[] = {-3, 3, -3, -4, -5};
    std::cout << maxSum(data_4, 5) << std::endl;
}

//void unit_test_max_sub_sequence_sum()
//{
//    int data[] = {1,2,3,4,5};
//    std::cout << max_sub_sequence_sum(data, 5) << std::endl;
//
//    int data_2[] = {-2, 1, 2, 4, 5};
//    std::cout << max_sub_sequence_sum(data_2, 5) << std::endl;
//
//    int data_3[] = {1, 2, -3, 4, 5};
//    std::cout << max_sub_sequence_sum(data_3, 5) << std::endl;
//
//    int data_4[] = {-3, 3, -3, -4, -5};
//    std::cout << max_sub_sequence_sum(data_4, 5) << std::endl;
//}
//
