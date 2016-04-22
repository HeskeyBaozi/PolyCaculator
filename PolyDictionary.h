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
	friend int operator>>(std::ifstream& fin, PolyDictionary& dictionary);
	friend std::istream& operator>>(std::istream& in, PolyDictionary& poly);
	friend std::ofstream& operator<<(std::ofstream& fout, PolyDictionary& poly);
	friend std::ostream& operator<<(std::ostream& out, PolyDictionary& poly);
		
private:
	std::map<std::string, Polynomial> dictionary;
};


