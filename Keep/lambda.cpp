//
// Created by root on 12/19/17.
//


#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

void func(std::function<void()> func)
{
    func();
}

int main()
{
    std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int x = 5;
    vec.erase(std::remove_if(vec.begin(), vec.end(), [x](int n) { return x < n;}), vec.end());
    std::cout << "vec: ";
    std::for_each(vec.begin(), vec.end(), [](int i) {std::cout << i << " ";});
    std::cout << std::endl;

    func([x](){std::cout << "lambda..." << std::endl << "x = " << x << std::endl; });
    std::priority_queue<int> priorityQueue;
    priorityQueue.push(1);
    std::make_heap(vec.begin(), vec.end());
    return 0;
}
