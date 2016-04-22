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
	return mNumber;
}

ostream& operator<<(ostream& out, Polynomial& poly)
{
	if (poly.getPolyLibrary().empty())
	{
		out << "Empty Polynomial!";
		return out;
	}
	out << poly.getPolyLibrary()[0];
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
	for (size_t i = 0; i < poly.getPolyLibrary().size();i++)
	{
		fout << poly.getPolyLibrary()[i];
	}
	return fout;
}

Polynomial::Polynomial()
{
}

Polynomial::Polynomial(string polyString)
{
	polyString >> *this;
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
	std::sort(polyLibrary.begin(), polyLibrary.end(),[](const Monomial& lhs, const Monomial& rhs)
	{
		return lhs.getPower() > rhs.getPower();
	});
}

inline vector<Monomial>& Polynomial::getPolyLibrary()
{
	return polyLibrary;
}
