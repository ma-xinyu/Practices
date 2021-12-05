#pragma once//防止头文件重复包含
#include<iostream>//包含输入输出流头文件
#include<fstream>
#include"Worker.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"
using namespace std;//使用标准命名空间
#define filename "file.txt"

class WorkManager
{
public:
	//构造函数
	WorkManager();
	//功能：展示菜单
	void show_Menu();
	//功能：退出系统
	void Exit();
	//记录职工人数
	int m_num;
	//职工数组指针
	Worker ** m_Array;//父类指针的指针
	//添加职工
	void add_Num();
	//保存文件
	void save();
	//判断文件是否为空的标志
	bool m_fileEmpty;
	//统计人数
	int get_num();
	//初始化员工
	void initial();
	//显示职工的成员函数
	void show();
	//判断是否有这个职工 如果存在返回职工在数组中的位置，不存在返回-1
	int isexist(int id);
	//删除职工
	void del();
	//修改职工
	void change();
	//查找职工
	void find();
	//排序功能
	void sort();
	//清空文件
	void clean();
	//析构函数
	~WorkManager();//只写声明，不写实现
};