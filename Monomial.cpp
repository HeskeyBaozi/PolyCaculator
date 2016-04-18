#include "Monomial.h"

Monomial::Monomial(const int coefficient_, const int power_)
{
	setCoefficient(coefficient_);
	setPower(power_);
}

Monomial::Monomial(const std::string& monoString)
{
	monoString >> *this;
}

int Monomial::getCoefficient() const
{
	return coefficient;
}

int Monomial::getPower() const
{
	return power;
}

void Monomial::setCoefficient(const int coefficient_)
{
	coefficient = coefficient_;
}

void Monomial::setPower(const int power_)
{
	power = power_;
}

std::istream& operator>>(std::istream& in, Monomial& mono)
{
	std::string monomialString;
	in >> monomialString;
	monomialString >> mono;
	return in;
}

int operator>>(const std::string& inString, Monomial& mono)
{
	int coefficient_ = 0, power_ = 0;
	int k = sscanf_s(inString.c_str(), "(%d,%d)", &coefficient_, &power_);
	mono.setCoefficient(coefficient_);
	mono.setPower(power_);
	return k;
}
