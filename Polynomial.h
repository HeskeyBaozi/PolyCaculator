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
	
	friend int operator>>(std::string& polynomialString, Polynomial& poly);
	std::vector<Monomial>& getPolynomial();

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

	/*
	* 其他重载运算符
	*/

	friend std::istream& operator>>(std::istream& in, Polynomial& poly);

	friend std::ostream& operator<<(std::ostream& out, Polynomial& poly);
	friend std::ofstream& operator<<(std::ofstream& fout, Polynomial& poly);

	friend Polynomial operator+(Polynomial& lhs, Polynomial& rhs);
	friend Polynomial operator-(Polynomial& lhs, Polynomial& rhs);
	friend Polynomial operator*(Monomial& lhs, Polynomial& rhs);
	friend Polynomial operator*(Polynomial& lhs, Polynomial& rhs);

private:
	std::vector<Monomial> __polynomial;
	void sortByPowerDescend();
};

