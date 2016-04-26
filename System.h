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

	/* ==============================
	*           �����������
	*  ==============================*/
	/*
	* Output:
	*        displayHead(...): ����, ����ʾҳ��ͷ����Ϣ
	* displayInstruction(...): ��ʾ�����﷨
	*/
	void displayHead(const std::string message, bool showPoly = true, bool showLastLine = true, int width = WIDTH);
	static void displayInstruction(int width = WIDTH);

	/*
	* ������, ����instruction��ֵ�������������ݲ�������
	*/
	void instructionSwitcher(const std::string& instruction, const std::string& content);

	/*
	* Input:
	*      inputOrder(...): ��һ������������ж���ָ���ָ�������
	*    inputContent(...): ����ָ������ݶ�ȡ�����Ϣ, ���������غ���
	*              ����(1): ��ȡ��ʽ {key}:{Polymial}, key��ѡ
	*              ����(2): ��ȡ��ʽ {key}
	*              ����(3): ��ȡ��ʽ {key}:{Polymial}{Sign}{Polymial}, key��ѡ
	*/
	bool inputOrder(const std::string& order, std::string& instruction, std::string& content) const;
	bool inputContent(const std::string& content, std::string& key, Polynomial& poly, const char sign = '!', bool keyNeeded = true);
	bool inputContent(const std::string& content, std::string& key) const;
	bool inputContent(const std::string& content, std::string& key, Polynomial& lhs, Polynomial& rhs, const char sign);
	
private:
	/*
	* Output �ڲ�ʹ�ú���
	*/
	static void printLine(char ch = '=', int width = WIDTH);
	static void displayPicture(int width = WIDTH);

	/*
	* Input �ڲ�ʹ�ú���
	*/
	bool stringToPolynomial(const std::string& polyStringOrKey, Polynomial& poly);
	static bool operationJudge(const std::string& content);
	static char getOperationSign(const std::string& content);
};
