#pragma once
#include <cstdlib>
#include <sstream>
#include "PolyDictionary.h"
#define WIDTH 70
class System :public PolyDictionary
{
public:
	/*
	* ����, ��������
	*/
	System();
	~System();

	/*
	* IO����:
	*    displayHead: չ����Ļ�������ַ���������
	* 
	*/
	void displayHead(const std::string message, bool showPoly = true, bool showLastLine = true, int width = WIDTH);
	static void displayFunction(int width = WIDTH);
	void dealContent(const std::string& instruction, const std::string& content);
	
private:
	/*
	* ģ�鹦�ܺ���:
	*       pushPoly: ��Ӷ���ʽ���ֵ���
	*     removePoly: ���ֵ����Ƴ�����ʽ
	*/
	void pushPoly(const std::string& key, const std::string& value);
	void pushPoly(const std::string& key, const Polynomial& polyValue);
	void removePoly(const std::string& key);
	void show(const std::string& content, const char sign);
	bool operationByString(std::string& lhsStr, std::string&rhsStr, const char sign, Polynomial& result);
	bool operationByString(std::string& lhsStr, const char sign, Polynomial& result);
	static void printLine(char ch = '=', int width = WIDTH);
	static void displayPicture(int width = WIDTH);
	
};
