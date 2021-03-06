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

BigInt abs(BigInt);

BigInt pow(BigInt, long long);

int digits(BigInt&);

BigInt min(BigInt, BigInt);
BigInt max(BigInt A, BigInt B);

string to_string(BigInt& A);
string to_base32(BigInt A);
string to_base58(BigInt A);
string to_base64(BigInt A);
bool is_prime(BigInt A, int iteration);

string removeLeadingZeros(string&);