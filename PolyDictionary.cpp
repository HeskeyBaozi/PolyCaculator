#include "PolyDictionary.h"
using namespace std;

/*
*   重载>>运算符: 通过文件读取到字典中
*           fin: 文件输入流
*    dictionary: 要读入的多项式字典
*        return: 整型int
*                表示成功读入进该字典的键值对个数
*/
int operator>>(ifstream& fin, PolyDictionary& dictionary)
{
	int successInputNumber = 0;
	/*
	* 遍历整个文件直到EOF
	*/
	while (!fin.eof())
	{
		string key;
		string polyString;
		fin >> key >> polyString;		
		Polynomial pTemp(polyString);
		/*  键值对:
		*     key: key
		*   value: pTemp
		*   形成有序对后追加到字典中
		*/
		dictionary.dictionary.emplace(key, pTemp);
		successInputNumber++;
	}
	return successInputNumber;
}

ostream& operator<<(ostream& out, PolyDictionary& poly)
{
	for (map<string, Polynomial>::iterator i = poly.dictionary.begin();
	i != poly.dictionary.end(); ++i)
	{
		out << i->first << "(x) =" << i->second << endl;
	}
	return out;
}

istream& operator>>(istream& in, PolyDictionary& poly)
{
	string identifier;
	string polyString;
	in >> identifier >> polyString;
	Polynomial pTemp(polyString);
	poly.dictionary.emplace(identifier, pTemp);
	return in;
}

ofstream& operator<<(ofstream& fout, PolyDictionary& poly)
{
	for (map<string, Polynomial>::iterator i = poly.dictionary.begin();
	i != poly.dictionary.end(); ++i)
	{
		fout << i->first << "\n";
		fout << i->second << "\n";
	}
	fout << endl;
	return fout;
}
