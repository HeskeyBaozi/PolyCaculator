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
		string key;
		string polyString;
		fin >> key >> polyString;		
		Polynomial pTemp(polyString);
		/*  ��ֵ��:
		*     key: key
		*   value: pTemp
		*   �γ�����Ժ�׷�ӵ��ֵ���
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
