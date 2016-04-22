#include "Polynomial.h"
using namespace std;

istream& operator>>(istream& in, Polynomial& poly)
{
	string polynomialString;
	in >> polynomialString;
	string::iterator i = polynomialString.begin();
	string::iterator previous = i;
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

/*string Polynomial::toString() const
{
	for (size_t i = 0; i < polyLibrary.size(); ++i)
	{
		
	}
}*/

void Polynomial::sortByPowerDescend(vector<Monomial>& Poly)
{
	std::sort(Poly.begin(),Poly.end(),[](const Monomial& lhs, const Monomial& rhs)
	{
		return lhs.getPower() > rhs.getPower();
	});
}

