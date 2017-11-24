//
// Created by root on 11/22/17.
//

#include <iostream>

void PrintSequence(int start, int end) {
    for (int x = start; x <= end; ++x) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
}

void FindContinuesSequence(int sum) {
    if (sum <= 2) {
        return;
    }
    int small = 1, big = 2;
    int current_sum = small + big;

    int middle = (1 + sum) / 2;

    while (big <= middle) {
        if (current_sum == sum) {
            PrintSequence(small, big);
        }

        while (current_sum > sum && small <= big) {
            current_sum -= small;
            ++small;
            if (current_sum == sum) {
                PrintSequence(small, big);
            }
        }
        ++big;
        current_sum += big;
    }
}

void unitTestFindContinuesSequence() {
    FindContinuesSequence(15);
}
