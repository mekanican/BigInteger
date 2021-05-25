#include "BigInt_process.h"
#include "BigInt.h"
#include "BigInt_core.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

BigInt whenNIsFour(string parameter[], BigInt lhs, BigInt rhs) {
	BigInt res;

	string toCmp = parameter[2];
	if (toCmp == "+") {
		res = lhs + rhs;
	}
	else if (toCmp == "-") {
		res = lhs - rhs;
	}
	else if (toCmp == "*") {
		res = lhs * rhs;
	}
	else if (toCmp == "/") {
		res = lhs / rhs;
	}
	else if (toCmp == "%") {
		res = lhs % rhs;
	}
	else if (toCmp == "&") {
		res = lhs & rhs;
	}
	else if (toCmp == "|") {
		res = lhs | rhs;
	}
	else if (toCmp == "^") {
		res = lhs ^ rhs;
	}
	else {
		long long toShift = stoll(parameter[3]);
		if (toCmp == ">>") {
			res = lhs >> toShift;
		}
		else {
			res = lhs << toShift;
		}
	}
	return res;
}

void bigIntProcess(string parameter[], int n, ofstream& fout) {
	if (n == 3) {
		if (parameter[1] == "~") {
			BigInt res;
			if (parameter[0] == "2") {
				BigInt operand(parameter[2], 2);
				res = ~operand;
				fout << res.getBin() << endl;
			}
			else {
				BigInt operand(parameter[2], 10);
				res = ~operand;
				fout << res.getDec() << endl;
			}
		}
		else if (parameter[0] == "2" && parameter[1] == "10") {
			BigInt operand(parameter[2], 2);
			fout << operand.getDec() << endl;
		}
		else {
			BigInt operand(parameter[2], 10);
			fout << operand.getBin() << endl;
		}
	}
	else {
		BigInt res;
		if (parameter[0] == "2") {
			BigInt lhs(parameter[1], 2);
			BigInt rhs(parameter[3], 2);
			res = whenNIsFour(parameter, lhs, rhs);
			fout << res.getBin() << endl;
		}
		else {
			BigInt lhs(parameter[1], 10);
			BigInt rhs(parameter[3], 10);

			res = whenNIsFour(parameter, lhs, rhs);
			fout << res.getDec() << endl;
		}
	}
}