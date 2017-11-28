//
// Created by root on 11/17/17.
//

#include <cstdlib>
#include <iostream>
#include <cstring>
#include "SortSolution.h"


int SortSolution::partition(int data[], int start, int end) {
    int index = random_in_range(start, end);
    std::swap(data[index], data[end]);
    int small = start - 1;
    for (index = start; index < end; ++index) {
        if (data[index] < data[end]) {
            ++small;
            if (index != small) {
                std::swap(data[index], data[small]);
            }
        }
    }
    ++small;
    std::swap(data[small], data[end]);
    return small;
}

void SortSolution::quick_sort(int data[], int start, int end) {
    if (start > end) {
        return;
    }
    int index = partition(data, start, end);
    if (index >= start) {
        quick_sort(data, start, index - 1);
    }
    if (index <= end) {
        quick_sort(data, index + 1, end);
    }
}

template<typename T>
void SortSolution::mergeSort(T data[], int length) {
    if (data == nullptr || length <= 1) {
        return;
    }
    SortSolution::doMergeSort(data, 0, length - 1);
}

template<typename T>
void SortSolution::doMergeSort(T data[], int start, int end) {
    if (start >= end) {
        return;
    }

    int mid = (start + end) / 2;
    doMergeSort(data, start, mid);
    doMergeSort(data, mid+1, end);
    SortSolution::doMerge(data, start, mid, end);
}

template<typename T>
void SortSolution::doMerge(T *data, int start, int mid, int end) {
    int i = start, j = mid+1;
    auto sorted = new T[end - start + 1];
    int index = 0;

    while (i <= mid && j <= end) {
        sorted[index++] = data[i] < data[j] ? data[i++] : data[j++];
    }

    while (i <= mid) {
        sorted[index++] = data[i++];
    }

    while (j <= end) {
        sorted[index++] = data[j++];
    }

    std::memcpy(data + start, sorted, (end - start + 1)*sizeof(*data));
    delete[](sorted);
}

void SortSolution::unitTestQuickSort() {
    int data[] = {1, 4, 5, 2, 9};
    quick_sort(data, 0, 4);
    for (auto x: data) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
}

void SortSolution::unitTestMergeSort() {
    int data[] = {1, 4, 5, 2};
    mergeSort(data, 4);
    for (auto x: data) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
}

void SortSolution::unitTest(){
    unitTestMergeSort();
}
