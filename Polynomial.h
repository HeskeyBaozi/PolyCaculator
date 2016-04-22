#pragma once
#include <iostream>
#include <algorithm>
#include <vector>
#include "Monomial.h"
class Polynomial
{
	/*
	* Polynomial ����ʽ��
	* ����ʽ���ɵ���ʽ�Ŀɱ����鹹��
	*/
public:
	explicit Polynomial(std::string polyString);
	void sortByPowerDescend();
	double getValue(double x);

	friend std::istream& operator>>(std::istream& in, Polynomial& poly);
	friend int operator>>(std::string& polynomialString, Polynomial& poly);
	friend std::ostream& operator<<(std::ostream& out, Polynomial& poly);
	friend std::ofstream& operator<<(std::ofstream& fout, Polynomial& poly);
private:
	std::vector<Monomial> polyLibrary;
};


