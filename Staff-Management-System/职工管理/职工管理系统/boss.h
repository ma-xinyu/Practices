//老板文件
#pragma once
#include<iostream>
#include"Worker.h"
using namespace std;
class Boss : public Worker
{
public:
	Boss(int id,string name,int depid);
	//显示信息
	virtual void showinfo();
	//获取岗位名称
	virtual string getdep();
};