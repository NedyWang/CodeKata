//
// Created by root on 12/22/17.
//

#include <exception>
#include <iostream>

int moreThanHalfNumber(const int *data, int length) {
    if (data == nullptr || length < 0) {
        throw std::exception();
    }

    int result = *data;
    int times = 1;
    for (int index = 1; index < length; ++index) {
        if (times == 0) {
            result = *(data + index);
            times = 1;
        } else {
            result == data[index] ? ++times : --times;
        }
    }
    return result;
}



int func(const int *data, int len)
{
    int nStart = data[len - 1];
    int aStart = data[len - 1];
    for (int i = len - 2; i >= 0; --i) {
        nStart = std::max(data[i], data[i] + nStart);
        aStart = std::max(aStart, nStart);
    }
    return aStart;
}

int main()
{
    int data[] = {0, 1, 2, -10, 3, 3, 3,3};
    std::cout << moreThanHalfNumber(data, sizeof(data) / sizeof(data[0])) << std::endl;

    std::cout << func(data, 7) << std:: endl;
}
