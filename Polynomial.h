#pragma once
#include <iostream>
#include <string>
#include <stdio.h>
#include <vector>
#include "Monomial.h"
class Polynomial
{	
public:
	Polynomial() = default;
	friend std::istream& operator>>(std::istream& in, Polynomial& poly);
	std::vector<Monomial> polyLibrary;
private:

};

