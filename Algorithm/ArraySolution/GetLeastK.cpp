//
// Created by root on 11/21/17.
//

#include <set>
#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include "ArraySolution.h"
#include "../SortSolution/SortSolution.h"

int ArraySolution::GetLeastNumbersMethod_1(int *data, int length, int *output, int k) {
    if (data == nullptr || length < 0 || k < 0 || k > length) {
        throw std::exception();
    }

    int start = 0, end = length - 1;
    int index = SortSolution::partition(data, start, end);
    while (k - 1 != index) {
        if (index < k - 1) {
            start = index + 1;
        } else {
            end = index - 1;
        }
        index = SortSolution::partition(data, start, end);
    }

    for (int i = 0; i < k; ++i) {
        output[i] = data[i];
        std::cout << output[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}

int ArraySolution::GetLeastNumbersMethod_2(std::vector<int> &data, int number) {
    std::multiset<int, std::greater<int> > maxHeap;
    for (auto iter: data) {
        if (maxHeap.size() < number) {
            maxHeap.insert(iter);
        } else {
            auto top = maxHeap.begin();
            if (*top > iter) {
                maxHeap.erase(top);
                maxHeap.insert(iter);
            }
        }
    }

    for (auto iter: maxHeap) {
        std::cout << iter << " ";
    }
}
