#include <iostream>
#include "Polynomial.h"
using namespace std;

int main()
{
	Polynomial a;
	cin >> a;
	Polynomial::sortByPowerDescend(a.polyLibrary);
	for(const auto& mono:a.polyLibrary)
	{
		cout << mono.toString();
	}
	return 0;
}