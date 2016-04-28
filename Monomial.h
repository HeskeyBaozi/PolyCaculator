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

	/*
	* ���ض��������, ��Ҫͨ��std::stringƥ��ʵ��
	*/
	friend bool operator>>(const std::string& inString, Monomial& mono);
	friend std::istream& operator>>(std::istream& in, Monomial& mono);
	friend std::ifstream& operator>>(std::ifstream& fin, Monomial& mono);

	/*
	* ������������
	*/
	friend std::ostream& operator<<(std::ostream& out, Monomial& mono);
	friend std::ofstream& operator<<(std::ofstream& fout, Monomial& mono);

	/*
	* ��������,��ϵ�����,��ϵֻ�ǱȽ�ָ������
	*/
	friend Monomial operator+(const Monomial& lhs, const Monomial& rhs);
	friend Monomial operator-(const Monomial& lhs, const Monomial& rhs);
	friend Monomial operator*(const Monomial& lhs, const Monomial& rhs);
	friend Monomial operator/(const Monomial& lhs, const Monomial& rhs);
	friend bool operator==(const Monomial& lhs, const Monomial& rhs);
	friend bool operator!=(const Monomial& lhs, const Monomial& rhs);
	friend bool operator<(const Monomial& lhs, const Monomial& rhs);
	friend bool operator<=(const Monomial& lhs, const Monomial& rhs);
	friend bool operator>(const Monomial& lhs, const Monomial& rhs);
	friend bool operator>=(const Monomial& lhs, const Monomial& rhs);
private:
	double __coefficient;
	double __power;
};




