#pragma once
#include <iostream>
#include <fstream>
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
	bool isZero() const;

	void setCoefficient(const int coefficient_);
	void setPower(const int power_);
	
private:
	int coefficient;
	int power;
};

std::istream& operator>>(std::istream& in, Monomial& mono);
std::ifstream& operator>>(std::ifstream& fin, Monomial& mono);
bool operator>>(const std::string& inString, Monomial& mono);
std::ostream& operator<<(std::ostream& out, Monomial& mono);
std::ofstream& operator<<(std::ofstream& fout, Monomial& mono);
