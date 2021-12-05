#include<iostream>
#include<string>
#include<fstream>
#include"globafile.h"
#include"identity.h"
using namespace std;
#include"student.h"
#include"teacher.h"
#include"manager.h"

//进入管理员的子菜单
void managermenu(Identity * &manager)//父类指针类型传进来
{
	while(1)
	{
		//调用管理员的子菜单
		manager->opermeun();

		//将父类指针 转为子类的指针，代用子类中其他特有的接口
		Manager * man = (Manager*)manager;

		int select=0;
		//接受用户的选择
		cin>>select;
		if(select==1)//添加账号
		{
			//cout<<"添加账号"<<endl;
			man->addperson();
		}
		else if(select==2)//查看账号
		{
			//cout<<"查看账号"<<endl;
			man->showperosn();
		}
		else if(select==3)//查看机房
		{
			//cout<<"查看机房"<<endl;
			man->showcomputer();
		}
		else if(select==4)//清空预约
		{
			//cout<<"清空预约"<<endl;
			man->clean();
		}
		else
		{
			delete manager;//销毁堆区对象
			cout<<"注销成功"<<endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//进入学生的子菜单
void studentmenu(Identity * &student)//父类指针类型传进来
{
	while(1)
	{
		//调用学生的子菜单
		student->opermeun();

		//将父类指针 转为子类的指针，代用子类中其他特有的接口
		Student * stu = (Student*)student;

		int select=0;
		//接受用户的选择
		cin>>select;
		if(select==1)//申请预约
		{
			//cout<<"申请预约"<<endl;
			stu->applyorder();
		}
		else if(select==2)//查看自身预约
		{
			//cout<<"查看自身预约"<<endl;
			stu->showmyorder();
		}
		else if(select==3)//查看所有预约
		{
			//cout<<"查看所有预约"<<endl;
			stu->showallroder();
		}
		else if(select==4)//取消预约
		{
			//cout<<"取消预约"<<endl;
			stu->cancel();
		}
		else
		{
			delete student;//销毁堆区对象
			cout<<"注销成功"<<endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//进入教师的子菜单
void Teachermenu(Identity * &teacher)//父类指针类型传进来
{
	while(1)
	{
		//调用教师的子菜单
		teacher->opermeun();

		//将父类指针 转为子类的指针，代用子类中其他特有的接口
		Teacher * tea = (Teacher*)teacher;

		int select=0;
		//接受用户的选择
		cin>>select;
		if(select==1)//查看所有预约
		{
			//cout<<"查看所有预约"<<endl;
			tea->showallorder();
		}
		else if(select==2)//审核预约
		{
			//cout<<"审核预约"<<endl;
			tea->validroder();
		}
		else
		{
			delete teacher;//销毁堆区对象
			cout<<"注销成功"<<endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//登陆功能  操作数1：操作文件名  操作数2：操作身份类型
void loginin(string filename,int type)
{
	//父类指针 指向子类对象
	Identity * person = NULL;

	//读文件
	ifstream ifs;
	ifs.open(filename,ios::in);

	//判断文件是否存在
	if(!ifs.is_open())
	{
		cout<<"文件不存在"<<endl;
		ifs.close();
		return;
	}

	//准备接受用户的信息
	int id=0;
	string name;
	string password;

	//判断身份
	if(type==1)//学生
	{
		cout<<"请输入你的学号："<<endl;
		cin>>id;
	}
	else if(type==2)
	{
		cout<<"请输入您的职工号："<<endl;
		cin>>id;
	}
	cout<<"请输入用户名："<<endl;
	cin>>name;
	cout<<"请输入密码："<<endl;
	cin>>password;

	if(type==1)
	{
		//学生身份验证
		int fid;//从文件读取的id号
		string fname;//从文件读取的姓名
		string fpassword;//从文件读取的密码
		while(ifs>>fid && ifs>>fname && ifs>>fpassword)
		{
			//与用户的做对比
			if(fid==id && fname==name && fpassword==password)
			{
				cout<<"学生验证登陆成功！"<<endl;
				system("pause");
				system("cls");
				//创建学生对象
				person = new Student(id,name,password);
				//进入学生身份的子菜单
				studentmenu(person);

				return;
			}
		}
	}
	else if(type==2)
	{
		//教师身份验证
		int fid;//从文件读取的id号
		string fname;//从文件读取的姓名
		string fpassword;//从文件读取的密码
		while(ifs>>fid && ifs>>fname && ifs>>fpassword)
		{
			//与用户的做对比
			if(fid==id && fname==name && fpassword==password)
			{
				cout<<"教师验证登陆成功！"<<endl;
				system("pause");
				system("cls");
				//创建教师对象
				person = new Teacher(id,name,password);
				//进入教师身份的子菜单
				Teachermenu(person);

				return;
			}
		}
	}
	else if(type==3)
	{
		//管理员身份验证
		string fname;//从文件读取的姓名
		string fpassword;//从文件读取的密码
		while(ifs>>fname && ifs>>fpassword)
		{
			//与用户的做对比
			if(fname==name && fpassword==password)
			{
				cout<<"管理员验证登陆成功！"<<endl;
				system("pause");
				system("cls");
				//创建管理员对象
				person = new Manager(name,password);
				//进入管理员身份的子菜单
				managermenu(person);

				return;
			}
		}

	}
	//都不是
	cout<<"验证登陆失败！"<<endl;
	system("pause");
	system("cls");
	return;
}

int main()
{
	int select=0;
	while(1)
	{
		cout<<"----------------欢迎来到Martin的机房预约系统----------------"<<endl;
		cout<<endl;
		cout<<"请输入您的身份"<<endl;
		cout<<"\t\t -------------------------\n";
		cout<<"\t\t|                         |\n";
		cout<<"\t\t|       1.学生代表        |\n";
		cout<<"\t\t|                         |\n";
		cout<<"\t\t|       2.老    师        |\n";
		cout<<"\t\t|                         |\n";
		cout<<"\t\t|       3.管 理 员        |\n";
		cout<<"\t\t|                         |\n";
		cout<<"\t\t|       0.退    出        |\n";
		cout<<"\t\t|                         |\n";
		cout<<"\t\t -------------------------\n";
		cout<<"输入您的选择："<<endl;
		cin>>select;

		switch(select)
		{
		case 1://学生
			loginin(student_file,1);
			break;
		case 2://老师
			loginin(teacher_file,2);
			break;
		case 3://管理员
			loginin(admin_file,3);
			break;
		case 0://退出系统
			cout<<"欢迎下一次使用"<<endl;
			//system("pause");
			return 0;
			break;
		default:
			cout<<"输入有误，请重新选择！"<<endl;
			system("pause");
			system("cls");
			break;
		}
	}

	system("pause");
	return 0;
}