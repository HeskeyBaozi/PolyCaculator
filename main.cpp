#include <iostream>
#include "PolyDictionary.h"
using namespace std;

int main()
{
	ifstream fin("file/out.txt");
	//ofstream fout("file/out.txt");
	PolyDictionary d;
	cout << "空字典:\n" << d << endl;
	fin >> d;
	cout << "读入文件后字典:\n" << d << endl;
	cout << d["a"](3) << endl;
	cout << d["a"] + d["b"] << endl;
	//cin >> d;
	//cout << "输入后的字典:\n" << d << endl;
	//fout << d << endl;
	return 0;
}