
#include <string>
#ifndef POLYNOMIALCLASS_HPP
#define POLYNOMIALCLASS_HPP

using namespace std;

class Polynomial{
	int size;
	int *data = NULL;
public:
    Polynomial();
	~Polynomial();
	Polynomial(int A[], int size);
	Polynomial(string fileName);
	void add(const Polynomial& second);
	void sub(const Polynomial& second);
	void mul(const Polynomial& second);
	void print(); 
};
#endif
