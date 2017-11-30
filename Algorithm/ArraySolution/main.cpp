
#include <vector>
#include <set>
#include <iostream>
#include "ArraySolution.h"

void testMultiSet(std::vector<int> data)
{
    std::multiset<int, std::greater<int> > maxHeap;
    for(auto x: data) {
        maxHeap.insert(x);
    }

    for (auto iter = maxHeap.begin(); iter != maxHeap.end(); ++iter) {
        std::cout << *iter << " ";
    }
    std::cout << std::endl;
}

//extern void unit_test_max_sub_sequence_sum();
extern void unitTestMaxSum();

int main()
{
//    int data[] = {1, 1, 1, 1, 2, 3, 4, 6, 1, 1, 1, 1};
//    int data[] = {1, 2, 3, 4, 5, 6};
//    std::vector<int> vec(data, data + sizeof(data)/sizeof(data[0]));
//    testMultiSet(vec);
//    ArraySolution::GetLeastNumbersMethod_2(vec, 4);
//    unit_test_max_sub_sequence_sum();
    unitTestMaxSum();
}
