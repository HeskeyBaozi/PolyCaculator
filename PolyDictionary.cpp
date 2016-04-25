#include "PolyDictionary.h"
using namespace std;

void clearSpace(std::string& str, char spaceChar)
{
	size_t spaceBegin = str.npos;
	size_t spaceEnd = str.npos;
	spaceBegin = str.find_first_of(spaceChar);
	spaceEnd = str.find_first_not_of(spaceChar);
	if (spaceBegin != str.npos&&spaceEnd != str.npos)
		str.replace(spaceBegin, spaceEnd, "");
	spaceBegin = str.find_first_of(spaceChar);
	spaceEnd = str.find_last_of(spaceChar);
	if (spaceBegin != str.npos&&spaceEnd != str.npos)
		str.replace(spaceBegin, spaceEnd, "");
}

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
		clearSpace(key, ' ');
		clearSpace(key, '\n');
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
