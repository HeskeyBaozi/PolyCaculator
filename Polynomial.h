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
	explicit Polynomial();
	
	friend int operator>>(std::string& polynomialString, Polynomial& poly);
	std::vector<Monomial>& getPolynomial();

	Polynomial operator-() const;
	double operator()(double x) const;
	/*
	* �����������!
	*/
	Polynomial operator!()const;

	/*
	* ���岻�����������~
	*/
	Polynomial operator~()const;

	/*
	* ���嶨���������(),ͨ������()����ʽ
	*/
	double operator()(const double lowerBound, const double upperBound);
private:
	std::vector<Monomial> __polynomial;
	void sortByPowerDescend();
};

std::istream& operator>>(std::istream& in, Polynomial& poly);


std::ostream& operator<<(std::ostream& out, Polynomial& poly);
std::ofstream& operator<<(std::ofstream& fout, Polynomial& poly);

Polynomial operator+(Polynomial& lhs, Polynomial& rhs);
Polynomial operator-(Polynomial& lhs, Polynomial& rhs);
Polynomial operator*(Monomial& lhs, Polynomial& rhs);
Polynomial operator*(Polynomial& lhs, Polynomial& rhs);
