//
// Created by root on 11/29/17.
//

/*
 * Given a 32-bit signed integer, reverse digits of an integer.
 * */

int reverse(int x) {
    int ret = 0;
    while (x){
        if ((ret*10 + x%10 - x%10)/10 != ret)
            return 0;
        ret = ret * 10 + x % 10;
        x = x / 10;
    }
    return ret;
}
