#include <iostream>
#include "PolyDictionary.h"
using namespace std;

int main()
{
	ifstream fin("file/data.txt");
	PolyDictionary d;
	cout << d << endl;
	fin >> d;
	cout << d << endl;
	ofstream fout("file/data.txt",ofstream::app);
	cin >> d;
	fout << d;
	return 0;
}