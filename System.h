#pragma once
#include <cstdlib>
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
	* getValidNumber: ������[lowerBound, upperBound]�ڵõ�һ���Ϸ�����
	*/
	static void displayHead(const std::string message, 
		bool showLastLine, bool showFunction = false, 
		int width = WIDTH);
	static int getValidNumber(const int lowerBound, const int upperBound);

	/*
	* ģ�鹦�ܺ���:
	* displayStoragedPolyDictionary: չʾ�洢�Ķ���ʽģ��
	*                  addOperation: �������� - �ӷ�
	*
	*/
	void displayStoragedPolyDictionary();
	void addOperation() const;
	
	
private:
	static void printLine(char ch = '=', int width = WIDTH);
	static void displayFunction(int width = WIDTH);
	static void displayPicture(int width = WIDTH);
};
