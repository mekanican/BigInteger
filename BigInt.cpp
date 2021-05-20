#include <algorithm>

#include "BigInt.h"
#include "BigInt_core.h"

using namespace std;


BigInt operator+(BigInt& lhs, BigInt& rhs) {
	if(lhs.base == rhs.base && rhs.base == 10) {
		if(lhs.sign && rhs.sign) { // Neg + Neg = Neg

		}
		if(lhs.sign && !rhs.sign) { // Neg + Pos = -Pos + Pos

		}
		if(!lhs.sign && rhs.sign) { // Pos + Neg = Pos - Pos
			
		}
		if(!lhs.sign && !rhs.sign) { // Pos + Pos = Pos
			
		}
	}
}
BigInt operator-(BigInt& lhs, BigInt& rhs) {
	if(lhs.base == rhs.base && rhs.base == 10) {
		if(lhs.sign && rhs.sign) { // Neg - Neg 
		
		}
		if(lhs.sign && !rhs.sign) { // Neg - Pos 

		}
		if(!lhs.sign && rhs.sign) { // Pos - Neg 
			
		}
		if(!lhs.sign && !rhs.sign) { // Pos - Pos  
			
		}
	}
}


string addDecimal(string A, string B) 
{

	if (A.length() < B.length()) // Make sure A.length > B.length
		return addDecimal(B, A);

	string res = "";

	int tempRes = 0;
	int carry = 0;

	// while (B.length() < A.length())
	// 	B.push_back('0');
	for (unsigned int i = 0; i < B.length(); i++) {
		tempRes = A[i] - '0' + B[i] - '0' + carry;
		res.push_back(tempRes % 10 + '0');
		carry = tempRes / 10;
	}

    for(unsigned int i = B.length(); i < A.length(); i++) {
        tempRes = A[i] - '0' + carry;
        res.push_back(tempRes % 10 + '0');
		carry = tempRes / 10;
    }

	if (carry) res.push_back(carry + '0');
	return res;
}

string subDecimal(string A, string B) 
{

    while(A.length() < B.length())	
		A += "0";
	while(B.length() < A.length())	
		B += "0";
	reverse(A.begin(), A.end());
	reverse(B.begin(), B.end());

	bool neg = false;

	if(A < B) {
		neg = true;
		swap(A, B);
	}

	string res = "";
	int tempRes = 0;
	int carry = 0;

	for(int i = A.length() - 1; i >= 0; i--) {
		tempRes = A[i] - '0' - (B[i] - '0') - carry;
		if(tempRes < 0) {
			res += char(tempRes + 10 + '0');
			carry = 1;
		} else {
			res += char(tempRes + '0');
			carry = 0;
		}
	}
	if(neg) res += "-";
	return res;
}

string mulDecimal(string A, string B)
{
	if (A.length() < B.length())
		return mulDecimal(B, A);

	string temp = "";
	std::string res = "";

	int tempRes = 0;
	int carry = 0;

	for (unsigned int i = 0; i < B.length(); i++) {
		for (unsigned int j = 0; j < i; j++) {
			temp.push_back('0');
		}
		for (unsigned int j = i; j < A.length() + i; j++) {
			tempRes = (A[j - i] - '0') * (B[i] - '0') + carry;
			temp.push_back(tempRes % 10 + '0');
			carry = tempRes / 10;
		}
		if (carry) temp.push_back(carry + '0');
		res = addDecimal(res, temp);
		temp.erase();
		carry = 0;
	}

	return res;
}

string pow(string s, int n)
{
	if (n == 0) {
		return "1";
	} 
	if (n == 1) {
		return s;
	}
    string res = "1";
    while(n > 0) {
        if(n & 1) {
            res = mulDecimal(s, res);
        }
        s = mulDecimal(s, s);
        n >>= 1;
    }

	return res;
}
