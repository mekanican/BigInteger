#pragma once
#include "BigInt_core.h"

BigInt operator+(BigInt, BigInt);
BigInt operator-(BigInt, BigInt);
BigInt operator*(BigInt, BigInt);
BigInt operator/(BigInt, BigInt);
BigInt operator%(BigInt, BigInt);

bool operator==(BigInt, BigInt);
bool operator<(BigInt, BigInt);
bool operator>(BigInt, BigInt);

BigInt operator>>(BigInt, long long);
BigInt operator<<(BigInt, long long);

BigInt operator&(BigInt, BigInt);
BigInt operator|(BigInt, BigInt);
BigInt operator^(BigInt, BigInt);
BigInt operator~(BigInt);

string binaryToDecimal(string);
string decimalToBinary(long long);
string decimalToBinary(string);

BigInt pow(BigInt, long long);

string removeLeadingZeros(string);