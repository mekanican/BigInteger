#include <iostream>
#include <string>
#include "BigInt_core.h"
#include "BigInt.h"
using namespace std;

int main() {

    BigInt A("123333247643", 10);
    BigInt B("123242312", 10);
    BigInt C = A % B;
    
	cout << C.getDec() << endl;
	
    return 0;
}