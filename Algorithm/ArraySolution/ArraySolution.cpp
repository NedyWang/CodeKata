//
// Created by root on 11/17/17.
//

#include <set>
#include <iostream>
#include <exception>
#include <vector>
#include <cstring>
#include "ArraySolution.h"
#include "../SortSolution/SortSolution.h"

int minInArray(const int *data, int length);

void ArraySolution::unitTestGetLeastNumbersMethod_1() {
    int data[] = {4, 5, 1, 6, 2, 7, 3, 8};
    int output[10] = {0};
    ArraySolution::GetLeastNumbersMethod_1(data, sizeof(data) / sizeof(data[0]), output, 4);

    std::vector<int> vec(data, data + sizeof(data) / sizeof(data[0]));
    GetLeastNumbersMethod_2(vec, 6);
}

int ArraySolution::minOfReverseArray(const int *data, int length) {
    if (data == nullptr || length <= 0) {
        throw std::exception();
    }

    int index_1 = 0;
    int index_2 = length - 1;
    int mid = index_1;

    while (data[index_1] > data[index_2]) {
        if (index_2 - index_1 == 1) {
            mid = index_2;
            break;
        }

        mid = (index_1 + index_2) / 2;

        if (data[index_1] == data[mid] && data[mid] == data[index_2]) {
            return minInArray(data, length);
        }

        if (data[mid] >= data[index_1]) {
            index_1 = mid;
        } else {
            index_2 = mid;
        }
    }
    return data[mid];
}

int ArraySolution::minInArray(const int *data, int length)
{
    int minValue = *data;
    for (int iter = 1; iter < length; ++iter) {
        if (data[iter] < minValue) {
            minValue = data[iter];
        }
    }
    return minValue;
}

void ArraySolution::print1ToMaxNNumbers(const int n)
{
    auto numbers = new char[n];
    memset(numbers, '0', n);
    numbers[n] = '\0';

    while(!Increment(numbers, n)) {
        printNumber(numbers, n);
    }
    delete []numbers;
//    std::cout << numbers << std::endl;
//    printNumber(numbers, n);
}

bool ArraySolution::Increment(char *numbers, const int length)
{
    int takeOver = 0;
    bool isOverflow = false;

    for (int i = length - 1; i >= 0; --i) {
        int sum = numbers[i] - '0' + takeOver;
        if (i == length - 1) {
            ++ sum;
        }
        if (sum >= 10) {
            if (i == 0) {
                isOverflow = true;
            }
            takeOver = 1;
            sum -= 10;
            numbers[i] =  char(sum)+ '0';
        }
        else {
            numbers[i] = char(sum)  + '0';
            break;
        }
    }
    return isOverflow;
}

void ArraySolution::printNumber(char *numbers, const int length)
{
    int index = 0;
    while (index < length && numbers[index] == '0') {
        ++index;
    }

    while (index < length) {
        std::cout << numbers[index++];
    }
    std::cout << " ";
}

void ArraySolution::unitTestMaxN()
{
    print1ToMaxNNumbers(3);
//    print1ToMaxNNumbers(10);
//    print1ToMaxNNumbers(100);
}

int ArraySolution::moreThanHalfNumber(int *data, int length) {
    if (data == nullptr || length < 0) {
        throw std::exception();
    }

    int middle = length >> 1;
    int start = 0;
    int end = length - 1;
    int index = SortSolution::partition(data, 0, end);

    while (index != middle) {
        if (index < middle) {
            start = index + 1;
        }
        else {
            end = index - 1;
        }
        index = SortSolution::partition(data, start, end);
    }

    return data[middle];
}

int ArraySolution::moreThanHalfNumberMethod_2(const int *data, int length) {
    if (data == nullptr || length < 0) {
        throw std::exception();
    }

    int result = *data;
    int times = 1;
    for (int index = 1; index < length; ++index) {
        if (times == 0) {
            result = *(data + index);
            //continue;
        }
        result == data[index] ? ++times : --times;
    }
    return result;
}

void ArraySolution::unitTestMoreThanHalfNumber()
{
    int data[] = {1, 1, 1, 1, 2, 3, 4, 6, 1, 1, 1, 1};
    std::cout << moreThanHalfNumber(data, sizeof(data) / sizeof(data[0])) << std::endl;
    std::cout << moreThanHalfNumberMethod_2(data, sizeof(data) / sizeof(data[0])) << std::endl;
}
