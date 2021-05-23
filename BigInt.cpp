#include <algorithm>
#include <stdexcept>
#include <iostream>
#include <cmath>

#include "BigInt.h"
#include "BigInt_core.h"

using namespace std;




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

string binaryToDecimal(string source) {
	bool sign = (source.length() >= 128) && (source.length() % 8 == 0);

	int n = source.length();
	if(sign)
	{
		for(int i = 0; i < n; i++)
			source[i] = (source[i] == '1') ? '0' : '1';
		int temp = 0;
		int carry = (source[n - 1] - '0' + 1) / 2;
		source[n - 1] = char(((source[n - 1] - '0' + 1) % 2) + '0');
		for(int i = n-2; i >= 0; i--) {
			temp = source[i] - '0' + carry;
			source[i] = char((temp % 2) + '0');
			carry = temp / 2;
		}
	}
	string res = "0";
	for(int i = n - 1; i >= 0; i--) {
		if(source[i] == '1') {
			res = addDecimal(res, pow("2", n - i - 1));
		}
	}

	if(sign) res += "-";

	reverse(res.begin(), res.end());

	return res;
}

string decimalToBinary(long long n)
{
	long long m = llabs(n);
	string temp = "";
	while (m > 0) {
		temp += char((m & 1) + '0');
		m >>= 1;
	}
	if(n >= 0) {
		reverse(temp.begin(), temp.end());
		return temp;
	} else { // 2 complement
		while(temp.length() < 128)
			temp += "0";
		while(temp.length() % 8 != 0)
			temp += "0";
		// Flip
		int x = temp.length();
		for(int i = 0; i < x; i++)
			temp[i] = (temp[i] == '1') ? '0' : '1';
		int carry = (temp[0] - '0' + 1) / 2;
		temp[0] = char(((temp[0] - '0' + 1) % 2) + '0');
		int t = 0;
		for(int i = 1; i < x; i++)
		{
			t = temp[i] - '0' + carry;
			carry = t / 2;
			temp[i] = char((t % 2) + '0');
		}
		reverse(temp.begin(), temp.end());
		return temp;
	}
}

string removeLeadingZeros(string s) {
	bool isNeg = (s[0] == '-');
	unsigned int i = isNeg;
	while (i < s.length() && s[i] == '0') i++;
	if (i == s.length()) return "0"; // Full 0
	if (isNeg)
		return "-" + s.substr(i, std::string::npos);
	return s.substr(i, std::string::npos);
}

string decimalToBinary(string n)
{
	bool sign = false;
	if(n[0] == '-') {
		sign = true;
		n = n.substr(1, string::npos);
	}
	string res = "";
	while (n.length() > 0 && n != "0")
	{
		string temp = "";
		string quotient = "";
		res += char(((n.back() - '0') & 1) + '0');
		int i = 0;
		while (i < n.length()) {
			temp += n[i];
			if (stoi(temp) >= 2) {
				int t = stoi(temp) / 2;
				quotient += char(t + '0');
				temp = to_string(stoi(temp) - t * 2);
				if (temp == "0") temp = "";
			} else {
				quotient += "0";
			}
			i++;
		}
		n = quotient;
		n = removeLeadingZeros(n);
	}
	if(!sign) {
		reverse(res.begin(), res.end());
		return res;
	} else {
		while(res.length() < 128)
			res += "0";
		while(res.length() % 8 != 0)
			res += "0";
		// Flip
		int x = res.length();
		for(int i = 0; i < x; i++)
			res[i] = (res[i] == '1') ? '0' : '1';
		int carry = (res[0] - '0' + 1) / 2;
		res[0] = char(((res[0] - '0' + 1) % 2) + '0');
		int t = 0;
		for(int i = 1; i < x; i++)
		{
			t = res[i] - '0' + carry;
			carry = t / 2;
			res[i] = char((t % 2) + '0');
		}
		reverse(res.begin(), res.end());
		return res;
	}
}

BigInt pow(BigInt A, long long n)
{
	if (A.big == "0" || n == 0) return A;
	BigInt res(1);
	while (n > 0) {
		if (n & 1) {
			res = res * A;
		}
		A = A * A;
		n >>= 1;
	}
	return res;
}

BigInt operator+(BigInt lhs, BigInt rhs) {
	BigInt temp;
	string temps = "";
	if(max(lhs.length, rhs.length) < 19) { // Optimize small number 
		return BigInt(lhs.small + rhs.small);
	} 
	if(lhs.sign && rhs.sign) { // Neg + Neg = Neg
		temp = lhs;
		BigInt temp2 = rhs;
		temp.sign = false;
		temp2.sign = false;
		temp = temp + temp2;
		temp.sign = true;
		return temp;
	}
	if(lhs.sign && !rhs.sign) { // Neg + Pos = -Pos + Pos
		temp = lhs;
		temp.sign = false;
		return rhs - temp;
	}
	if(!lhs.sign && rhs.sign) { // Pos + Neg = Pos - Pos
		temp = rhs;
		temp.sign = false;
		return lhs - temp;
	}
	if(!lhs.sign && !rhs.sign) { // Pos + Pos = Pos
		temps = addDecimal(lhs.big, rhs.big);
		reverse(temps.begin(), temps.end());
		return BigInt(temps, 10);
	}
	return temp;
}
BigInt operator-(BigInt lhs, BigInt rhs) {
	BigInt temp;
	string temps = "";

	
	if(max(lhs.length, rhs.length) < 19){ // Optimize small number 
		return BigInt(lhs.small - rhs.small);
	} 
	
	if(lhs.sign && rhs.sign) { // Neg - Neg <=> Neg + Pos
		temp = rhs;
		temp.sign = false;
		return lhs + temp;
	}
	if(lhs.sign && !rhs.sign) { // Neg - Pos <=> Neg + Neg
		temp = rhs;
		temp.sign = true;
		return lhs + temp;
	}
	if(!lhs.sign && rhs.sign) { // Pos - Neg <=> Pos + Pos
		temp = rhs;
		temp.sign = false;
		return lhs + temp;
	}
	if(!lhs.sign && !rhs.sign) { // Pos - Pos
		temps = subDecimal(lhs.big, rhs.big);
		reverse(temps.begin(), temps.end());
		return BigInt(temps, 10);
	}
	return temp;
}

void split_at(BigInt source, BigInt& high, BigInt& low, int num)
{
	string s = source.getDec();

	string h = "", l = "";

	int n = s.length();

	for (int i = 0; i < n - num; i++)
		h += s[i];
	for (int i = n - num; i < s.length(); i++)
		l += s[i];
	high = BigInt(h, 10);
	low = BigInt(l, 10);
}

void shiftLeft10(BigInt& source, int num) {
	if (num == 0 || source.big == "0")
		return;
	reverse(source.big.begin(), source.big.end());
	for (int i = 0; i < num; i++)
		source.big += "0";
	source.length = source.big.length();
	if (source.length < 19)
		source.small = stoll(source.big);
	reverse(source.big.begin(), source.big.end());
}

// https://en.wikipedia.org/wiki/Karatsuba_algorithm#Pseudocode
BigInt karatsuba(BigInt num1, BigInt num2) {

	BigInt res;

	if (num1.length < 2 || num2.length < 2) {
		string temp = mulDecimal(num1.big, num2.big);
		reverse(temp.begin(), temp.end());
		return BigInt(temp, 10);
	}

	int m = max(num1.length, num2.length);
	int m2 = floor(m / 2);
	BigInt high1, low1, high2, low2;
	split_at(num1, high1, low1, m2);
	split_at(num2, high2, low2, m2);
	BigInt z0, z1, z2;
	z0 = karatsuba(low1, low2);
	z1 = karatsuba(low1 + high1, low2 + high2);
	z2 = karatsuba(high1, high2);

	BigInt ztemp = z1 - z2;
	ztemp = ztemp - z0; // Equal ztemp = z1 - z2 - z0;
	shiftLeft10(z2, m2 * 2);
	shiftLeft10(ztemp, m2);

	ztemp = ztemp + z2;
	ztemp = ztemp + z0;
	return ztemp;
}

BigInt operator*(BigInt lhs, BigInt rhs)
{
	BigInt temp1;
	BigInt temp2;
	if (lhs.length + rhs.length < 19) { // Optimize small number 
		return BigInt(lhs.small * rhs.small);
	}
	
	if (lhs.sign && rhs.sign) { // Neg * Neg 
		temp1 = lhs;
		temp2 = rhs;
		temp1.sign = false;
		temp2.sign = false;
		return temp1 * temp2;
	}

	if (!lhs.sign && rhs.sign) { // Pos * Neg
		temp1 = rhs;
		temp1.sign = false;
		temp1 = lhs * temp1;
		temp1.sign = true;
		return temp1;
	}

	if (lhs.sign && !rhs.sign) { // Neg * Pos
		temp1 = lhs;
		temp1.sign = false;
		temp1 = temp1 * rhs;
		temp1.sign = true;
		return temp1;
	}

	if (!lhs.sign && !rhs.sign) { // Pos * Pos
		return karatsuba(lhs, rhs);
	}

	return BigInt();
}

void divide(BigInt A, BigInt B, BigInt &q, BigInt &r)
{
	string start = "";
	int i = 0;
	for(; i < B.length - 1; i++)
		start += A.big[A.length - i - 1];

	BigInt temp(start, 10);

	BigInt digit[10];
	for(int i = 0; i < 10; i++)
		digit[i] = BigInt(i);

	BigInt quotient(0);

	for(; i < A.length; i++) {
		shiftLeft10(temp, 1);
		temp = temp + digit[A.big[A.length - i - 1] - '0'];
		if(!(temp < B)) {
			int j = 9;
			for(; j >= 0; j--) {
				if(!(temp < (B * digit[j])))
					break;
			}
			shiftLeft10(quotient, 1);
			quotient = quotient + digit[j];
			temp = temp - B * digit[j];
		} else {
			shiftLeft10(quotient, 1);
			quotient = quotient + digit[0];
		}
	}
	q = quotient;
	r = temp;
}

BigInt operator/(BigInt A, BigInt B)
{
	if (B.big == "0") throw overflow_error("Divide by zero");

	if (A == B) {
		return BigInt(1);
	}
	if (A < B) {
		return BigInt(0);
	}
	if (A.length < 19 && B.length < 19)
		return BigInt(A.small / B.small);

	BigInt q, r;
	divide(A, B, q, r);
	
	if ((A.sign && !B.sign) || (!A.sign && B.sign))
		q.sign = true;

	return q;
}

BigInt operator%(BigInt A, BigInt B) {
	if (B.big == "0") throw overflow_error("Divide by zero");

	if (A == B) {
		return BigInt(0);
	}
	if (A < B) {
		return A;
	}
	if (A.length < 19 && B.length < 19)
		return BigInt(A.small % B.small);
	BigInt q, r;
	divide(A, B, q, r);
	if ((A.sign && !B.sign) || (!A.sign && B.sign))
		r.sign = true;
	return r;
}

bool operator==(BigInt A, BigInt B)
{
	return A.big == B.big;
}

bool operator<(BigInt A, BigInt B)
{
	BigInt temp = A - B;
	return temp.sign; // A - B < 0
}

bool operator>(BigInt A, BigInt B)
{
	return !(A < B) && !(A == B);
}

// Div 2 ^ n
BigInt operator>>(BigInt A, long long n)
{
	if(A.length < 19) { // Optimize for small number
		long long t = A.small;
		if(A.sign) t = -t;
		return BigInt(t >> n);
	}
	string bin = A.getBin();
	while (bin.length() > 0 && n > 0) {
		bin.pop_back();
		n--;
	}
	return BigInt(bin, 2);
}

// Mul 2 ^ n
BigInt operator<<(BigInt A, long long n)
{

	if(A.length + (n*log10(2)) + 1 < 19) // Optimize small number
	{
		long long t = A.small;
		if(A.sign) t = -t;
		return BigInt(t << n);
	}

	BigInt res = pow(BigInt(2), n);
	res = res * A;
	return res;
}

BigInt operator&(BigInt lhs, BigInt rhs)
{
	if(lhs.length < 19 && rhs.length < 19) {
		bool signA = lhs.sign;
		bool signB = rhs.sign;

		long long A = lhs.small;
		long long B = rhs.small;

		if(signA) A = -A;
		if(signB) B = -B;

		return BigInt(A & B);
	}
	string A = lhs.getBin();
	string B = rhs.getBin();
	reverse(A.begin(), A.end());
	reverse(B.begin(), B.end());

	string res = "";
	
	if(A.length() < B.length()) {
		for(int i = 0; i < A.length(); i++) {
			res += char(((A[i] - '0') & (B[i] - '0')) + '0');
		}
	} else {
		for(int i = 0; i < B.length(); i++) {
			res += char(((A[i] - '0') & (B[i] - '0')) + '0');
		}
	}
	reverse(res.begin(), res.end());
	return BigInt(res, 2);
}

BigInt operator|(BigInt lhs, BigInt rhs)
{
	if(lhs.length < 19 && rhs.length < 19) {
		bool signA = lhs.sign;
		bool signB = rhs.sign;

		long long A = lhs.small;
		long long B = rhs.small;

		if(signA) A = -A;
		if(signB) B = -B;

		return BigInt(A | B);
	}
	string A = lhs.getBin();
	string B = rhs.getBin();
	reverse(A.begin(), A.end());
	reverse(B.begin(), B.end());

	string res = "";
	
	if(A.length() < B.length()) {
		for(int i = 0; i < A.length(); i++) {
			res += char(((A[i] - '0') | (B[i] - '0')) + '0');
		}
		for(int i = A.length(); i < B.length(); i++) {
			res += B[i];
		}
	} else {
		for(int i = 0; i < B.length(); i++) {
			res += char(((A[i] - '0') | (B[i] - '0')) + '0');
		}
		for(int i = B.length(); i < A.length(); i++) {
			res += A[i];
		}
	}
	reverse(res.begin(), res.end());
	return BigInt(res, 2);
}

BigInt operator^(BigInt lhs, BigInt rhs)
{
	if(lhs.length < 19 && rhs.length < 19) {
		bool signA = lhs.sign;
		bool signB = rhs.sign;

		long long A = lhs.small;
		long long B = rhs.small;

		if(signA) A = -A;
		if(signB) B = -B;

		return BigInt(A ^ B);
	}
	string A = lhs.getBin();
	string B = rhs.getBin();
	reverse(A.begin(), A.end());
	reverse(B.begin(), B.end());

	string res = "";
	
	if(A.length() < B.length()) {
		for(int i = 0; i < A.length(); i++) {
			res += char(((A[i] - '0') ^ (B[i] - '0')) + '0');
		}
		for(int i = A.length(); i < B.length(); i++) {
			res += B[i];
		}
	} else {
		for(int i = 0; i < B.length(); i++) {
			res += char(((A[i] - '0') ^ (B[i] - '0')) + '0');
		}
		for(int i = B.length(); i < A.length(); i++) {
			res += A[i];
		}
	}
	cout << res << endl;
	reverse(res.begin(), res.end());
	return BigInt(res, 2);
}

BigInt operator~(BigInt A)
{
	if(A.length < 19) {
		BigInt t(~A.small);
		t.sign = !A.sign;
		return t;
	}

	string s = A.getBin();
	for(int i = 0; i < s.length(); i++)
		s[i] = (s[i] == '1') ? '0' : '1';
	return BigInt(s,2);
}
