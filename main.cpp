#include <iostream>
#include "System.h"
using namespace std;

int main()
{
	System sys;
	sys.displayHead("欢迎使用!");
	sys.displayFunction();
	string order;
	cout << ">>> ";
	getline(cin, order, '\n');
	while (order != "quit")
	{
		istringstream orderFlow(order);
		string instruction;
		string content;
		getline(orderFlow, instruction, ' ');
		getline(orderFlow, content, '\n');
		sys.dealContent(instruction, content);
		
		cout << ">>> ";
		getline(cin, order, '\n');
	}
	sys.displayHead("欢迎再次使用, 再见!", false);
	return 0;
}