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
				poly.polyLibrary.push_back(mTemp);
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
	if (poly.polyLibrary.empty())
	{
		out << " [Empty Polynomial!]";
		return out;
	}

	/*
	* ��֤��һ���ϵ�������������, ����ʽ�ɿո�ʼ
	*/
	if (poly.polyLibrary[0].getCoefficient() >= 0)
		out << " ";
	out << poly.polyLibrary[0];

	/*
	* ����ÿ������ʽ�����
	*/
	for (size_t i = 1; i < poly.polyLibrary.size(); i++)
	{
		if (poly.polyLibrary[i].getCoefficient() >= 0)
			out << " + ";
		out << poly.polyLibrary[i];
	}
	return out;
}

ofstream& operator<<(ofstream& fout, Polynomial& poly)
{
	for (size_t i = 0; i < poly.polyLibrary.size(); i++)
	{
		fout << poly.polyLibrary[i];
	}
	return fout;
}

Polynomial::Polynomial(string polyString)
{
	polyString >> *this;
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

double Polynomial::getValue(double x)
{
	double sum = 0;
	for (size_t i = 0; i < polyLibrary.size(); i++)
	{
		sum += polyLibrary[i].getValue(x);
	}
	return sum;
}
