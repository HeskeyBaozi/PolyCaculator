#pragma once
#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <stdio.h>
class Monomial
{
	/*
	* Monomial 单项式类
	*/
public:
	explicit Monomial(const int coefficient_ = 0, const int power_ = 0);
	explicit Monomial(const std::string& monoString);

	int getCoefficient() const;
	int getPower() const;
	double getValue(double x) const;
	bool isZero() const;

	void setCoefficient(const int coefficient_);
	void setPower(const int power_);

private:
	int coefficient;
	int power;
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
