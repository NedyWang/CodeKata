//
// Created by root on 11/17/17.
//

#ifndef LEET_CODE_ARRAYSOLUTION_H
#define LEET_CODE_ARRAYSOLUTION_H


#include <vector>

class ArraySolution {
public:
    static int GetLeastNumbersMethod_1(int *data, int length, int *output, int k);
    static int GetLeastNumbersMethod_2(std::vector<int> &data, int number);

    static int minOfReverseArray(const int *data, int length);
    static int minInArray(const int *data, int length);

    static void print1ToMaxNNumbers(int n);
    static bool Increment(char *numbers, int length);
    static void printNumber(char *numbers, int length);


    static int moreThanHalfNumber(int *data, int length);
    static int moreThanHalfNumberMethod_2(const int *data, int length);

    static void unitTestMoreThanHalfNumber();
    static void unitTestGetLeastNumbersMethod_1();
    static void unitTestMaxN();
};



#endif //LEET_CODE_ARRAYSOLUTION_H
