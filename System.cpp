#include "System.h"
using namespace std;

System::System()
	:PolyDictionary()
{
	reload();
}

System::~System()
{
	save();
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

void System::displayInstruction(int width)
{
	cout << ": ) 详细的输入语法如下: \n\n";
	cout << string(7, ' ') << "push 【多项式名】:【多项式】  ==>  添加多项式\n";
	cout << string(5, ' ') << "remove 【多项式名】  ==>  移除多项式\n";
	cout << string(7, ' ') << "show 【多项式】 + 【多项式】  ==>  多项式加法运算\n";
	cout << string(7, ' ') << "show 【多项式】 - 【多项式】  ==>  多项式减法运算\n";
	cout << string(7, ' ') << "show 【多项式】 * 【多项式】  ==>  多项式乘法运算\n";
	cout << string(7, ' ') << "show !【多项式】  ==>  多项式求导\n";
	cout << string(7, ' ') << "show ~【多项式】  ==>  多项式求不定积分\n";
	cout << string(8, ' ') << "get 【多项式】(【x的取值】)  ==>  求当 x =【x的取值】时, 多项式的值\n";
	cout << string(8, ' ') << "get 【多项式】(【下界】,【上界】)  ==>  求多项式从【下界】积到【上界】的定积分\n";
	cout << "\n";
	cout << string(5, ' ') << "温馨技巧提示: \n";
	cout << string(7, ' ') << "在show命令中, 在表达式前面加入前缀  \"【多项式名】:\"\n" << string(7, ' ') << "即可将该结果以【多项式名】存入系统中\n";
}

void System::displaySimpleInstruction(bool simplist, int width)
{
	cout << "现在可以输入命令如下: \n";
	if(simplist)
	{
		cout << string(5, ' ') << "【push】,【remove】,【show】,【get】" << endl;
		cout << string(5, ' ') << "【save】,【clear】,【reload】,【help】,【quit】" << endl;
	}else
	{
		cout << string(7, ' ') << "【 push 】添加多项式" << string(9, ' ') << "【remove】移除多项式\n" << string(7, ' ') << "【 show 】多项式运算" << string(9, ' ') << "【  get 】多项式求值与积分运算\n" << string(7, ' ') << "【 help 】查看详细帮助" << string(7, ' ') << "【 save 】快速保存\n" << string(7, ' ') << "【 clear】清除所有数据" << string(7, ' ') << "【reload】重新加载数据\n" << string(7, ' ') << "【 quit 】保存并退出" << endl;
	}
}

bool System::inputOrder(const std::string& order, std::string& instruction, std::string& content) const
{
	istringstream orderFlow(order);
	getline(orderFlow, instruction, ' ');
	getline(orderFlow, content, '\n');
	if (!instruction.empty() && content.empty())return true;
	if (instruction.empty() || content.empty())
	{
		cerr << "命令或者内容为空" << endl;
		return false;
	}
	return true;
}

bool System::inputContent(const std::string& content, string& key, Polynomial& poly, const char sign, bool keyNeeded)
{
	istringstream contentFlow(content);
	if (keyNeeded)
	{
		getline(contentFlow, key, ':');
		string polyString;
		getline(contentFlow, polyString, '\n');
		if (polyString.empty())
		{
			cerr << "多项式内容为空, 请重新输入" << endl;
			return false;
		}
		poly = Polynomial(polyString);
		return true;
	}
	else
	{
		/*
		* 读取key, 若没有key, 则为空
		*/
		bool keyFound = content.find(':') != content.npos;
		if (keyFound)
			getline(contentFlow, key, ':');
		/*
		* 获取运算表达式
		*/
		string expression;
		getline(contentFlow, expression, '\n');
		string::iterator i = expression.begin();
		while (*i == sign)++i;
		string polyStringOrKey(i, expression.end());
		if (stringToPolynomial(polyStringOrKey, poly))return true;
		return false;
	}
}

bool System::inputContent(const std::string& order, std::string& key) const
{
	istringstream orderFlow(order);
	getline(orderFlow, key, '\n');
	if (key.empty())
	{
		cerr << "key内容为空, 请重新输入" << endl;
		return false;
	}
	return true;
}

bool System::inputContent(const std::string& content, std::string& key, Polynomial& lhs, Polynomial& rhs, const char sign)
{
	istringstream contentFlow(content);
	/*
	* 读取key, 若没有key, 则为空
	*/
	bool keyFound = content.find(':') != content.npos;
	if (keyFound)
		getline(contentFlow, key, ':');
	/*
	* 读入二元运算对象的构造字符串
	*/
	string lhsStr, rhsStr;
	getline(contentFlow, lhsStr, sign);
	getline(contentFlow, rhsStr, '\n');
	if (lhsStr.empty() || rhsStr.empty())
	{
		cerr << "其中一项多项式为空, 请重新输入" << endl;
		return false;
	}
	bool successLhs = stringToPolynomial(lhsStr, lhs);
	bool successRhs = stringToPolynomial(rhsStr, rhs);
	if (successLhs&&successRhs)return true;
	return false;
}

void System::instructionSwitcher(const std::string& instruction, const std::string& content)
{
	if (instruction == "help")
	{
		displayHead("");
		displayInstruction();
		return;
	}
	if (instruction == "reload")
	{
		reload();
		displayHead("");		
		cout << "重新加载完成" << endl;
		displaySimpleInstruction(true);
		cout << endl;
		return;
	}
	if (instruction == "save")
	{
		save();
		cout << "成功保存" << endl;
		displaySimpleInstruction(true);
		cout << endl;
		return;
	}
	if (instruction == "clear")
	{
		clear();
		displayHead("成功清除了所有数据");
		cout << "想补救? 试试输入【reload】" << endl;
		displaySimpleInstruction(true);
		cout << endl;
		return;
	}
	string key;
	Polynomial result;
	/*
	* 根据内容判断是二元运算还是一元运算
	*/
	bool operationType = operationJudge(content);

	/*
	* push: 添加多项式指令
	*/
	if (instruction == "push")
	{
		Polynomial poly;
		if (inputContent(content, key, poly) == false)
			return;
		this->getDictionary().emplace(key, poly);
		displayHead("成功添加该多项式");
		return;
	}

	/*
	* remove: 移除多项式指令
	*/
	if (instruction == "remove")
	{
		if (inputContent(content, key) == false)
			return;
		if (this->getDictionary().erase(key) != 0)
			displayHead("成功移除该多项式");
		else
		{
			cerr << "key值对应的多项式找不到" << endl;
			return;
		}
		return;
	}

	/*
	* show: 展现运算指令
	*/
	if (instruction == "show")
	{

		if (operationType == true)
		{
			/*
			* 二元运算情况
			*/

			Polynomial lhs;
			Polynomial rhs;
			char sign = getOperationSign(content);
			if (inputContent(content, key, lhs, rhs, sign) == false)return;
			switch (sign)
			{
			case '+':result = lhs + rhs; break;
			case '-':result = lhs - rhs; break;
			case '*':result = lhs * rhs; break;
			}
		}
		else
		{
			/*
			* 一元运算情况
			*/
			Polynomial poly;
			char sign = getOperationSign(content);
			if (inputContent(content, key, poly, sign,false) == false)return;
			switch (sign)
			{
			case '!':result = !poly; break;
			case '~':result = ~poly; break;
			}
		}
		/*
		* 如果有key, 则存入字典中
		*/
		if (!key.empty())
			this->getDictionary().emplace(key, result);
		/*
		* 输出结果
		*/
		displayHead("");
		cout << "得到的结果为:\n" << string(5, ' ') << (key.empty() ? "结果 =" : string(key + "(x) =")) << result << endl;
		displaySimpleInstruction(true);
		cout << endl;
		
		return;
	}

	if (instruction == "get")
	{
		Polynomial poly; 
		istringstream contentFlow(content);
		double resultValue = 0.0;
		string polyString;
		getline(contentFlow, polyString, '(');
		if (stringToPolynomial(polyString, poly) == false)return;
		string expression;
		getline(contentFlow, expression, '\n');
		double a = 0.0, b = 0.0;
		bool isValueOperation = false;
		if (sscanf(expression.c_str(), "%lf,%lf)", &a, &b) != 2)
		{
			isValueOperation = true;
			sscanf(expression.c_str(), "%lf)", &a);
		}
		/*
		* 输出结果
		*/
		displayHead("");
		
		if (isValueOperation)
		{
			resultValue = poly(a);
			if (key.empty())
				cout << "得到的结果为:\n" << string(5, ' ') << polyString << "(" << a << ") = " << resultValue << endl;
			else
				cout << "得到的结果为:\n" << string(5, ' ') << key << "( " << a << " ) = " << resultValue << endl;
		}
		else
		{
			resultValue = poly(a, b);
				cout << "得到的结果为:\n" << string(5, ' ') << "∫" << polyString << "(x)(" << a << "→" << b << ")" << key << " = " << resultValue << endl;
		}
		displaySimpleInstruction(true);
		cout << endl;
		return;		
	}
	cerr << "指令输入有误, 请重新输入" << endl;
}


void System::displayPicture(int width)
{
	cout << string(width / 4, ' ') << "﹎ ┈ ┈ .o┈ ﹎  ﹎.. ○\n";
	cout << string(width / 4, ' ') << " ﹎┈﹎ ●  ○ .﹎ ﹎o▂▃▅▆\n";
	cout << string(width / 4, ' ') << " ┈ ┈ /█\\/▓\\ ﹎ ┈ ﹎﹎ ┈ ﹎ \n";
	cout << string(width / 4, ' ') << "▅▆▇█████▇▆▅▃▂┈﹎\n" << endl;
}


/*
* 用可能是key或者是括号形式的字符串转换成多项式
*   polyString: 字符串, 可能是key, 也可能是有括号的多项式字符
*         poly: 用来保存结果的多项式
*       return: 布尔值
*               true: poly成功得到赋值
*              false: poly赋值失败原因为key对应的多项式找不到
*/
bool System::stringToPolynomial(const std::string& polyStringOrKey, Polynomial& poly)
{
	/*
	* 判断polyString 是否是一个标识符key
	*/
	bool polyStringIsKey = polyStringOrKey.find('(') == polyStringOrKey.npos;
	if (polyStringIsKey)
	{
		string key = polyStringOrKey;
		clearSpace(key, ' ');
		bool keyIsFound = this->getDictionary().find(key) != this->getDictionary().end();
		/*
		* 若找到key, 则poly赋值为key所对应的多项式
		*/
		if (keyIsFound)
		{
			poly = this->getDictionary().at(key);
			return true;
		}
		cerr << "有一项多项式找不到: " << key << " ,请重新输入指令" << endl;
		return false;
	}
	/*
	* 若polyString是带括号的多项式字符串
	* 则直接赋给poly
	*/
	poly = Polynomial(polyStringOrKey);
	return true;
}

/*
* 判断内容是二元运算还是一元运算
*  true: 二元
* false: 一元
*/
bool System::operationJudge(const std::string& content)
{
	bool findBinarySign = content.find('+') != string::npos
		|| content.find('-') != string::npos
		|| content.find('*') != string::npos;
	if (findBinarySign)return true;
	return false;
}

char System::getOperationSign(const std::string& content)
{
	if (content.find('+') != string::npos)
		return '+';
	if (content.find('-') != string::npos)
		return '-';
	if (content.find('*') != string::npos)
		return '*';
	if (content.find('!') != string::npos)
		return '!';
	if (content.find('~') != string::npos)
		return '~';
	return '+';
}

void System::save(const std::string& address)
{
	ofstream fout("file/data.txt");
	if (fout)
		fout << *this;
	else
		cerr << "Fail to appendid new data" << endl;
	fout.close();
}

void System::reload(const std::string& address)
{
	ifstream fin("file/data.txt");
	if (fin)
		fin >> *this;
	else
		cerr << "Fail to init dictionary!" << endl;
	fin.close();
}

void System::clear()
{
	this->getDictionary().clear();
}

void System::printLine(char ch, int width)
{
	cout << string(width, ch) << "\n";
}
