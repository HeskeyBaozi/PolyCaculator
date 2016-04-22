#include "Polynomial.h"
using namespace std;

istream& operator>>(istream& in, Polynomial& poly)
{
	string polynomialString;
	in >> polynomialString;
	polynomialString >> poly;
	return in;
}

void operator>>(string& polynomialString, Polynomial& poly)
{
	string::iterator i = polynomialString.begin();
	string::iterator previous = i;
	while (i != polynomialString.end())
	{
		while (i != polynomialString.end() && *i != '(')++i;
		string monomialString(previous, i);
		if (!monomialString.empty())
		{
			Monomial temp(monomialString);
			if (!temp.isZero())poly.getPolyLibrary().push_back(temp);
		}
		previous = i;
		if (previous != polynomialString.end())++i;
	}
}

ostream& operator<<(ostream& out, Polynomial& poly)
{
	if (poly.getPolyLibrary().empty())
	{
		out << "None";
		return out;
	}
	out << poly.getPolyLibrary()[0];
	for (size_t i = 1; i < poly.getPolyLibrary().size(); i++)
	{
		if (poly.getPolyLibrary()[i].getCoefficient() >= 0)
			out << " + ";
		out << poly.getPolyLibrary()[i];
	}
	return out;
}

ofstream& operator<<(ofstream& fout, Polynomial& poly)
{
	for (size_t i = 0; i < poly.getPolyLibrary().size();i++)
	{
		fout << poly.getPolyLibrary()[i];
	}
	return fout;
}

Polynomial::Polynomial()
{
}

Polynomial::Polynomial(string polyString)
{
	polyString >> *this;
}

void Polynomial::sortByPowerDescend()
{
	std::sort(polyLibrary.begin(), polyLibrary.end(),[](const Monomial& lhs, const Monomial& rhs)
	{
		return lhs.getPower() > rhs.getPower();
	});
}

inline vector<Monomial>& Polynomial::getPolyLibrary()
{
	return polyLibrary;
}
