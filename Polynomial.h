#pragma once
#include <iostream>
#include <algorithm>
#include <vector>
#include "Monomial.h"
class Polynomial
{	
public:
	Polynomial() = default;
	friend std::istream& operator>>(std::istream& in, Polynomial& poly);
	static void sortByPowerDescend(std::vector<Monomial>& Poly);
	//std::string toString() const;
	std::vector<Monomial> polyLibrary;
private:
	
};