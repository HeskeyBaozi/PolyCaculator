#include <iostream>
#include "System.h"
using namespace std;

int main()
{
	System sys;
	sys.displayHead("Welcome to use my Poly-Caculator", true, true);
	int numberChosen = sys.getValidNumber(0, 3);
	system("cls");
	while (numberChosen != 0)
	{
		switch(numberChosen)
		{
		case 1:
			sys.displayStoragedPolyDictionary();
			break;
		}
		int zeroToBack = sys.getValidNumber(0, 0);
		system("cls");
		sys.displayHead("Welcome to use my Poly-Caculator", true, true);
		numberChosen = sys.getValidNumber(0, 3);
		system("cls");
	}
	sys.displayHead("GoodBye! See you next time..", true);
	return 0;
}