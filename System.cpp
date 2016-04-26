#include "System.h"
using namespace std;

System::System()
	:PolyDictionary()
{
	ifstream fin("file/data.txt");
	if (fin)
		fin >> *this;
	else
		cerr << "Fail to init dictionary!" << endl;
	fin.close();
}

System::~System()
{
	ofstream fout("file/data.txt");
	if (fout)
		fout << *this;
	else
		cerr << "Fail to appendid new data" << endl;
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
		cout << string(width / 4, ' ') << "Ŀǰ�洢�Ķ���ʽ��:" << "\n\n";
		cout << *this << endl;
	}
	if (showLastLine)
		printLine();
}

void System::displayInstruction(int width)
{
	cout << "�����﷨����: \n";
	cout << string(7, ' ') << "push {key}:{Polymial}  ==>  ��Ӷ���ʽ\n";
	cout << string(5, ' ') << "remove {key}:{Polymial}  ==>  �Ƴ�����ʽ\n";
	cout << string(7, ' ') << "show {Polymial} + {Polymial}  ==>  ����ʽ�ӷ�����\n";
	cout << string(7, ' ') << "show {Polymial} - {Polymial}  ==>  ����ʽ��������\n";
	cout << string(7, ' ') << "show {Polymial} * {Polymial}  ==>  ����ʽ�˷�����\n";
	cout << string(7, ' ') << "show !{Polymial}  ==>  ����ʽ��\n";
	cout << string(7, ' ') << "show ~{Polymial}  ==>  ����ʽ�󲻶�����\n";
	cout << "\n";
	cout << string(5, ' ') << "��ܰ������ʾ: \n";
	cout << string(7, ' ') << "��show������, �ڱ��ʽǰ�����ǰ׺  \"{key}:\"\n" << string(7, ' ') << "���ɽ��ý��������key����ϵͳ��\n";
}

bool System::inputOrder(const std::string& order, std::string& instruction, std::string& content) const
{
	istringstream orderFlow(order);
	getline(orderFlow, instruction, ' ');
	getline(orderFlow, content, '\n');
	if (instruction.empty() || content.empty())
	{
		cerr << "�����������Ϊ��" << endl;
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
			cerr << "����ʽ����Ϊ��, ����������" << endl;
			return false;
		}
		poly = Polynomial(polyString);
		return true;
	}
	else
	{
		/*
		* ��ȡkey, ��û��key, ��Ϊ��
		*/
		bool keyFound = content.find(':') != content.npos;
		if (keyFound)
			getline(contentFlow, key, ':');
		/*
		* ��ȡ������ʽ
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
		cerr << "key����Ϊ��, ����������" << endl;
		return false;
	}
	return true;
}

bool System::inputContent(const std::string& content, std::string& key, Polynomial& lhs, Polynomial& rhs, const char sign)
{
	istringstream contentFlow(content);
	/*
	* ��ȡkey, ��û��key, ��Ϊ��
	*/
	bool keyFound = content.find(':') != content.npos;
	if (keyFound)
		getline(contentFlow, key, ':');
	/*
	* �����Ԫ�������Ĺ����ַ���
	*/
	string lhsStr, rhsStr;
	getline(contentFlow, lhsStr, sign);
	getline(contentFlow, rhsStr, '\n');
	if (lhsStr.empty() || rhsStr.empty())
	{
		cerr << "����һ�����ʽΪ��, ����������" << endl;
		return false;
	}
	bool successLhs = stringToPolynomial(lhsStr, lhs);
	bool successRhs = stringToPolynomial(rhsStr, rhs);
	if (successLhs&&successRhs)return true;
	return false;
}

void System::instructionSwitcher(const std::string& instruction, const std::string& content)
{
	/*
	* ���������ж��Ƕ�Ԫ���㻹��һԪ����
	*/
	bool operationType = operationJudge(content);

	/*
	* push: ��Ӷ���ʽָ��
	*/
	if (instruction == "push")
	{
		string key;
		Polynomial poly;
		if (inputContent(content, key, poly) == false)
			return;
		this->getDictionary().emplace(key, poly);
		displayHead("�ɹ���Ӹö���ʽ");
		return;
	}

	/*
	* remove: �Ƴ�����ʽָ��
	*/
	if (instruction == "remove")
	{
		string key;
		if (inputContent(content, key) == false)
			return;
		if (this->getDictionary().erase(key) != 0)
			displayHead("�ɹ��Ƴ��ö���ʽ");
		else
		{
			cerr << "keyֵ��Ӧ�Ķ���ʽ�Ҳ���" << endl;
			return;
		}
		return;
	}

	/*
	* show: չ������ָ��
	*/
	if (instruction == "show")
	{
		string key;
		Polynomial result;
		if (operationType == true)
		{
			/*
			* ��Ԫ�������
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
			* һԪ�������
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
		* �����key, ������ֵ���
		*/
		if (!key.empty())
			this->getDictionary().emplace(key, result);
		/*
		* ������
		*/
		displayHead("");
		cout << "�õ��Ľ��Ϊ:\n" << string(5, ' ') << (key.empty() ? "��� =" : string(key + "(x) =")) << result << endl;
		return;
	}
	displayHead("ָ����������, ����������");
}


void System::displayPicture(int width)
{
	cout << string(width / 4, ' ') << "�m �� �� .o�� �m  �m.. ��\n";
	cout << string(width / 4, ' ') << " �m���m ��  �� .�m �mo�y�z�|�}\n";
	cout << string(width / 4, ' ') << " �� �� /��\\/��\\ �m �� �m�m �� �m \n";
	cout << string(width / 4, ' ') << "�|�}�~�����������~�}�|�z�y���m\n" << endl;
}


/*
* �ÿ�����key������������ʽ���ַ���ת���ɶ���ʽ
*   polyString: �ַ���, ������key, Ҳ�����������ŵĶ���ʽ�ַ�
*         poly: �����������Ķ���ʽ
*       return: ����ֵ
*               true: poly�ɹ��õ���ֵ
*              false: poly��ֵʧ��ԭ��Ϊkey��Ӧ�Ķ���ʽ�Ҳ���
*/
bool System::stringToPolynomial(const std::string& polyStringOrKey, Polynomial& poly)
{
	/*
	* �ж�polyString �Ƿ���һ����ʶ��key
	*/
	bool polyStringIsKey = polyStringOrKey.find('(') == polyStringOrKey.npos;
	if (polyStringIsKey)
	{
		string key = polyStringOrKey;
		clearSpace(key, ' ');
		bool keyIsFound = this->getDictionary().find(key) != this->getDictionary().end();
		/*
		* ���ҵ�key, ��poly��ֵΪkey����Ӧ�Ķ���ʽ
		*/
		if (keyIsFound)
		{
			poly = this->getDictionary().at(key);
			return true;
		}
		cerr << "��һ�����ʽ�Ҳ���: " << key << " ,����������ָ��" << endl;
		return false;
	}
	/*
	* ��polyString�Ǵ����ŵĶ���ʽ�ַ���
	* ��ֱ�Ӹ���poly
	*/
	poly = Polynomial(polyStringOrKey);
	return true;
}

/*
* �ж������Ƕ�Ԫ���㻹��һԪ����
*  true: ��Ԫ
* false: һԪ
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




void System::printLine(char ch, int width)
{
	cout << string(width, ch) << "\n";
}
