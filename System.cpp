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

void System::displayHead(const std::string message, bool showPoly, bool showLastLine, int width)
{
	system("cls");
	printLine();
	cout << "\n";
	displayPicture();
	cout << string(width / 4, ' ') << message << "\n";	
	if (showPoly)
	{
		cout << string(width / 4, ' ') << "目前存储的多项式有:" << "\n\n";
		cout << *this << endl;
	}		
	if (showLastLine)
		printLine();
}

void System::displayFunction(int width)
{
	cout << "输入语法:\n";
	cout << string(7, ' ') << "push {key}:{Polymial}  ==>  添加多项式\n";
	cout << string(5, ' ') << "remove {key}:{Polymial}  ==>  移除多项式\n";
	cout << string(7, ' ') << "show {key}:{Polymial}{Sign}{Polymial}  ==>  执行多项式加减乘运算, 并添加至系统中\n";
	cout << string(7, ' ') << "show {Polymial}{Sign}{Polymial}  ==>  执行多项式加减乘运算\n";
}

void System::dealContent(const string& instruction, const string& content)
{
	if (instruction == "push" || instruction == "remove")
	{
		istringstream contentFlow(content);
		string key;
		getline(contentFlow, key, ':');
		if (instruction == "push")
		{
			string value;
			getline(contentFlow, value, '\n');
			pushPoly(key, value);
		}else
		{
			removePoly(key);
		}
		return;
	}
	if (instruction == "show")
	{	
		if (content.find('+') != content.npos)
			show(content, '+');
		else
			if (content.find('-') != content.npos)
				show(content, '-');
			else
				if (content.find('*') != content.npos)
					show(content, '*');
				else
					cerr << "请输入一个表达式 : )" << endl;		
		return;
	}
	displayHead("指令输入有误, 请重新输入");
}

void System::pushPoly(const string& key, const string& value)
{
	string message("成功添加该多项式");
	try
	{
		if (value.empty() || key.empty())
			throw runtime_error("key或value的值为空");
	}
	catch (runtime_error err)
	{
		message = "添加失败, 可以重新输入一个新指令";
		displayHead(message);
		return;
	}
	Polynomial pTemp(value);
	pushPoly(key, pTemp);
}

void System::pushPoly(const std::string& key, const Polynomial& polyValue)
{
	string message("成功添加该多项式");
	this->getDictionary().emplace(key, polyValue);
	displayHead(message);
}

void System::removePoly(const std::string& key)
{
	string message("成功删除该多项式");
	try
	{
		if (key.empty())
			throw runtime_error("key的值为空");
	}
	catch (runtime_error err)
	{
		message = "删除失败, 可以重新输入一个新指令";
		displayHead(message);
		return;
	}
	this->getDictionary().erase(key);
	displayHead(message);
}

void System::show(const string& content, const char sign)
{
	istringstream contentFlow(content);
	/*
	* 读取key, 若没有key, 则为空
	*/
	string key;
	bool keyIsNotEmpty = content.find(':') != content.npos;
	if (keyIsNotEmpty)
		getline(contentFlow, key, ':');
	/*
	* 读入二元运算对象的构造字符串
	*/
	string lhsStr, rhsStr;
	getline(contentFlow, lhsStr, sign);
	getline(contentFlow, rhsStr, '\n');

	/*
	* 读入结果, 若读入失败则返回
	*/
	Polynomial result;
	if (operationByString(lhsStr, rhsStr, sign, result) == false)
		return;
	/*
	* 如果有key, 则存入字典中
	*/
	if (keyIsNotEmpty)
		this->getDictionary().emplace(key, result);
	/*
	* 输出结果
	*/
	displayHead("");
	cout << "得到的结果为:\n" << string(5, ' ') << (key.empty() ? "结果 =" : string(key + "(x) =")) << result << endl;
}

bool System::operationByString(std::string& lhsStr, std::string&rhsStr, const char sign, Polynomial& result)
{
	Polynomial lhs, rhs;
	if (lhsStr.find('(') == lhsStr.npos)
	{
		clearSpace(lhsStr, ' ');
		if (this->getDictionary().find(lhsStr) == this->getDictionary().end())
		{
			cerr << "有一项多项式找不到: " << lhsStr << " ,请重新输入指令" << endl;
			return false;
		}
		lhs = this->getDictionary().at(lhsStr);
	}
	else
	{
		lhs = Polynomial(lhsStr);
	}
	if (rhsStr.find('(') == rhsStr.npos)
	{
		clearSpace(rhsStr, ' ');
		if (this->getDictionary().find(rhsStr) == this->getDictionary().end())
		{
			cerr << "有一项多项式找不到: " << rhsStr << " ,请重新输入指令" << endl;
			return false;
		}
		rhs = this->getDictionary().at(rhsStr);
	}
	else
	{
		rhs = Polynomial(rhsStr);
	}
	switch (sign)
	{
	case '+':
		result = Polynomial(lhs + rhs);
		break;
	case '-':
		result = Polynomial(lhs - rhs);
		break;
	case '*':
		result = Polynomial(lhs * rhs);
		break;
	default:
		cerr << "无法执行次操作" << endl;
		return false;
	}
	return true;
}

void System::displayPicture(int width)
{
	cout << string(width / 4, ' ') << "﹎ ┈ ┈ .o┈ ﹎  ﹎.. ○\n";
	cout << string(width / 4, ' ') << " ﹎┈﹎ ●  ○ .﹎ ﹎o▂▃▅▆\n";
	cout << string(width / 4, ' ') << " ┈ ┈ /█\\/▓\\ ﹎ ┈ ﹎﹎ ┈ ﹎ \n";
	cout << string(width / 4, ' ') << "▅▆▇█████▇▆▅▃▂┈﹎\n" << endl;
}


void System::printLine(char ch, int width)
{
	cout << string(width, ch) << "\n";
}
