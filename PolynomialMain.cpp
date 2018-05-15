#include <iostream>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include "PolynomialClass.h"
#include <ctime>
int main()
{
	/*
srand(time(NULL));
int Test1array[4] = {0, 0, 0, 0};
int Test2array[5] = {0, 0, 0, 0, 0};
Polynomial Test1("list.txt");
Polynomial Test2(Test2array, 5);
Test2.print();
Test1.print();
//Test2.mul(Test1);
Test2.print();
Test1.print();
*/
	int polySize;
	ifstream fin("list.txt");
	if(!fin)
		cout << "NO FILE";
	fin >> polySize;
	cout << polySize;
	
}

		
	
