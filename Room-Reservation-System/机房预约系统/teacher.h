#pragma once//防止头文件重复包含
#include<iostream>
#include<string>
#include<vector>
#include"orderfile.h"
#include"identity.h"
using namespace std;

class Teacher:public Identity
{
public:
	//默认构造
	Teacher();

	//有参构造
	Teacher(int tid,string name,string password);

	//菜单编号
	virtual void opermeun();

	//查看所有预约
	void showallorder();

	//审核预约
	void validroder();

	//职工编号
	int m_tid;
};