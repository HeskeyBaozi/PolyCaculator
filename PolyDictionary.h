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
private:
	std::map<std::string, Polynomial> dictionary;
};

int operator>>(std::ifstream& fin, PolyDictionary& dictionary);
std::istream& operator>>(std::istream& in, PolyDictionary& poly);
std::ofstream& operator<<(std::ofstream& fout, PolyDictionary& poly);
std::ostream& operator<<(std::ostream& out, PolyDictionary& poly);

