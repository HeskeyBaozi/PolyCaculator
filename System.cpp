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
		cout << string(width / 4, ' ') << "Ŀǰ�洢�Ķ���ʽ��:" << "\n\n";
		cout << *this << endl;
	}		
	if (showLastLine)
		printLine();
}

void System::displayFunction(int width)
{
	cout << "�����﷨:\n";
	cout << string(7, ' ') << "push {key}:{Polymial}  ==>  ��Ӷ���ʽ\n";
	cout << string(5, ' ') << "remove {key}:{Polymial}  ==>  �Ƴ�����ʽ\n";
	cout << string(7, ' ') << "show {key}:{Polymial}{Sign}{Polymial}  ==>  ִ�ж���ʽ�Ӽ�������, �������ϵͳ��\n";
	cout << string(7, ' ') << "show {Polymial}{Sign}{Polymial}  ==>  ִ�ж���ʽ�Ӽ�������\n";
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
					cerr << "������һ�����ʽ : )" << endl;		
		return;
	}
	displayHead("ָ����������, ����������");
}

void System::pushPoly(const string& key, const string& value)
{
	string message("�ɹ���Ӹö���ʽ");
	try
	{
		if (value.empty() || key.empty())
			throw runtime_error("key��value��ֵΪ��");
	}
	catch (runtime_error err)
	{
		message = "���ʧ��, ������������һ����ָ��";
		displayHead(message);
		return;
	}
	Polynomial pTemp(value);
	pushPoly(key, pTemp);
}

void System::pushPoly(const std::string& key, const Polynomial& polyValue)
{
	string message("�ɹ���Ӹö���ʽ");
	this->getDictionary().emplace(key, polyValue);
	displayHead(message);
}

void System::removePoly(const std::string& key)
{
	string message("�ɹ�ɾ���ö���ʽ");
	try
	{
		if (key.empty())
			throw runtime_error("key��ֵΪ��");
	}
	catch (runtime_error err)
	{
		message = "ɾ��ʧ��, ������������һ����ָ��";
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
	* ��ȡkey, ��û��key, ��Ϊ��
	*/
	string key;
	bool keyIsNotEmpty = content.find(':') != content.npos;
	if (keyIsNotEmpty)
		getline(contentFlow, key, ':');
	/*
	* �����Ԫ�������Ĺ����ַ���
	*/
	string lhsStr, rhsStr;
	getline(contentFlow, lhsStr, sign);
	getline(contentFlow, rhsStr, '\n');

	/*
	* ������, ������ʧ���򷵻�
	*/
	Polynomial result;
	if (operationByString(lhsStr, rhsStr, sign, result) == false)
		return;
	/*
	* �����key, ������ֵ���
	*/
	if (keyIsNotEmpty)
		this->getDictionary().emplace(key, result);
	/*
	* ������
	*/
	displayHead("");
	cout << "�õ��Ľ��Ϊ:\n" << string(5, ' ') << (key.empty() ? "��� =" : string(key + "(x) =")) << result << endl;
}

bool System::operationByString(std::string& lhsStr, std::string&rhsStr, const char sign, Polynomial& result)
{
	Polynomial lhs, rhs;
	if (lhsStr.find('(') == lhsStr.npos)
	{
		clearSpace(lhsStr, ' ');
		if (this->getDictionary().find(lhsStr) == this->getDictionary().end())
		{
			cerr << "��һ�����ʽ�Ҳ���: " << lhsStr << " ,����������ָ��" << endl;
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
			cerr << "��һ�����ʽ�Ҳ���: " << rhsStr << " ,����������ָ��" << endl;
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
		cerr << "�޷�ִ�дβ���" << endl;
		return false;
	}
	return true;
}

void System::displayPicture(int width)
{
	cout << string(width / 4, ' ') << "�m �� �� .o�� �m  �m.. ��\n";
	cout << string(width / 4, ' ') << " �m���m ��  �� .�m �mo�y�z�|�}\n";
	cout << string(width / 4, ' ') << " �� �� /��\\/��\\ �m �� �m�m �� �m \n";
	cout << string(width / 4, ' ') << "�|�}�~�����������~�}�|�z�y���m\n" << endl;
}


void System::printLine(char ch, int width)
{
	cout << string(width, ch) << "\n";
}
