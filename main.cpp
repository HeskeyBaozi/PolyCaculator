#include <iostream>
#include "System.h"
using namespace std;

int main()
{
	System sys;
	sys.displayHead("��ӭʹ��!");
	sys.displaySimpleInstruction();

	string order;
	cout << ">>> ";
	getline(cin, order, '\n');
	while (order != "quit")
	{
		string instruction, content;
		sys.inputOrder(order, instruction, content);
		sys.switcher(instruction, content);		

		cout << ">>> ";
		getline(cin, order, '\n');
	}
	sys.displayHead("��ӭ�ٴ�ʹ��, �ټ�!", false);
	return 0;
}