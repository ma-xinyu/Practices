#pragma once//防止头文件重复包含
#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include"student.h"
#include"teacher.h"
#include"computerRoom.h"
#include"identity.h"
#include"globafile.h"
#include<algorithm>
using namespace std;

class Manager:public Identity
{
public:
	//默认构造
	Manager();

	//有参构造
	Manager(string name,string password);

	//菜单界面
	virtual void opermeun();

	//添加账号
	void addperson();

	//查看账号
	void showperosn();

	//查看机房信息
	void showcomputer();

	//清空预约记录
	void clean();

	//去重
	//初始化容器
	void initial();

	//检测重复 参数1：学号/职工号 参数2：学生/老师
	bool check(int id,int type);

	//学生容器
	vector<Student>vs;

	//教师容器
	vector<Teacher>vt;

	//机房容器
	vector<ComputerRoom>vc;
};