#pragma once
#include <cstdlib>
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

	/*
	* IO部分:
	*    displayHead: 展现屏幕顶部的字符画与文字
	* getValidNumber: 在区间[lowerBound, upperBound]内得到一个合法数字
	*/
	static void displayHead(const std::string message, 
		bool showLastLine, bool showFunction = false, 
		int width = WIDTH);
	static int getValidNumber(const int lowerBound, const int upperBound);

	/*
	* 模块功能函数:
	* displayStoragedPolyDictionary: 展示存储的多项式模块
	*                  addOperation: 算术运算 - 加法
	*
	*/
	void displayStoragedPolyDictionary();
	void addOperation() const;
	
	
private:
	static void printLine(char ch = '=', int width = WIDTH);
	static void displayFunction(int width = WIDTH);
	static void displayPicture(int width = WIDTH);
};
