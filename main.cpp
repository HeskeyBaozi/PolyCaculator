#include <iostream>
#include "System.h"
using namespace std;

int main()
{
	System sys;
	sys.displayHead("欢迎使用!");
	sys.displaySimpleInstruction();
	string order;
	cout << ">>> ";
	getline(cin, order, '\n');
	while (order != "quit")
	{
		string instruction;
		string content;
		sys.inputOrder(order, instruction, content);
		sys.instructionSwitcher(instruction, content);		
		cout << ">>> ";
		getline(cin, order, '\n');
	}
	sys.displayHead("欢迎再次使用, 再见!", false);
	return 0;
}