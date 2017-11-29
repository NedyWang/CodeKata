//
// Created by root on 11/29/17.
//

#include <iostream>
#include <vector>
#include <string>

std::string zigzarg_convert(std::string s, int num_rows) {
    if (num_rows <= 1)
        return s;
    int step = 1;
    int cur_row = 0;
    std::string res_rows[num_rows];

    for (auto ch: s) {
        res_rows[cur_row].push_back(ch);
        if (cur_row == 0)
            step = 1;
        else if (cur_row == num_rows - 1)
            step = -1;
        cur_row += step;
    }
    std::string res;
    for (auto iter: res_rows)
        res += iter;
    return res;
}
