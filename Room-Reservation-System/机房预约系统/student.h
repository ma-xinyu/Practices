#pragma once//防止头文件重复包含
#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include"globafile.h"
#include"computerRoom.h"
#include"identity.h"
#include"orderfile.h"
using namespace std;

class Student:public Identity
{
public:
	//默认构造
	Student();

	//有参构造 参数：学号、姓名、密码
	Student(int id,string name,string password);

	//菜单构造
	virtual void opermeun();

	//申请预约
	void applyorder();

	//查看自己的预约
	void showmyorder();

	//查看所有预约
	void showallroder();

	//取消预约
	void cancel();

	//学生学号
	int m_id;

	//机房容量
	vector<ComputerRoom>vc;
};