#include"teacher.h"	

//默认构造
Teacher::Teacher()
{
}

//有参构造
Teacher::Teacher(int tid,string name,string password)
{
	//初始化属性
	this->m_tid=tid;
	this->m_name=name;
	this->m_password=password;
}

//菜单编号
void Teacher::opermeun()
{
	cout<<"欢迎教师："<<this->m_name<<" 登陆！"<<endl;
	cout<<"\t\t -------------------------\n";
	cout<<"\t\t|                         |\n";
	cout<<"\t\t|       1.查看所有预约    |\n";
	cout<<"\t\t|                         |\n";
	cout<<"\t\t|       2.审核预约        |\n";
	cout<<"\t\t|                         |\n";
	cout<<"\t\t|       0.注销登陆        |\n";
	cout<<"\t\t|                         |\n";
	cout<<"\t\t -------------------------\n";
	cout<<"请选择您的操作："<<endl;
}

//查看所有预约
void Teacher::showallorder()
{
	OrderFile of;
	if(of.m_size==0)
	{
		cout<<"无预约"<<endl;
		system("pause");
		system("cls");
		return;
	}

	for(int i=0;i<of.m_size;i++)
	{
		cout<<i+1<<"、";
		cout<<"预约时间：周"<<of.mo[i]["date"]<<" ";
		cout<<"学号："<<of.mo[i]["stuid"]<<" ";
		cout<<"姓名："<<of.mo[i]["stuname"]<<" ";
		cout<<"时间段："<<(of.mo[i]["interval"]=="1" ? "上午":"下午")<<" ";
		cout<<"机房号："<<of.mo[i]["roomid"]<<" ";
		string status="预约状态：";
		//1.审核中 2.已预约 -1.预约失败 0.取消预约
		if(of.mo[i]["status"]=="1")
		{
			status += "审核中";
		}
		else if(of.mo[i]["status"]=="2")
		{
			status += "预约成功";
		}
		else if(of.mo[i]["status"]=="-1")
		{
			status += "预约失败，审核未通过";
		}
		else
		{
			status +="预约已取消";
		}
		cout<<status<<endl;
	}
	system("pause");
	system("cls");
}

//审核预约
void Teacher::validroder()
{
	OrderFile of;
	if(of.m_size==0)
	{
		cout<<"无预约"<<endl;
		system("pause");
		system("cls");
		return;
	}

	cout<<"待审核的预约记录如下："<<endl;
	vector<int>v;//存放在最大容器中的预约的编号
	int index=1;
	for(int i=0;i<of.m_size;i++)
	{
			//筛选状态 审核中的
			if(of.mo[i]["status"]=="1")
			{
				v.push_back(i);
				cout<<index++<<"、";
				cout<<"预约时间：周"<<of.mo[i]["date"]<<" ";
				cout<<"时间段："<<(of.mo[i]["interval"]=="1" ? "上午":"下午")<<" ";
				cout<<"机房号："<<of.mo[i]["roomid"]<<" ";
				string status="预约状态：";
				//1.审核中 2.已预约 -1.预约失败 0.取消预约
				if(of.mo[i]["status"]=="1")
				{
					status += "审核中";
				}
				cout<<status<<endl;
			}
	}

	cout<<"请输入审核的预约记录，0表示返回"<<endl;
	int select = 0;//接受用户选择的预约记录
	int ret = 0;//接受预约结果记录
	while(true)
	{
		cin>>select;
		if(select >= 0 && select <= v.size())
		{
			if(select == 0)
			{
				break;
			}
			else
			{
				cout<<"请输入审核结果"<<endl;
				cout<<"1.通过"<<endl;
				cout<<"2.不通过"<<endl;
				cin>>ret;
				if(ret==1)
				{
					//通过
					of.mo[v[select-1]]["status"] = "2";
				}
				else
				{
					//不通过
					of.mo[v[select-1]]["status"] = "-1";
				}
				//更新
				of.update();
				cout<<"已审核完毕！"<<endl;
				break;
			}
		}
		cout<<"输入有误，请重新输入"<<endl;
	}
	system("pause");
	system("cls");
}