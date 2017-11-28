//
// Created by root on 11/21/17.
//


#include <iostream>

void Permutation(char *str, char *start);

void Permutation(char *str) {
    if (str == nullptr) {
        return;
    }

    return Permutation(str, str);
}

void Permutation(char *str, char *start) {
    if (*start == '\0') {
        std::cout << str << std::endl;
        return;
    } else {
        for (char *index = start; *index != '\0'; ++index) {
            std::swap(*index, *start);
            Permutation(str, start + 1);
            std::swap(*index, *start);
        }
    }
}

int main()
{
    char data[] = "abc";
    Permutation(data);
}

