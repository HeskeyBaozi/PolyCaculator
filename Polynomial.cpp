#include "Polynomial.h"


std::istream& operator>>(std::istream& in, Polynomial& poly)
{
	std::string polynomialString;
	in >> polynomialString;
	std::string::iterator i = polynomialString.begin();
	std::string::iterator previous = i;
	while (i != polynomialString.end())
	{
		while (i != polynomialString.end() && *i != '(')++i;
		std::string monomialString(previous, i);
		if (!monomialString.empty())
		{
			Monomial temp(monomialString);
			poly.polyLibrary.push_back(temp);
		}
		previous = i;
		if (previous != polynomialString.end())++i;
	}


	return in;
}
