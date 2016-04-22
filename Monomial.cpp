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

bool Monomial::isZero() const
{
	if (getCoefficient() == 0)return true;
	return false;
}

istream& operator>>(istream& in, Monomial& mono)
{
	string monomialString;
	in >> monomialString;
	monomialString >> mono;
	return in;
}

std::ifstream& operator>>(std::ifstream& fin, Monomial& mono)
{
	string monomialString;
	fin >> monomialString;
	monomialString >> mono;
	return fin;

}

bool operator>>(const string& inString, Monomial& mono)
{
	int coefficient_ = 0, power_ = 0;
	int k = sscanf_s(inString.c_str(), "(%d,%d)", &coefficient_, &power_);
	if (k != 2)cout << inString << " is failed to input. It is setted as (0,0)!!" << endl;
	mono.setCoefficient(coefficient_);
	mono.setPower(power_);
	if (k == 2)return true;
	return false;
}

ostream& operator<<(std::ostream& out, Monomial& mono)
{
	int coeff_ = mono.getCoefficient();
	if (coeff_ == 0)return out;
	int power_ = mono.getPower();
	if (coeff_ < 0)
	{
		out << " - ";
		coeff_ = -coeff_;
	}
	if (!(coeff_ == 1))out << coeff_;
	if (power_ != 0)out << "x^" << power_;
	return out;
}

std::ofstream& operator<<(std::ofstream& fout, Monomial& mono)
{
	fout << "(" << mono.getCoefficient() << "," << mono.getPower() << ")";
	return fout;
}
