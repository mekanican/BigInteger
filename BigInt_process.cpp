#include "BigInt_process.h"
#include "BigInt.h"

BigInt whenNIsFour(char* parameter[], string para[], BigInt lhs, BigInt rhs) {
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
		long long toShift = 0;
		int len = (int)para[3].length();
		for (int i = len - 1; i >= 0; i--) {
			toShift = toShift * 10 + (para[3][i] - '0');
		}
		if (toCmp == ">>") {
			res = lhs >> toShift;
		}
		else {
			res = lhs << toShift;
		}
	}
	return res;
}

void bigIntProcess(char* parameter[], int n, FILE* fo) {
	string para[5];
	for (int i = 0; i < n; i++) {
		para[i] = string(parameter[i]);
	}
	if (para[n - 1][para[n - 1].length() - 1] == '\n') {
		para[n] = para[n - 1];
		para[n - 1] = "";
		for (int i = 0; i < para[n].length() - 1; i++) {
			para[n - 1] += para[n][i];
		}
	}
	
	if (n == 3) {
		if (para[1] == "~") {
			BigInt res;
			if (para[0] == "2") {
				BigInt operand(para[2], 2);
				res = ~operand;
				//printf("%s", res.getBin());
				fprintf(fo, "%s", res.getBin().c_str());
			}
			else {
				BigInt operand(para[2], 10);
				res = ~operand;
				//printf("%s", res.getDec());
				fprintf(fo, "%s", res.getDec().c_str());
			}
		}
		else if (para[0] == "2") {
			BigInt operand(para[2], 2);
			//printf("%s", operand.getDec());
			fprintf(fo, "%s", operand.getDec().c_str());
		}
		else {
			BigInt operand(para[2], 10);
			//printf("%s", operand.getBin());
			fprintf(fo, "%s", operand.getBin().c_str());
		}
	}
	else {
		BigInt res;
		if (para[0] == "2") {
			BigInt lhs(para[1], 2);
			BigInt rhs(para[3], 2);
			res = whenNIsFour(parameter, para, lhs, rhs);
			string s = res.getBin();
			//fprintf(fo, "%s", res.getBin().c_str());
		}
		else {
			BigInt lhs(para[1], 10);
			BigInt rhs(para[3], 10);
			res = whenNIsFour(parameter, para, lhs, rhs);
			//fprintf(fo, "%s", res.getDec().c_str());
		}
	}
}