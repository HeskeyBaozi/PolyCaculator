#pragma once
#include <iostream>
#include <algorithm>
#include <vector>
#include "Monomial.h"
class Polynomial
{
	/*
	* Polynomial 多项式类
	* 多项式类由单项式的可变数组构成
	*/
public:
	Polynomial();
	explicit Polynomial(std::string polyString);
	void sortByPowerDescend();
	std::vector<Monomial>& getPolyLibrary();
	
private:
	std::vector<Monomial> polyLibrary;
};

std::istream& operator>>(std::istream& in, Polynomial& poly);
int operator>>(std::string& polynomialString, Polynomial& poly);
std::ostream& operator<<(std::ostream& out, Polynomial& poly);
std::ofstream& operator<<(std::ofstream& fout, Polynomial& poly);


