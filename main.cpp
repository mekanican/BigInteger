#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <string.h>
#include <fstream>
#include <iomanip>
#include <ctime>
#include <sstream>
#include "BigInt_core.h"
#include "BigInt.h"
#include "BigInt_process.h"

using namespace std;


int main(int argc, char* argv[]) {

	if (argc != 3) {
		cout << "Wrong argument, take 2 argument as file name!" << endl;
		return 1;
	}
	double start = clock();

	cout << "Program started!" << endl << endl;

    ifstream fin(argv[1]);
    ofstream fout(argv[2]);

    string line = "";
    string parameter[5];
    
	int counter = 1;


	double sfunction = 0;

    while(getline(fin, line)) {
        for(int i = 0; i < 5; i++)
            parameter[i] = "";
        int count = 0;
        stringstream s(line);
        while(s >> parameter[count++]);
        if(parameter[count - 1].length() == 0) count--;
		sfunction = clock();
        bigIntProcess(parameter, count, fout);
		cout << fixed << setprecision(4) << "Line " << counter++ << " takes " << ((double)clock() - sfunction) / CLOCKS_PER_SEC << " seconds" << endl;
    }
    
	cout << endl << endl << fixed << setprecision(4) << "Program takes totally " << ((double)clock() - start) / CLOCKS_PER_SEC << " seconds" << endl;

    fin.close();
    fout.close();
    return 0;
}