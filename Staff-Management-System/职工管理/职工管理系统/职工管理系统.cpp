#include<iostream>
#include"WorkManager.h"
#include"Worker.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"
using namespace std;

int main()
{
	//����
	//Worker * worker = NULL;

	//worker = new Employee(1,"����",0);
	//worker->showinfo();
	//delete worker;

	//worker = new Manager(2,"����",0);
	//worker->showinfo();
	//delete worker;

	//worker = new Boss(3,"����",0);
	//worker->showinfo();
	//delete worker;


	//ʵ���������ߵĶ���
	WorkManager wm;
	int choice=-1;//switch ѡ��ϵͳ����
	while (true)
	{
	    //���ó�Ա����(���ܣ�չʾ�˵�)
		wm.show_Menu();
		cout<<"�������ѡ��"<<endl;
		cin>>choice;
		switch(choice)
		{
		case 0://�˳�ϵͳ
			wm.Exit();
			break;
		case 1://����ְ��
			wm.add_Num();
			break;
		case 2://��ʾְ��
			wm.show();
			break;
		case 3://ɾ��ְ��
			wm.del();
			break;
		case 4://�޸�ְ��
			wm.change();
			break;
		case 5://����ְ��
			wm.find();
			break;
		case 6://ְ������
			wm.sort();
			break;
		case 7://��յ���
			wm.clean();
			break;
		default://���ڷ�Χ��
			system("cls");//�������
			break;
		}
	}

	system("pause");
	return 0;
}

//����
//{{int ret=wm.isexist(2);
//if(ret!=-1)
//{
//	cout<<"ְ������"<<endl;
//}
//else
//{
//	cout<<"ְ��������"<<endl;
//}}