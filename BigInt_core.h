#pragma once

#include <string>
using std::string;

struct BigInt {
    BigInt(); // Null BigInt
    BigInt(string, int); // Convert a base nth into BigInt


    int length;
    bool sign;
    long long small; // If value is small < 2^63 - 1
    string big; // If value is big (otherwise)
};