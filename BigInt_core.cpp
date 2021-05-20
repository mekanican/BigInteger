#include <cmath>
#include <iostream>

#include "BigInt_core.h"
#include "BigInt.h"

string removeLeadingZeros(string s) {
    bool isNeg = (s[0] == '-');
	unsigned int i = isNeg;
	while (i < s.length() && s[i] == '0') i++;
	if (i == s.length()) return "0"; // Full 0
    if(isNeg)
        return "-" + s.substr(i, std::string::npos);
	return s.substr(i, std::string::npos);
}

BigInt::BigInt()
{
    length = 0;
    small = 0;
    big = "";
    base = 10;
    sign = false;
}

BigInt::BigInt(string input, int _base)
{
    big = "";
    sign = false;
    length = 0;
    small = 0;
    base = 10;

    input = removeLeadingZeros(input); // Remove unnecessary zeros

    if(_base == 10) {

        base = 10;
        int n = input.length();
        if(input[0] == '-')
            sign = true;
        for(int i = n-1; i >= sign; i--)
            big += input[i];
        length = n - sign;
        if(length < 19) small = stoi(big);

    } else if(_base == 2) {

        base = 2;
        int n = input.length();    
        for(int i = n - 1; i >= 0; i--) {
            big += input[i];
        }
        length = n;
        if(length >= 128 && length % 8 == 0)
            sign = true;
        if(length < 63) {

            unsigned long long temp = 1;
            for(int i = 0; i < length; i++) {
                small += (big[i] - '0') * temp;
                temp *= 2;
            }
        }

    } else {
        std::cerr << "Wrong base!" << std::endl;
    }
}