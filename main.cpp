#include <iostream>
#include "Polynomial.h"
using namespace std;

int main()
{
	Polynomial b;
	ifstream fin("file/fuck.txt");	
	cout << b << endl;
	fin >> b;
	cout << b;
	return 0;
}