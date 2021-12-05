/*12人参加 比赛分两轮 第一轮为淘汰赛，第二轮为决赛
每个选手有编号 如10001-10012
比赛方式：分组比赛，每组6人
第一轮分为两个小组 抽签分组
十个评委打分 去除最高和最低 求平均值
淘汰组内后三名 前三名晋级
第二轮为决赛 前三名为胜者
每轮比赛过后都要显示晋级选手的信息*/

/*开始演讲比赛：完成整个比赛的流程，每个比赛阶段都要给用户一个提示，用户按任意键继续下个阶段
查看往届记录：查看之前比赛的前三名，每次比赛都会记录到文件中，文件用.csv后缀名保存
清空比赛记录：将文件中数据清空
退出比赛程序：可以退出当前程序*/

#include<iostream>
#include"演讲管理.h"
using namespace std;

int main()
{
	//随机数种子
	srand((unsigned int)time(NULL));
	
	//创建管理类对象
	Manager sm;

	int choice=0;//存储用户的选择
	while(1)
	{
		sm.show_menu();
		cout<<"输入您的选择："<<endl;
		cin>>choice;
		switch(choice)
		{
		case 1://开始比赛
			sm.start();
			break;
		case 2://查看记录
			sm.showrecord();
			break;
		case 3://清空记录
			sm.clear();
			break;
		case 0://退出系统
			sm.exitsystem();
			break;
		default:
			system("cls");
			break;
		}
	}
	system("pause");
	return 0;
}

	////测试12名选手的创建
	//for(map<int,Speaker>::iterator it=sm.m.begin();it!=sm.m.end();it++)
	//{
	//	cout<<"选手编号："<<it->first<<" 姓名："<<it->second.m_name<<" 成绩："<<it->second.m_score[0]<<endl;
	//}