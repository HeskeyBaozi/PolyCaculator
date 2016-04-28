#pragma once
#include "Polynomial.h"
#include <map>
class PolyDictionary
{
	/*
	* Poly Dictionary ����ʽ�ֵ���
	* ������ǶԼ�ֵ�Լ��ϵķ�װ
	*/
public:
	std::map<std::string, Polynomial>& getDictionary();
	double operator()(const std::string& key, double x) const;
	Polynomial& operator[](const std::string& key);

	/*
	* ���������
	*/
	friend int operator>>(std::ifstream& fin, PolyDictionary& dictionary);

	friend std::ofstream& operator<<(std::ofstream& fout, PolyDictionary& poly);
	friend std::ostream& operator<<(std::ostream& out, PolyDictionary& poly);
	
private:
	std::map<std::string, Polynomial> __dictionary;
};


void clearSpace(std::string& str, char spaceChar);


