#include "Polynomial.h"
using namespace std;

istream& operator>>(istream& in, Polynomial& poly)
{
	string polynomialString;
	in >> polynomialString;
	polynomialString >> poly;
	return in;
}

/*
*        重载运算符: 通过std::string 读入多项式
* polynomialString: 读入的串
*             poly: 要读入的多项式
*           return: 整型int
*                   表示成功读入进该多项式的单项式个数
*/
int operator>>(string& polynomialString, Polynomial& poly)
{
	/*
	* 函数体内m开头变量代表与单项式monomial相关的
	*/
	int mNumber = 0;

	/*
	* 用mHead和mTail来匹配串中的单项式
	* mHead: 匹配到左括号(
	* mTail: 匹配到右括号(
	*/
	string::iterator mTail = polynomialString.begin();
	string::iterator mHead = mTail;
	while (mTail != polynomialString.end())
	{
		while (mTail != polynomialString.end() && *mTail != '(')
			++mTail;

		/*
		* mString: 匹配到的可以表示一个单项式的串
		*/
		string mString(mHead, mTail);
		if (!mString.empty())
		{
			/*
			* mTemp: 用串生成的临时单项式
			*        若这个单项式不为0, 则读入多项式中
			*/
			Monomial mTemp(mString);
			if (!mTemp.isZero())
			{
				poly.getPolyLibrary().push_back(mTemp);
				mNumber++;
			}
		}

		/*
		* 保证成功匹配到下一个单项式
		*/
		mHead = mTail;
		if (mHead != polynomialString.end())
			++mTail;
	}
	/*
	* 将输入进来的多项式按指数降序排序
	*/
	poly.sortByPowerDescend();
	return mNumber;
}

/*
*  重载<<运算符: 输出一个多项式到屏幕
*          out: 输出流
*         poly: 要输出的多项式
*       return: ostream& 保证链式调用
*         约定: 多项式由一个空格开始
*               每个符号间都有一个空格
*/
ostream& operator<<(ostream& out, Polynomial& poly)
{
	/*
	* 若多项式为空, 输出警告信息
	*/
	if (poly.getPolyLibrary().empty())
	{
		out << " [Empty Polynomial!]";
		return out;
	}

	/*
	* 保证第一项的系数是正数情况下, 多项式由空格开始
	*/
	if (poly.getPolyLibrary()[0].getCoefficient() >= 0)
		out << " ";
	out << poly.getPolyLibrary()[0];

	/*
	* 遍历每个单项式并输出
	*/
	for (size_t i = 1; i < poly.getPolyLibrary().size(); i++)
	{
		if (poly.getPolyLibrary()[i].getCoefficient() >= 0)
			out << " + ";
		out << poly.getPolyLibrary()[i];
	}
	return out;
}

ofstream& operator<<(ofstream& fout, Polynomial& poly)
{
	for (size_t i = 0; i < poly.getPolyLibrary().size(); i++)
	{
		fout << poly.getPolyLibrary()[i];
	}
	return fout;
}

Polynomial::Polynomial(string polyString)
{
	polyString >> *this;
}

Polynomial::Polynomial()
{
}

/*
* 将该多项式中的单项式按指数由大到小排序
*/
void Polynomial::sortByPowerDescend()
{
	/*
	* std::sort() 需要 #include <algorithm>
	* 前两个参数是需要排序的范围
	* 第三个参数是一个lambda表达式
	* 这个lambda表达式表示排序靠前的指数要大于排序靠后的
	*/
	std::sort(polyLibrary.begin(), polyLibrary.end(), [](const Monomial& lhs, const Monomial& rhs)
	{
		return lhs.getPower() > rhs.getPower();
	});
}

inline vector<Monomial>& Polynomial::getPolyLibrary()
{
	return polyLibrary;
}

Polynomial Polynomial::operator-() const
{
	Polynomial temp = *this;
	for (vector<Monomial>::iterator i = temp.getPolyLibrary().begin();
	i != temp.getPolyLibrary().end();++i)
	{
		*i = -*i;
	}
	return temp;
}

double Polynomial::operator()(double x) const
{
	double sum = 0;
	for (size_t i = 0; i < polyLibrary.size(); i++)
	{
		sum += polyLibrary[i](x);
	}
	return sum;
}

Polynomial Polynomial::operator!() const
{
	Polynomial temp = *this;
	for (vector<Monomial>::iterator i = temp.getPolyLibrary().begin();
	i != temp.getPolyLibrary().end(); ++i)
	{
		*i = !*i;
	}
	return temp;
}

Polynomial Polynomial::operator~() const
{
	Polynomial temp = *this;
	for (vector<Monomial>::iterator i = temp.getPolyLibrary().begin();
	i != temp.getPolyLibrary().end(); ++i)
	{
		*i = ~*i;
	}
	return temp;
}

double Polynomial::operator()(const double lowerBound, const double upperBound)
{
	double resultSum = 0;
	for (vector<Monomial>::iterator i = polyLibrary.begin();
	i != polyLibrary.end(); ++i)
	{
		resultSum += (*i)(lowerBound, upperBound);
	}
	return resultSum;
}

Polynomial operator+(Polynomial& lhs, Polynomial& rhs)
{
	Polynomial temp;
	vector<Monomial>::iterator lhsPoint = lhs.getPolyLibrary().begin();
	vector<Monomial>::iterator rhsPoint = rhs.getPolyLibrary().begin();
	while (lhsPoint != lhs.getPolyLibrary().end()
		&& rhsPoint != rhs.getPolyLibrary().end())
	{
		if (*lhsPoint == *rhsPoint)
		{
			Monomial result = *lhsPoint + *rhsPoint;
			if (abs(result.getCoefficient()) > Ep)
				temp.getPolyLibrary().push_back(result);
			++lhsPoint;
			++rhsPoint;
		}
		else
		{
			if (*lhsPoint > *rhsPoint)
			{
				temp.getPolyLibrary().push_back(*lhsPoint);
				++lhsPoint;
			}
			else
			{
				temp.getPolyLibrary().push_back(*rhsPoint);
				++rhsPoint;
			}
		}
	}
	while (lhsPoint != lhs.getPolyLibrary().end())
	{
		temp.getPolyLibrary().push_back(*lhsPoint);
		++lhsPoint;
	}
	while (rhsPoint != rhs.getPolyLibrary().end())
	{
		temp.getPolyLibrary().push_back(*rhsPoint);
		++rhsPoint;
	}
	return temp;
}

Polynomial operator-(Polynomial& lhs, Polynomial& rhs)
{
	Polynomial reverseRhs = -rhs;
	return lhs + reverseRhs;
}
