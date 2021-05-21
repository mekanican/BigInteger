#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include "BigInt_core.h"
#include "BigInt.h"
#include "BigInt_process.h"

using namespace std;

int main() {

   /*BigInt A("12333324760030000000000", 10);
    BigInt B("123242312", 10);
    BigInt C = A / B;
    string s = "1293872797257295875230925372";
    BigInt D(s, 10);
    
	cout << C.getDec() << endl;
    cout << D.getDec() << endl;
	*/

    FILE* fi = fopen("TestInput.txt", "r");
    FILE* fo = fopen("TestOutput.txt", "w");

    
    char* str = (char*)calloc(10001, sizeof(char));
    if (!str) {
        printf("Error. Not enough memory.\n");
    }
    else {
        char delim[] = " ";
        char* token;
        while (fgets(str, 10000, fi)) {
            char* parameter[5];
            token = strtok(str, delim);
            int n = 0;
            while (token) {
                parameter[n] = token;
                n++;
                token = strtok(NULL, delim);
            }
            bigIntProcess(parameter, n, fo);
            fprintf(fo, "\n");
        }
    }



    fclose(fi);
    fclose(fo);
    return 0;
}