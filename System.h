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
	*              displayHead(...): ����, ����ʾҳ��ͷ����Ϣ
	*       displayInstruction(...): ��ʾ��ϸ�������﷨
	* displaySimpleInstruction(...): ��ʾ�򵥵������﷨
	*/
	void displayHead(const std::string message, bool showPoly = true, bool showLastLine = true, int width = WIDTH);
	static void displayInstruction(int width = WIDTH);
	static void displaySimpleInstruction(bool simplist = false, int width = WIDTH);

	/*
	* ȡ��Ϊswitcher, ��˼����������Ĺ��ܾ�����ת������ģ��ĺ���
	* ��ת����, ����instruction��ֵ�������������ݲ�������
	*/
	void switcher(const std::string& instruction, const std::string& content);

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

	/*
	* �����ú���
	*/
	void save(const std::string& address = "file/data.txt");
	void reload(const std::string& address = "file/data.txt");
	void clear();
	void push(const std::string& content, std::string& key, Polynomial& result);
	void remove(const std::string& content, std::string& key);
	void show(bool operationType, const std::string& content, std::string& key, Polynomial& result);
	void get(const std::string& content, std::string& key);
};
