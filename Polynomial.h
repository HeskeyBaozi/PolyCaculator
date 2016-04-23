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
	explicit Polynomial(std::string polyString);
	explicit Polynomial();
	void sortByPowerDescend();
	std::vector<Monomial>& getPolyLibrary();

	Polynomial operator-() const;
	double operator()(double x) const;
	/*
	* 定义求导运算符!
	*/
	Polynomial operator!()const;

	/*
	* 定义不定积分运算符~
	*/
	Polynomial operator~()const;

	/*
	* 定义定积分运算符(),通过重载()的形式
	*/
	double operator()(const double lowerBound, const double upperBound);
private:
	std::vector<Monomial> polyLibrary;
};

std::istream& operator>>(std::istream& in, Polynomial& poly);
int operator>>(std::string& polynomialString, Polynomial& poly);
std::ostream& operator<<(std::ostream& out, Polynomial& poly);
std::ofstream& operator<<(std::ofstream& fout, Polynomial& poly);
Polynomial operator+(Polynomial& lhs, Polynomial& rhs);
Polynomial operator-(Polynomial& lhs, Polynomial& rhs);



