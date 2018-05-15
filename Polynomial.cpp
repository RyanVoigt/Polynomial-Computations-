#include <iostream>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include "PolynomialClass.h"
#include <ctime>
#include <string>


using namespace std;
//Print Class
Polynomial::~Polynomial()
{
	delete [] data;
}
void Polynomial::print()
{
	cout << "Polynomial Coefficients:  ";
	for(int index = 0; index < size; index++)
	{
		cout << "\t" <<data[index];
	}
		cout << endl;
}
//Default Constructor
Polynomial::Polynomial()
{   
	size = rand() % 10 +1;
	data = new int[size];
	for(int index=0; index <= size -1; index++)
	{
		data[index] = rand() % 6 + 1;
	}
}
//Constructor
Polynomial::Polynomial(int A[], int max)
{
	//To avoid memory leak
	if(max < 0)
		max = -1*max;
	data = new int[max];
	for(int count = 0; count < max; count++)
	{
		data[count] = A[count];
	}
	size = max;
}
//File Constructor
Polynomial::Polynomial(string fileName)
{
	int polySize;
	ifstream fin(fileName.c_str() );
	if(!fin)
		cout << "NO FILE";
	fin >> polySize;
//	data = new int[polySize];
//	for (int count=0; count < polySize; count++)
//	{
//		fin >> data[count];
//	}	
}
//Adding Polynomials
void Polynomial::add(const Polynomial& second)
{
	int tempSize = 0;
	
//	bigSize = (second.size>size)?second.size:size;
	if(second.size < size)
		tempSize = size;
	else
		tempSize = second.size;
	
	int tempArray[tempSize] = {0};

	for(int count = 0; count < size; count++)
		tempArray[count] = data[count];
	
	for(int count = 0; count < second.size; count++)
	{
		tempArray[count] += second.data[count];
	}
	
	data = new int[tempSize];
	for(int count = 0; count < tempSize; count++)
	{
		data[count] = tempArray[count];
	}

	size = tempSize;
}
//Subtracting Polynomials
void Polynomial::sub(const Polynomial& second)
{
	int bigSize = 0;
	if(second.size < size)
		bigSize = size;
	else
		bigSize = second.size;
		
	int tempArray[bigSize] = {};
	
	for(int count = 0; count < size; count++)
		tempArray[count] = data[count];
	
	for(int count = 0; count < second.size; count++)
		tempArray[count] -= second.data[count];
		
	delete [] data;
	data = new int[bigSize];
	
	for(int count = 0; count < bigSize; count++)
	{
		cout << count;
		data[count] = tempArray[count];
	}
	size = bigSize;
}
//Multiplying Polynomials
void Polynomial::mul(const Polynomial& second)
{
	int bigSize = size + second.size - 1;
	int spot = 0;
	int tempArray[bigSize] = {0};
	int max1, max2;
	if(second.size < size)
	{
		max1 = size;
		max2 = second.size;
	}
	else
	{
		max1 = second.size;
		max2 = size;
	}
	
	for(int count1 = 0; count1 < max1; count1++)
	{
			for(int count2 = 0; count2 < max2; count2++)
			{
				spot = count1 + count2;
				if(second.size < size)
					tempArray[spot] += data[count1] * second.data[count2];
				else
					tempArray[spot] += second.data[count1] * data[count2];
			}
	}
	
	data = new int[bigSize];
	for(int count = 0; count < bigSize; count++)
		data[count] = tempArray[count];
	size = bigSize;
}
		
