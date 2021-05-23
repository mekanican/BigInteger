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
	// string para[5];
	// for (int i = 0; i < 5; i++)
	// 	para[i] = "";
	// for (int i = 0; i < n; i++) {
	// 	para[i] = string(parameter[i]);
	// }
	// /*if (para[n - 1][para[n - 1].length() - 1] == '\n') {
	// 	para[n] = para[n - 1];
	// 	para[n - 1] = "";
	// }*/
	// for (int i = 0; i < int(para[n].length()) - 1; i++) {
	// 	para[n - 1] += para[n][i];
	// }
	// para[4] = para[3];
	// para[3] = "";

	// for (int i = 0; i < int(para[4].length()) - 1; i++) { // Careful
	// 	para[3] += para[4][i];
	// }

	if (n == 3) {
		if (parameter[1] == "~") {
			BigInt res;
			if (parameter[0] == "2") {
				BigInt operand(parameter[2], 2);
				res = ~operand;
				//printf("%s", res.getBin());
				fout << res.getBin() << endl;
				//fprintf(fo, "%s\n", res.getBin().c_str());
			}
			else {
				BigInt operand(parameter[2], 10);
				res = ~operand;
				//printf("%s", res.getDec());
				fout << res.getDec() << endl;
				//fprintf(fo, "%s\n", res.getDec().c_str());
			}
		}
		else if (parameter[0] == "2" && parameter[1] == "10") {
			
			BigInt operand(parameter[2], 2);
			//printf("%s", operand.getDec());
			fout << operand.getDec() << endl;
			//fprintf(fo, "%s\n", operand.getDec().c_str());
		}
		else {
			BigInt operand(parameter[2], 10);
			//printf("%s", operand.getBin());
			fout << operand.getBin() << endl;
			//fprintf(fo, "%s\n", operand.getBin().c_str());
		}
	}
	else {
		BigInt res;
		if (parameter[0] == "2") {
			BigInt lhs(parameter[1], 2);
			BigInt rhs(parameter[3], 2);

			res = whenNIsFour(parameter, lhs, rhs);
			fout << res.getBin() << endl;
			// string s = res.getBin();
			// fprintf(fo, "%s\n", res.getBin().c_str());
		}
		else {
			BigInt lhs(parameter[1], 10);
			BigInt rhs(parameter[3], 10);
			//cout << para[1] << " " << para[3] << endl;

			res = whenNIsFour(parameter, lhs, rhs);
			fout << res.getDec() << endl;
			//fprintf(fo, "%s", res.getDec().c_str());
		}
	}
}