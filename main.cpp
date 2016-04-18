#include <iostream>
#include "Polynomial.h"
using namespace std;

int main()
{
	Polynomial a;
	cin >> a;
	for(const auto& mono:a.polyLibrary)
	{
		cout << mono.getCoefficient() << ' ' << mono.getPower() << endl;
	}
	return 0;
}