#include <cmath>
#include <iostream>
#include <string>
#include <algorithm>

#include "BigInt_core.h"
#include "BigInt.h"
using namespace std;

string BigInt::getDec() {
	string temp = big;
	if (sign) temp += "-";
	reverse(temp.begin(), temp.end());
	return temp;
}

string BigInt::getBin()
{
	if (length < 19) {
        if(sign)
		    return decimalToBinary(-(long long)small);
        else
            return decimalToBinary(small);
	}
	string temp = big;
	reverse(temp.begin(), temp.end());
    if(sign) temp = "-" + temp;

	return decimalToBinary(temp);
}


BigInt::BigInt()
{
    length = 0;
    small = 0;
    big = "";
    sign = false;
}

BigInt::BigInt(string input, int _base)
{
    big = "";
    sign = false;
    length = 0;
    small = 0;

    input = removeLeadingZeros(input); // Remove unnecessary zeros


    if(_base == 10) {

        int n = input.length();
        if(input[0] == '-')
            sign = true;
        for(int i = n-1; i >= sign; i--)
            big += input[i];
        length = n - sign;

		string temp = big;
		reverse(temp.begin(), temp.end());
        if(length < 19) {
            small = stoll(temp);
        }

    } else if(_base == 2) {

        input = binaryToDecimal(input);
        int n = input.length();
        if(input[0] == '-')
            sign = true;
        for(int i = n-1; i >= sign; i--)
            big += input[i];
        length = n - sign;

		string temp = big;
		reverse(temp.begin(), temp.end());
        if(length < 19) small = stoll(temp);

    } else {
        std::cerr << "Wrong base!" << std::endl;
    }
}

BigInt::BigInt(long long data) 
{
    sign = data < 0;
    small = llabs(data);
    big = to_string(small);
	reverse(big.begin(), big.end());
    length = log10(small) + 1;
}