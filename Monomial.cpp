#include "Monomial.h"
using namespace std;

Monomial::Monomial(const int coefficient_, const int power_)
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

int Monomial::getCoefficient() const
{
	return coefficient;
}

int Monomial::getPower() const
{
	return power;
}

double Monomial::getValue(double x) const
{
	double coeff_ = getCoefficient();
	if (coeff_ == 0)
		return 0;
	double power_ = getPower();
	return coeff_ * pow(x, power_);
}

void Monomial::setCoefficient(const int coefficient_)
{
	coefficient = coefficient_;
}

void Monomial::setPower(const int power_)
{
	power = power_;
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
	int coefficient_ = 0, power_ = 0;
	int successInputNumber =
		sscanf_s(inString.c_str(), "(%d,%d)", &coefficient_, &power_);

	/*
	* ����ȡʧ��, ���ʧ����ʾ
	*/
	if (successInputNumber != 2)
		cout << inString << " is failed to input." << endl;

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
ostream& operator<<(std::ostream& out, Monomial& mono)
{
	int coeff_ = mono.getCoefficient();

	/*
	* ��ϵ��Ϊ0, ��õ���ʽΪ0, ��������κ��ַ�
	*/
	if (coeff_ == 0)return out;

	int power_ = mono.getPower();

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
	if (coeff_ != 1)out << coeff_;

	/*
	* ��ָ��Ϊ1, ��ָ�����ֲ������
	*/
	if (power_ != 0)out << "x^" << power_;
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
