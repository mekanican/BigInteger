#pragma once

#include <string>
using std::string;

struct BigInt {
    BigInt(); // Null BigInt
    BigInt(string, int); // Convert a base nth into BigInt
    BigInt(long long); // Convert integer into BigInt

	string getDec();
	string getBin();

    int length;
    bool sign;
    unsigned long long small; // If value is small < 2^63 - 1
    string big; // If value is big (otherwise)
};