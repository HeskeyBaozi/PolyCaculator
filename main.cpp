#include <iostream>
#include "PolyDictionary.h"
using namespace std;

int main()
{
	ifstream fin("file/out.txt");
	//ofstream fout("file/out.txt");
	PolyDictionary d;
	cout << "���ֵ�:\n" << d << endl;
	fin >> d;
	cout << "�����ļ����ֵ�:\n" << d << endl;
	cout << d["a"](3) << endl;
	cout << d["a"] + d["b"] << endl;
	//cin >> d;
	//cout << "�������ֵ�:\n" << d << endl;
	//fout << d << endl;
	return 0;
}