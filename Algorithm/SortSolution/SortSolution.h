//
// Created by root on 11/17/17.
//

#ifndef LEET_CODE_SORTSOLUTION_H
#define LEET_CODE_SORTSOLUTION_H


#include "../Common/Solution.h"
#include <cstdlib>
#include <ctime>

class SortSolution: public Solution {
public:
    static int partition(int data[], int start, int end);
    static void quick_sort(int data[], int start, int end);
    static void unitTestQuickSort();

    template <typename T>
    static void mergeSort(T data[], int length);
    static void unitTestMergeSort();
    void unitTest();


private:
    static int random_in_range(int start, int end)
    {
        srand(time(0));
        return rand()%(end - start + 1) + start;
    }

    template <typename T>
    static void doMergeSort(T data[], int start, int end);

    template <typename T>
    static void doMerge(T data[], int start, int mid, int end);
};




#endif //LEET_CODE_SORTSOLUTION_H
