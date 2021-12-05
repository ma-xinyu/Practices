#pragma once
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<deque>
#include<functional>
#include<numeric>
#include<fstream>
#include<ctime>
#include"speaker.h"
using namespace std;

//设计演讲比赛管理类
class Manager
{
public:
	//构造函数
	Manager();

	//菜单界面
	void show_menu();

	//退出系统
	void exitsystem();

	//析构函数
	~Manager();


	//初始化容器和属性
	void initial();

	//创建12名选手
	void create();

	//开始比赛 比赛流程控制
	void start();

	//抽签
	void draw();

	//比赛
	void contest();

	//显示得分
	void showscore();

	//保存记录分数
	void save();

	//读取记录分数
	void load();
	//判断文件是否为空
	bool isempty;
	//存放往届记录的容器
	map<int,vector<string>>mr;

	//显示往届得分
	void showrecord();

	//清空记录
	void clear();

	//成员属性
	//保存第一轮比赛选手编号的容器
	vector<int>v1;
	//保存第一轮晋级选手编号的容器
	vector<int>v2;
	//胜出的三人编号的容器
	vector<int>v;
	//存放编号以及对应的选手容器
	map<int,Speaker>m;
	//存放比赛轮数
	int count;
};