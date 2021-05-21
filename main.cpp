#include <iostream>
#include <string>
#include "BigInt_core.h"
#include "BigInt.h"
using namespace std;

int main() {

    BigInt A("12333324764300000000000", 10);
    BigInt B("12324231200000000000000", 10);
    BigInt C = A & B;
    
	cout << C.getDec() << endl;
	
    return 0;
}