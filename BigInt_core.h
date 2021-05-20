#pragma once

#include <string>
using std::string;

struct BigInt {
    BigInt(); // Null BigInt
    BigInt(string, int); // Convert a base nth into BigInt


    int length;
    char base; // 10 for Decimal mode, 2 for Binary mode
    bool sign;
    unsigned long long small; // If value is small < 2^63 - 1
    string big; // If value is big (otherwise)
};