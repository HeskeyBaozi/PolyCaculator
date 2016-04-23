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
		/*
		*        key: 键(关键字)
		* polyString: 用于生成多项式的字符串
		*/
		string key;
		string polyString;
		/*
		* 从':'之前读取到key
		* 同时清除key串中开头多余空白字符
		*/
		getline(fin, key, ':');
		if (key[0] == ' ' || key[0] == '\n')
		{
			key.replace(0, key.find_first_not_of(' '), "");
			key.replace(0, key.find_first_not_of('\n'), "");
		}
		getline(fin, polyString, ';');
		if (!key.empty() && !polyString.empty())
		{
			/*  键值对:
			*     key: key
			*   value: pTemp
			*/
			Polynomial pTemp(polyString);
			dictionary.getDictionary().emplace(key, pTemp);
			successInputNumber++;
		}
	}
	return successInputNumber;
}

ostream& operator<<(ostream& out, PolyDictionary& poly)
{
	for (map<string, Polynomial>::iterator i = poly.getDictionary().begin();
	i != poly.getDictionary().end(); ++i)
	{
		out << i->first << "(x) =" << i->second << endl;
	}
	return out;
}

istream& operator>>(istream& in, PolyDictionary& poly)
{
	string key;
	string polyString;
	getline(in, key, '\n');
	getline(in, polyString, '\n');
	Polynomial pTemp(polyString);
	poly.getDictionary().emplace(key, pTemp);
	return in;
}

ofstream& operator<<(ofstream& fout, PolyDictionary& poly)
{
	for (map<string, Polynomial>::iterator i = poly.getDictionary().begin();
	i != poly.getDictionary().end(); ++i)
	{
		fout << i->first << ':';
		fout << i->second << ";\n";
	}
	fout << endl;
	return fout;
}

inline map<string, Polynomial>& PolyDictionary::getDictionary()
{
	return dictionary;
}

double PolyDictionary::operator()(const string& key, double x) const
{
	return dictionary.at(key)(x);
}

Polynomial& PolyDictionary::operator[](const std::string& key)
{
	return dictionary.at(key);
}
