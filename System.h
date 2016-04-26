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
	*              displayHead(...): 清屏, 并显示页面头部信息
	*       displayInstruction(...): 显示详细的命令语法
	* displaySimpleInstruction(...): 显示简单的命令语法
	*/
	void displayHead(const std::string message, bool showPoly = true, bool showLastLine = true, int width = WIDTH);
	static void displayInstruction(int width = WIDTH);
	static void displaySimpleInstruction(bool simplist = false, int width = WIDTH);

	/*
	* 取名为switcher, 意思是这个函数的功能就是跳转到各个模块的函数
	* 跳转函数, 根据instruction的值来处理读入的内容并输出结果
	*/
	void switcher(const std::string& instruction, const std::string& content);

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

	/*
	* 处理用函数
	*/
	void save(const std::string& address = "file/data.txt");
	void reload(const std::string& address = "file/data.txt");
	void clear();
	void push(const std::string& content, std::string& key, Polynomial& result);
	void remove(const std::string& content, std::string& key);
	void show(bool operationType, const std::string& content, std::string& key, Polynomial& result);
	void get(const std::string& content, std::string& key);
};
