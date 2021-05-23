#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <string.h>
#include <fstream>
#include <sstream>
#include "BigInt_core.h"
#include "BigInt.h"
#include "BigInt_process.h"

using namespace std;

int main() {

    // BigInt A("10000001101100100101001001001101", 2);
    // BigInt B("11001111111000110111111100100011", 2);
    // BigInt C = A ^ B;
    // cout << C.getBin();
    /*BigInt D(s, 10);
    
	cout << C.getDec() << endl;
    cout << D.getDec() << endl;
	*/

    // BigInt A("-3365585698", 10);
    // BigInt B = ~A;
    // cout << A.getBin() << endl;
    // cout << B.getBin() << endl;
    // cout << endl;


    ifstream fin("TestInput.txt");
    ofstream fout("TestOutput.txt");

    string line = "";
    string parameter[5];

    //int debug = 1;

    while(getline(fin, line)) {
        for(int i = 0; i < 5; i++)
            parameter[i] = "";
        int count = 0;
        stringstream s(line);
        while(s >> parameter[count++]);
        if(parameter[count - 1].length() == 0) count--;
        bigIntProcess(parameter, count, fout);

        //cout << debug++ << endl;
    }

    fin.close();
    fout.close();

    // FILE* fi = fopen("TestInput.txt", "r");
    // FILE* fo = fopen("TestOutput.txt", "w");

	// if (!fi || !fo) {
	// 	cout << "Can't create file";
	// 	return 1;
	// }
    
    // char* str = (char*)calloc(10001, sizeof(char));
    // if (!str) {
    //     printf("Error. Not enough memory.\n");
    // }
    // else {
    //     char delim[] = " ";
    //     char* token;
    //     char* parameter[5];
    //     while (fgets(str, 10000, fi)) {
    //         token = strtok(str, delim);
    //         int n = 0;
    //         while (token) {
    //             parameter[n] = token;
    //             n++;
    //             token = strtok(NULL, delim);
    //         }            
    //         cout << n << endl;
    //         if(!strcmp(parameter[n - 1],"\n")) n--;
    //         bigIntProcess(parameter, n, fo);
    //         fprintf(fo, "\n");
    //     }
    // }



    // fclose(fi);
    // fclose(fo);
    return 0;
}