#pragma once
#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <stdio.h>
#define Ep 0.000001
class Monomial
{
	/*
	* Monomial ����ʽ��
	*/
public:
	explicit Monomial(const double coefficient_ = 0, const double power_ = 0);
	explicit Monomial(const std::string& monoString);
	Monomial(const Monomial& oldMono);
	double getCoefficient() const;
	double getPower() const;
	bool isZero() const;

	void setCoefficient(const double coefficient_);
	void setPower(const double power_);

	/*
	* ���ظ�ֵ,���������
	* ����()�����������ֵ
	*/
	Monomial operator-() const;
	Monomial& operator+=(const Monomial& rhs);
	Monomial& operator-=(const Monomial& rhs);
	double operator()(double x)const;

	/*
	* �����������!
	*/
	Monomial operator!()const;

	/*
	* ���岻�����������~
	*/
	Monomial operator~()const;

	/*
	* ���嶨���������(),ͨ������()����ʽ
	*/
	double operator()(const double lowerBound, const double upperBound)const;
private:
	double coefficient;
	double power;
};

/*
* ���ض��������, ��Ҫͨ��std::stringƥ��ʵ��
*/
bool operator>>(const std::string& inString, Monomial& mono);
std::istream& operator>>(std::istream& in, Monomial& mono);
std::ifstream& operator>>(std::ifstream& fin, Monomial& mono);

/*
* ������������
*/
std::ostream& operator<<(std::ostream& out, Monomial& mono);
std::ofstream& operator<<(std::ofstream& fout, Monomial& mono);

/*
* ��������,��ϵ�����,��ϵֻ�ǱȽ�ָ������
*/
Monomial operator+(const Monomial& lhs, const Monomial& rhs);
Monomial operator-(const Monomial& lhs, const Monomial& rhs);
bool operator==(const Monomial& lhs, const Monomial& rhs);
bool operator!=(const Monomial& lhs, const Monomial& rhs);
bool operator<(const Monomial& lhs, const Monomial& rhs);
bool operator<=(const Monomial& lhs, const Monomial& rhs);
bool operator>(const Monomial& lhs, const Monomial& rhs);
bool operator>=(const Monomial& lhs, const Monomial& rhs);


