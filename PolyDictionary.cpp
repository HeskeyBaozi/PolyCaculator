#include "PolyDictionary.h"
using namespace std;

/*
*   ����>>�����: ͨ���ļ���ȡ���ֵ���
*           fin: �ļ�������
*    dictionary: Ҫ����Ķ���ʽ�ֵ�
*        return: ����int
*                ��ʾ�ɹ���������ֵ�ļ�ֵ�Ը���
*/
int operator>>(ifstream& fin, PolyDictionary& dictionary)
{
	int successInputNumber = 0;
	/*
	* ���������ļ�ֱ��EOF
	*/
	while (!fin.eof())
	{
		/*
		*        key: ��(�ؼ���)
		* polyString: �������ɶ���ʽ���ַ���
		*/
		string key;
		string polyString;
		/*
		* ��':'֮ǰ��ȡ��key
		* ͬʱ���key���п�ͷ����հ��ַ�
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
			/*  ��ֵ��:
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
