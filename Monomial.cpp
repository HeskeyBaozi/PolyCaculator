#include "Monomial.h"
using namespace std;

Monomial::Monomial(const int coefficient_, const int power_)
{
	setCoefficient(coefficient_);
	setPower(power_);
}

Monomial::Monomial(const std::string& monoString)
{
	monoString >> *this;
}

string Monomial::toString() const
{
	string result;
	if (getCoefficient() == 0)return result;
	stringstream stream;
	string power_;
	stream << getPower();
	stream >> power_;
	if (getCoefficient() == 1 || getCoefficient() == -1)
	{		
		result = string(getCoefficient() > 0 ? "+" : "-") + string("x^") + power_;
		return result;
	}
	string coefficient_;
	stream.clear();
	stream << getCoefficient();
	stream >> coefficient_;
	result = (getCoefficient() > 0 ? string("+") + coefficient_ : coefficient_) + string("x^") + power_;
	return result;
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

istream& operator>>(istream& in, Monomial& mono)
{
	string monomialString;
	in >> monomialString;
	monomialString >> mono;
	return in;
}

int operator>>(const string& inString, Monomial& mono)
{
	int coefficient_ = 0, power_ = 0;
	int k = sscanf_s(inString.c_str(), "(%d,%d)", &coefficient_, &power_);
	mono.setCoefficient(coefficient_);
	mono.setPower(power_);
	return k;
}
