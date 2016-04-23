#pragma once
#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <stdio.h>
#define Ep 0.000001
class Monomial
{
	/*
	* Monomial 单项式类
	*/
public:
	explicit Monomial(const double coefficient_ = 0, const double power_ = 0);
	explicit Monomial(const std::string& monoString);
	Monomial(const Monomial& oldMono);
	double getCoefficient() const;
	double getPower() const;
	bool isZero() const;

	void setCoefficient(const double coefficient_);
	void setPower(const double power_);

	/*
	* 重载赋值,调用运算符
	* 调用()运算符用来求值
	*/
	Monomial operator-() const;
	Monomial& operator+=(const Monomial& rhs);
	Monomial& operator-=(const Monomial& rhs);
	double operator()(double x)const;

	/*
	* 定义求导运算符!
	*/
	Monomial operator!()const;

	/*
	* 定义不定积分运算符~
	*/
	Monomial operator~()const;

	/*
	* 定义定积分运算符(),通过重载()的形式
	*/
	double operator()(const double lowerBound, const double upperBound)const;
private:
	double coefficient;
	double power;
};

/*
* 重载读入运算符, 主要通过std::string匹配实现
*/
bool operator>>(const std::string& inString, Monomial& mono);
std::istream& operator>>(std::istream& in, Monomial& mono);
std::ifstream& operator>>(std::ifstream& fin, Monomial& mono);

/*
* 重载输出运算符
*/
std::ostream& operator<<(std::ostream& out, Monomial& mono);
std::ofstream& operator<<(std::ofstream& fout, Monomial& mono);

/*
* 重载算术,关系运算符,关系只是比较指数部分
*/
Monomial operator+(const Monomial& lhs, const Monomial& rhs);
Monomial operator-(const Monomial& lhs, const Monomial& rhs);
bool operator==(const Monomial& lhs, const Monomial& rhs);
bool operator!=(const Monomial& lhs, const Monomial& rhs);
bool operator<(const Monomial& lhs, const Monomial& rhs);
bool operator<=(const Monomial& lhs, const Monomial& rhs);
bool operator>(const Monomial& lhs, const Monomial& rhs);
bool operator>=(const Monomial& lhs, const Monomial& rhs);


