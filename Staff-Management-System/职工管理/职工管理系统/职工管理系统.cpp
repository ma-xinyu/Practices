#include<iostream>
#include"WorkManager.h"
#include"Worker.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"
using namespace std;

int main()
{
	//测试
	//Worker * worker = NULL;

	//worker = new Employee(1,"张三",0);
	//worker->showinfo();
	//delete worker;

	//worker = new Manager(2,"李四",0);
	//worker->showinfo();
	//delete worker;

	//worker = new Boss(3,"王五",0);
	//worker->showinfo();
	//delete worker;


	//实例化管理者的对象
	WorkManager wm;
	int choice=-1;//switch 选择系统功能
	while (true)
	{
	    //调用成员函数(功能：展示菜单)
		wm.show_Menu();
		cout<<"输入你的选择"<<endl;
		cin>>choice;
		switch(choice)
		{
		case 0://退出系统
			wm.Exit();
			break;
		case 1://增加职工
			wm.add_Num();
			break;
		case 2://显示职工
			wm.show();
			break;
		case 3://删除职工
			wm.del();
			break;
		case 4://修改职工
			wm.change();
			break;
		case 5://查找职工
			wm.find();
			break;
		case 6://职工排序
			wm.sort();
			break;
		case 7://清空档案
			wm.clean();
			break;
		default://不在范围内
			system("cls");//清零操作
			break;
		}
	}

	system("pause");
	return 0;
}

//测试
//{{int ret=wm.isexist(2);
//if(ret!=-1)
//{
//	cout<<"职工存在"<<endl;
//}
//else
//{
//	cout<<"职工不存在"<<endl;
//}}