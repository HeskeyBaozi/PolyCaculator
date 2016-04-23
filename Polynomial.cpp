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
				poly.getPolyLibrary().push_back(mTemp);
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
	if (poly.getPolyLibrary().empty())
	{
		out << " [Empty Polynomial!]";
		return out;
	}

	/*
	* ��֤��һ���ϵ�������������, ����ʽ�ɿո�ʼ
	*/
	if (poly.getPolyLibrary()[0].getCoefficient() >= 0)
		out << " ";
	out << poly.getPolyLibrary()[0];

	/*
	* ����ÿ������ʽ�����
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
