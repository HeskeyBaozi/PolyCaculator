#pragma once
#include <iostream>
#include <string>
#include <stdio.h>
class Monomial
{
public:
	explicit Monomial(const int coefficient_ = 0, const int power_ = 0);
	explicit Monomial(const std::string& monoString);


	int getCoefficient() const;
	int getPower() const;
	void setCoefficient(const int coefficient_);
	void setPower(const int power_);
private:
	int coefficient;
	int power;
};

std::istream& operator>>(std::istream& in, Monomial& mono);
int operator>>(const std::string& inString, Monomial& mono);

