#include <cmath>
#include <iostream>

#include "BigInt_core.h"

BigInt::BigInt()
{
    length = 0;
    sign = false;
    small = 0;
    big = "";
}

BigInt::BigInt(string input, int base)
{
    length = 0;
    small = 0;
    big = "";
    sign = false;

    if(base == 10) {
        int n = input.length();
        if(input[0] == '-')
            sign = true;
        for(int i = n-1; i >= sign; i--)
            big += input[i];
        length = n - sign;

        if(length < 19) small = stoi(big);

    } else if(base == 2) {

    } else {
        std::cerr << "Wrong base!" << std::endl;
    }
}