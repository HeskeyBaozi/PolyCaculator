#include "System.h"
using namespace std;

System::System()
	:PolyDictionary()
{
	ifstream fin("file/data.txt");
	if(fin)
	{
		fin >> *this;
	}else
	{
		cerr << "Fail to init dictionary!" << endl;
	}
	fin.close();
}

System::~System()
{
	ofstream fout("file/data.txt");
	if(fout)
	{
		fout << *this;
	}else
	{
		cerr << "Fail to appendid new data" << endl;
	}
	fout.close();
}

void System::displayHead(const std::string message, bool showLastLine, bool showFunction, int width)
{
	printLine();
	cout << "\n";
	displayPicture();
	cout << string(width / 4, ' ') << message << "\n\n";
	if (showFunction)
		displayFunction();
	if (showLastLine)
		printLine();
}

void System::displayFunction(int width)
{
	cout << string(width / 4, ' ') << "[ 1 ] 显示存储的多项式\n";
	cout << string(width / 4, ' ') << "[ 2 ] 算术运算\n";
	cout << string(width / 4, ' ') << "[ 3 ] 求导与积分运算\n";
	cout << string(width / 4, ' ') << "[ 0 ] 退出\n";
	cout << endl;
}

void System::displayPicture(int width)
{
	cout << string(width / 4, ' ') << "﹎ ┈ ┈ .o┈ ﹎  ﹎.. ○\n";
	cout << string(width / 4, ' ') << " ﹎┈﹎ ●  ○ .﹎ ﹎o▂▃▅▆\n";
	cout << string(width / 4, ' ') << " ┈ ┈ /█\\/▓\\ ﹎ ┈ ﹎﹎ ┈ ﹎ \n";
	cout << string(width / 4, ' ') << "▅▆▇█████▇▆▅▃▂┈﹎\n" << endl;
}

void System::displayStoragedPolyDictionary()
{
	displayHead("There are storaged Polymials: ", false);
	cout << *this << endl;
	printLine();
	cout << "[0]: Back\n" << endl;
}

int System::getValidNumber(const int lowerBound, const int upperBound)
{
	int numberChosen = -1;
	cout << ">>> ";
	cin >> numberChosen;
	while (!(numberChosen >= lowerBound&&numberChosen <= upperBound))
	{
		cout << "Sorry, Please input again..." << endl;		
		cin.clear();
		cin.ignore(32, '\n');
		cout << ">>> ";
		cin >> numberChosen;
	}
	cout << "the number is " << numberChosen << endl;
	return numberChosen;
}

void System::addOperation() const
{

}

void System::printLine(char ch, int width)
{
	cout << string(width, ch) << "\n";
}
