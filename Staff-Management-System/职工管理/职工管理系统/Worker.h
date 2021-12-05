#pragma once
#include<iostream>
#include<string>
using namespace std;

class Worker//抽象类不实现，不用建立.cpp
{
public:
	//显示信息
	virtual void showinfo()=0;
	//获取岗位名称
	virtual string getdep()=0;
	int m_id;
	string m_name;
	int m_depid;
};