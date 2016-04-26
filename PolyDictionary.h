#pragma once
#include "Polynomial.h"
#include <map>
class PolyDictionary
{
	/*
	* Poly Dictionary 多项式字典类
	* 这个类是对键值对集合的封装
	*/
public:
	std::map<std::string, Polynomial>& getDictionary();
	double operator()(const std::string& key, double x) const;
	Polynomial& operator[](const std::string& key);
	
private:
	std::map<std::string, Polynomial> __dictionary;
};

int operator>>(std::ifstream& fin, PolyDictionary& dictionary);

std::ofstream& operator<<(std::ofstream& fout, PolyDictionary& poly);
std::ostream& operator<<(std::ostream& out, PolyDictionary& poly);
void clearSpace(std::string& str, char spaceChar);


