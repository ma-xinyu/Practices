#include"student.h"

//默认构造
Student::Student()
{
}

//有参构造 参数：学号、姓名、密码
Student::Student(int id,string name,string password)
{
	//初始化属性
	this->m_id=id;
	this->m_name=name;
	this->m_password=password;

	//初始化机房信息
	ifstream ifs;
	ifs.open(computer_file,ios::in);
	ComputerRoom com;
	while(ifs>>com.m_cid && ifs>>com.m_max)
	{
		//将机房信息放到 容器中
		vc.push_back(com);
	}
	ifs.close();
}

//菜单构造
void Student::opermeun()
{
	cout<<"欢迎学生："<<this->m_name<<" 登陆！"<<endl;
	cout<<"\t\t -------------------------\n";
	cout<<"\t\t|                         |\n";
	cout<<"\t\t|       1.申请预约        |\n";
	cout<<"\t\t|                         |\n";
	cout<<"\t\t|       2.查看我的预约    |\n";
	cout<<"\t\t|                         |\n";
	cout<<"\t\t|       3.查看所有预约    |\n";
	cout<<"\t\t|                         |\n";
	cout<<"\t\t|       4.取消预约        |\n";
	cout<<"\t\t|                         |\n";
	cout<<"\t\t|       0.注销登陆        |\n";
	cout<<"\t\t|                         |\n";
	cout<<"\t\t -------------------------\n";
	cout<<"请选择您的操作："<<endl;
}

//申请预约
void Student::applyorder()
{
	cout<<"机房开放时间为周一至周五！"<<endl;
	int date=0;//星期
	int interval=0;//上午/下午
	int room=0;//机房编号

	//星期
	cout<<"请输入申请预约的时间："<<endl;
	cout<<"1.周一"<<endl;
	cout<<"2.周二"<<endl;
	cout<<"3.周三"<<endl;
	cout<<"4.周四"<<endl;
	cout<<"5.周五"<<endl;
	while(1)
	{
		cin>>date;
		if(date>=1 && date<=5)
		{
			break;
		}
		cout<<"输入有误，请重新输入！"<<endl;
	}

	//时间段
	cout<<"请输入申请预约时间段："<<endl;
	cout<<"1.上午"<<endl;
	cout<<"2.下午"<<endl;
	while(1)
	{
		cin>>interval;
		if(interval>=1 && interval<=2)
		{
			break;
		}
		cout<<"输入有误，请重新输入！"<<endl;
	}

	//机房信息
	cout<<"请选择机房："<<endl;
	for(int i=0;i<vc.size();i++)
	{
		cout<<vc[i].m_cid<<"号机房容量为："<<vc[i].m_max<<endl;
	}
	//cout<<vc[0].m_cid<<""<<vc[0].m_max<<endl;
	while(1)
	{
		cin>>room;
		if(room>=1 && room<=3)
		{
			break;
		}
		cout<<"输入有误，请重新输入！"<<endl;
	}

	cout<<"预约成功！审核中"<<endl;

	//写入 order
	ofstream ofs;
	ofs.open(order_file,ios::app);//追加
	ofs<<"date:"<<date<<" ";
	ofs<<"interval:"<<interval<<" ";
	ofs<<"stuid:"<<this->m_id<<" ";
	ofs<<"stuname:"<<this->m_name<<" ";
	ofs<<"roomid:"<<room<<" ";
	ofs<<"status:"<<1<<endl;
	ofs.close();

	system("pause");
	system("cls");
}

//查看自己的预约
void Student::showmyorder()
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
		//string 转 int
		//string 利用 .c_str() 转 const char *
		//利用 atoi(const char * )转 int
		if(atoi(of.mo[i]["stuid"].c_str()) == this->m_id)//整型之间的对比
		{
			cout<<"预约时间：周"<<of.mo[i]["date"]<<" ";
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
	}
	system("pause");
	system("cls");
}

//查看所有预约
void Student::showallroder()
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

//取消预约
void Student::cancel()
{
	OrderFile of;
	if(of.m_size==0)
	{
		cout<<"无预约"<<endl;
		system("pause");
		system("cls");
		return;
	}

	cout<<"审核中或预约成功的预约可以取消，请输入要取消的预约记录"<<endl;
	vector<int>v;//存放在最大容器中的预约的编号
	int index=1;
	for(int i=0;i<of.m_size;i++)
	{
		//先判断是自己的预约
		if(atoi(of.mo[i]["stuid"].c_str()) == this->m_id)
		{
			//再筛选状态 审核中或预约成功的
			if(of.mo[i]["status"]=="1"||of.mo[i]["status"]=="2")
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
				else if(of.mo[i]["status"]=="2")
				{
					status += "预约成功";
				}
				cout<<status<<endl;
			}
		}
	}

	cout<<"请输入要取消的记录，0表示返回"<<endl;
	int select = 0;
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
				of.mo[v[select-1]]["status"] = "0";
				//更新
				of.update();
				cout<<"已取消预约"<<endl;
				break;
			}
		}
		cout<<"输入有误，请重新输入"<<endl;
	}
	system("pause");
	system("cls");
}