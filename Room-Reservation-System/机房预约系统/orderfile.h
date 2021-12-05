#pragma once//防止头文件重复包含
#include<iostream>
#include<string>
#include<map>
#include<fstream>
#include"globafile.h"
using namespace std;

class OrderFile
{
public:
	//构造函数
	OrderFile();

	//更新预约信息
	void update();

	//记录预约条数
	int m_size;

	//记录所有信息的容器 key记录预约的条数 value记录具体键值对信息
	map<int,map<string,string>>mo;
};