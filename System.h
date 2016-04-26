#pragma once
#include <cstdlib>
#include <sstream>
#include "PolyDictionary.h"
#define WIDTH 70
class System :public PolyDictionary
{
public:
	/*
	* 构造, 析构函数
	*/
	System();
	~System();

	/* ==============================
	*           输入输出部分
	*  ==============================*/
	/*
	* Output:
	*        displayHead(...): 清屏, 并显示页面头部信息
	* displayInstruction(...): 显示命令语法
	*/
	void displayHead(const std::string message, bool showPoly = true, bool showLastLine = true, int width = WIDTH);
	static void displayInstruction(int width = WIDTH);

	/*
	* 处理函数, 根据instruction的值来处理读入的内容并输出结果
	*/
	void instructionSwitcher(const std::string& instruction, const std::string& content);

	/*
	* Input:
	*      inputOrder(...): 从一整行命令语句中读入指令和指令的内容
	*    inputContent(...): 根据指令的内容读取相关信息, 有三个重载函数
	*              重载(1): 读取形式 {key}:{Polymial}, key可选
	*              重载(2): 读取形式 {key}
	*              重载(3): 读取形式 {key}:{Polymial}{Sign}{Polymial}, key可选
	*/
	bool inputOrder(const std::string& order, std::string& instruction, std::string& content) const;
	bool inputContent(const std::string& content, std::string& key, Polynomial& poly, const char sign = '!', bool keyNeeded = true);
	bool inputContent(const std::string& content, std::string& key) const;
	bool inputContent(const std::string& content, std::string& key, Polynomial& lhs, Polynomial& rhs, const char sign);
	
private:
	/*
	* Output 内部使用函数
	*/
	static void printLine(char ch = '=', int width = WIDTH);
	static void displayPicture(int width = WIDTH);

	/*
	* Input 内部使用函数
	*/
	bool stringToPolynomial(const std::string& polyStringOrKey, Polynomial& poly);
	static bool operationJudge(const std::string& content);
	static char getOperationSign(const std::string& content);
};
