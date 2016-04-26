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
*        ���������: ͨ��std::string �������ʽ
* polynomialString: ����Ĵ�
*             poly: Ҫ����Ķ���ʽ
*           return: ����int
*                   ��ʾ�ɹ�������ö���ʽ�ĵ���ʽ����
*/
int operator>>(string& polynomialString, Polynomial& poly)
{
	/*
	* ��������m��ͷ���������뵥��ʽmonomial��ص�
	*/
	int mNumber = 0;

	/*
	* ��mHead��mTail��ƥ�䴮�еĵ���ʽ
	* mHead: ƥ�䵽������(
	* mTail: ƥ�䵽������(
	*/
	string::iterator mTail = polynomialString.begin();
	string::iterator mHead = mTail;
	while (mTail != polynomialString.end())
	{
		while (mTail != polynomialString.end() && *mTail != '(')
			++mTail;

		/*
		* mString: ƥ�䵽�Ŀ��Ա�ʾһ������ʽ�Ĵ�
		*/
		string mString(mHead, mTail);
		if (!mString.empty())
		{
			/*
			* mTemp: �ô����ɵ���ʱ����ʽ
			*        ���������ʽ��Ϊ0, ��������ʽ��
			*/
			Monomial mTemp(mString);
			if (!mTemp.isZero())
			{
				poly.getPolynomial().push_back(mTemp);
				mNumber++;
			}
		}

		/*
		* ��֤�ɹ�ƥ�䵽��һ������ʽ
		*/
		mHead = mTail;
		if (mHead != polynomialString.end())
			++mTail;
	}
	/*
	* ����������Ķ���ʽ��ָ����������
	*/
	poly.sortByPowerDescend();
	return mNumber;
}

/*
*  ����<<�����: ���һ������ʽ����Ļ
*          out: �����
*         poly: Ҫ����Ķ���ʽ
*       return: ostream& ��֤��ʽ����
*         Լ��: ����ʽ��һ���ո�ʼ
*               ÿ�����ż䶼��һ���ո�
*/
ostream& operator<<(ostream& out, Polynomial& poly)
{
	/*
	* ������ʽΪ��, ���������Ϣ
	*/
	if (poly.getPolynomial().empty())
	{
		out << " [Empty Polynomial!]";
		return out;
	}

	/*
	* ��֤��һ���ϵ�������������, ����ʽ�ɿո�ʼ
	*/
	if (poly.getPolynomial()[0].getCoefficient() >= 0)
		out << " ";
	out << poly.getPolynomial()[0];

	/*
	* ����ÿ������ʽ�����
	*/
	for (size_t i = 1; i < poly.getPolynomial().size(); i++)
	{
		if (poly.getPolynomial()[i].getCoefficient() >= 0)
			out << " + ";
		out << poly.getPolynomial()[i];
	}
	return out;
}

ofstream& operator<<(ofstream& fout, Polynomial& poly)
{
	for (size_t i = 0; i < poly.getPolynomial().size(); i++)
	{
		fout << poly.getPolynomial()[i];
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
* ���ö���ʽ�еĵ���ʽ��ָ���ɴ�С����
*/
void Polynomial::sortByPowerDescend()
{
	/*
	* std::sort() ��Ҫ #include <algorithm>
	* ǰ������������Ҫ����ķ�Χ
	* ������������һ��lambda���ʽ
	* ���lambda���ʽ��ʾ����ǰ��ָ��Ҫ�������򿿺��
	*/
	std::sort(__polynomial.begin(), __polynomial.end(), [](const Monomial& lhs, const Monomial& rhs)
	{
		return lhs.getPower() > rhs.getPower();
	});
}

inline vector<Monomial>& Polynomial::getPolynomial()
{
	return __polynomial;
}

Polynomial Polynomial::operator-() const
{
	Polynomial temp = *this;
	for (vector<Monomial>::iterator i = temp.getPolynomial().begin();
	i != temp.getPolynomial().end();++i)
	{
		*i = -*i;
	}
	return temp;
}

double Polynomial::operator()(double x) const
{
	double sum = 0;
	for (size_t i = 0; i < __polynomial.size(); i++)
	{
		sum += __polynomial[i](x);
	}
	return sum;
}

Polynomial Polynomial::operator!() const
{
	Polynomial temp = *this;
	for (vector<Monomial>::iterator i = temp.getPolynomial().begin();
	i != temp.getPolynomial().end(); ++i)
	{
		*i = !*i;
	}
	return temp;
}

Polynomial Polynomial::operator~() const
{
	Polynomial temp = *this;
	for (vector<Monomial>::iterator i = temp.getPolynomial().begin();
	i != temp.getPolynomial().end(); ++i)
	{
		*i = ~*i;
	}
	return temp;
}

double Polynomial::operator()(const double lowerBound, const double upperBound)
{
	double resultSum = 0;
	for (vector<Monomial>::iterator i = __polynomial.begin();
	i != __polynomial.end(); ++i)
	{
		resultSum += (*i)(lowerBound, upperBound);
	}
	return resultSum;
}

Polynomial operator+(Polynomial& lhs, Polynomial& rhs)
{
	Polynomial temp;
	vector<Monomial>::iterator lhsPoint = lhs.getPolynomial().begin();
	vector<Monomial>::iterator rhsPoint = rhs.getPolynomial().begin();
	while (lhsPoint != lhs.getPolynomial().end()
		&& rhsPoint != rhs.getPolynomial().end())
	{
		if (*lhsPoint == *rhsPoint)
		{
			Monomial result = *lhsPoint + *rhsPoint;
			if (abs(result.getCoefficient()) > Ep)
				temp.getPolynomial().push_back(result);
			++lhsPoint;
			++rhsPoint;
		}
		else
		{
			if (*lhsPoint > *rhsPoint)
			{
				temp.getPolynomial().push_back(*lhsPoint);
				++lhsPoint;
			}
			else
			{
				temp.getPolynomial().push_back(*rhsPoint);
				++rhsPoint;
			}
		}
	}
	while (lhsPoint != lhs.getPolynomial().end())
	{
		temp.getPolynomial().push_back(*lhsPoint);
		++lhsPoint;
	}
	while (rhsPoint != rhs.getPolynomial().end())
	{
		temp.getPolynomial().push_back(*rhsPoint);
		++rhsPoint;
	}
	return temp;
}

Polynomial operator-(Polynomial& lhs, Polynomial& rhs)
{
	Polynomial reverseRhs = -rhs;
	return lhs + reverseRhs;
}

Polynomial operator*(Monomial& lhs, Polynomial& rhs)
{
	Polynomial temp = rhs;
	for (vector<Monomial>::iterator i = temp.getPolynomial().begin();
	i != temp.getPolynomial().end(); ++i)
	{
		*i = lhs * (*i);
	}
	return temp;
}

Polynomial operator*(Polynomial& lhs, Polynomial& rhs)
{
	Polynomial resultPoly;
	Polynomial lhsTemp = lhs;
	for (vector<Monomial>::iterator lhsItemPoint = lhsTemp.getPolynomial().begin();
	lhsItemPoint != lhsTemp.getPolynomial().end(); ++lhsItemPoint)
	{
		Polynomial monoMultiPoly = (*lhsItemPoint) * rhs;
		resultPoly = resultPoly + monoMultiPoly;
	}
	return resultPoly;
}
