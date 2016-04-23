#include "Monomial.h"
using namespace std;

/*
* coeff_ == 0  <=> abs(coeff_ - 0) < Ep
*/

Monomial::Monomial(const double coefficient_, const double power_)
{
	setCoefficient(coefficient_);
	setPower(power_);
}

/*
* ����ʽ����ͨ��һ��������ʽ�����std::string��ʼ��
*/
Monomial::Monomial(const std::string& monoString)
{
	monoString >> *this;
}

Monomial::Monomial(const Monomial& oldMono)
{
	setCoefficient(oldMono.getCoefficient());
	setPower(oldMono.getPower());
}

inline double Monomial::getCoefficient() const
{
	return coefficient;
}

inline double Monomial::getPower() const
{
	return power;
}

inline void Monomial::setCoefficient(const double coefficient_)
{
	coefficient = coefficient_;
}

inline void Monomial::setPower(const double power_)
{
	power = power_;
}

Monomial Monomial::operator-() const
{
	Monomial temp(-getCoefficient(), getPower());
	return temp;
}

double Monomial::operator()(double x) const
{
	double coeff_ = getCoefficient();
	if (abs(coeff_ - 0) < Ep)
		return 0;
	double power_ = getPower();
	return coeff_ * pow(x, power_);
}

Monomial Monomial::operator!() const
{
	Monomial temp(
		getCoefficient()*getPower(),
		getPower() - 1);
	return temp;
}

Monomial Monomial::operator~() const
{
	Monomial temp(
		getCoefficient() / (getPower() + 1),
		getPower() + 1);
	return temp;
}

double Monomial::operator()(const double lowerBound, const double upperBound) const
{
	double fUpper = (~*this)(upperBound);
	double fLower = (~*this)(lowerBound);
	return fUpper - fLower;
}

bool Monomial::isZero() const
{
	if (getCoefficient() == 0)return true;
	return false;
}

istream& operator>>(istream& in, Monomial& mono)
{
	string monomialString;
	in >> monomialString;
	monomialString >> mono;
	return in;
}

/*
* istream ---> ifstream
* ifstream �� istream ��������
* ifstream ���Ե��� istream ����
*/
ifstream& operator>>(ifstream& fin, Monomial& mono)
{
	istream& in = fin;
	in >> mono;
	return fin;

}

/*
* ͨ��std::string ���뵥��ʽ
* inString: ����Ĵ�
*     mono: Ҫ����ĵ���ʽ
*   return: ����ֵbool
*           ����ɹ�: true
*           ����ʧ��: false
*/
bool operator>>(const string& inString, Monomial& mono)
{
	double coefficient_ = 0, power_ = 0;
	int successInputNumber =
		sscanf_s(inString.c_str(), "(%lf,%lf)", &coefficient_, &power_);

	/*
	* ����ȡʧ��, ���ʧ����ʾ
	*/
	/*if (successInputNumber != 2)
		cout << inString << " is failed to input." << endl;*/

	/*
	* ���õ���ʽ��ϵ����ָ��, Ĭ��Ϊ0
	*/
	mono.setCoefficient(coefficient_);
	mono.setPower(power_);
	if (successInputNumber == 2)return true;
	return false;
}


/*
* ��������������Ѻõ���ʽ�������ʽ
*/
ostream& operator<<(ostream& out, Monomial& mono)
{
	double coeff_ = mono.getCoefficient();

	/*
	* ��ϵ��Ϊ0, ��õ���ʽΪ0, ��������κ��ַ�
	*/
	if (abs(coeff_ - 0) < Ep)return out;

	double power_ = mono.getPower();

	/*
	* ��ϵ��Ϊ��ֵ, �����һ������, ȡ����ֵ
	*/
	if (coeff_ < 0)
	{
		out << " - ";
		coeff_ = -coeff_;
	}

	/*
	* ��ϵ��Ϊ1, ��ϵ�����������
	*/
	if (abs(coeff_ - 1)>Ep)
		out << coeff_;

	/*
	* ��ָ��Ϊ1, ��ָ�����ֲ������
	*/
	if (abs(power_ - 0) > Ep)
	{
		if (abs(power_ - 1) < Ep)
		{
			out << "x";
		}else
		{
			out << "x^" << power_;
		}
	}
	return out;
}

/*
* �Դ����ŵĴ������ݵ���ʽ������ļ���
*/
ofstream& operator<<(ofstream& fout, Monomial& mono)
{
	fout << "(" << mono.getCoefficient() << "," << mono.getPower() << ")";
	return fout;
}

Monomial operator+(const Monomial& lhs, const Monomial& rhs)
{
	Monomial temp(0, lhs.getPower());
	if (abs(lhs.getPower() - rhs.getPower()) > Ep)		
	{
		cerr << "ָ����һ�� �޷�����";
		return temp;
	}
	temp.setCoefficient(lhs.getCoefficient() + rhs.getCoefficient());
	return temp;
}

Monomial operator-(const Monomial& lhs, const Monomial& rhs)
{
	return lhs + (-rhs);
}

Monomial operator*(const Monomial& lhs, const Monomial& rhs)
{
	Monomial temp(
		lhs.getCoefficient()*rhs.getCoefficient(),
		lhs.getPower() + rhs.getPower());
	return temp;
}

Monomial operator/(const Monomial& lhs, const Monomial& rhs)
{
	Monomial temp(
		lhs.getCoefficient() / rhs.getCoefficient(),
		lhs.getPower() - rhs.getPower());
	return temp;
}

bool operator==(const Monomial& lhs, const Monomial& rhs)
{
	if (abs(lhs.getPower() - rhs.getPower()) < Ep)
		return true;
	return false;
}

bool operator!=(const Monomial& lhs, const Monomial& rhs)
{
	return !(lhs == rhs);
}

bool operator<(const Monomial& lhs, const Monomial& rhs)
{
	if (lhs.getPower() < rhs.getPower()
		&& abs(lhs.getPower() - rhs.getPower()) > Ep)
		return true;
	return false;
}

bool operator<=(const Monomial& lhs, const Monomial& rhs)
{
	return lhs < rhs || lhs == rhs;
}

bool operator>(const Monomial& lhs, const Monomial& rhs)
{
	return !(lhs <= rhs);
}

bool operator>=(const Monomial& lhs, const Monomial& rhs)
{
	return !(lhs < rhs);
}
