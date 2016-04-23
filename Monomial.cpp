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
* 单项式可以通过一个括号形式输入的std::string初始化
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
* ifstream 是 istream 的派生类
* ifstream 可以当做 istream 来用
*/
ifstream& operator>>(ifstream& fin, Monomial& mono)
{
	istream& in = fin;
	in >> mono;
	return fin;

}

/*
* 通过std::string 读入单项式
* inString: 读入的串
*     mono: 要读入的单项式
*   return: 布尔值bool
*           读入成功: true
*           读入失败: false
*/
bool operator>>(const string& inString, Monomial& mono)
{
	double coefficient_ = 0, power_ = 0;
	int successInputNumber =
		sscanf_s(inString.c_str(), "(%lf,%lf)", &coefficient_, &power_);

	/*
	* 若读取失败, 输出失败提示
	*/
	/*if (successInputNumber != 2)
		cout << inString << " is failed to input." << endl;*/

	/*
	* 设置单项式的系数和指数, 默认为0
	*/
	mono.setCoefficient(coefficient_);
	mono.setPower(power_);
	if (successInputNumber == 2)return true;
	return false;
}


/*
* 向输出流以人类友好的形式输出单项式
*/
ostream& operator<<(ostream& out, Monomial& mono)
{
	double coeff_ = mono.getCoefficient();

	/*
	* 若系数为0, 则该单项式为0, 不用输出任何字符
	*/
	if (abs(coeff_ - 0) < Ep)return out;

	double power_ = mono.getPower();

	/*
	* 若系数为负值, 则输出一个负号, 取绝对值
	*/
	if (coeff_ < 0)
	{
		out << " - ";
		coeff_ = -coeff_;
	}

	/*
	* 若系数为1, 则系数本身不必输出
	*/
	if (abs(coeff_ - 1)>Ep)
		out << coeff_;

	/*
	* 若指数为1, 则指数部分不必输出
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
* 以带括号的储存数据的形式输出到文件流
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
		cerr << "指数不一样 无法操作";
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
