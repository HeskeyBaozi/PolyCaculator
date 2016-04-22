#pragma once
#include <iostream>
#include <algorithm>
#include <vector>
#include "Monomial.h"
class Polynomial
{	
public:
	Polynomial();
	explicit Polynomial(std::string polyString);
	friend std::istream& operator>>(std::istream& in, Polynomial& poly);
	void sortByPowerDescend();
	std::vector<Monomial>& getPolyLibrary();
	
private:
	std::vector<Monomial> polyLibrary;
};

void operator>>(std::string& polynomialString, Polynomial& poly);
std::ostream& operator<<(std::ostream& out, Polynomial& poly);
std::ofstream& operator<<(std::ofstream& fout, Polynomial& poly);

