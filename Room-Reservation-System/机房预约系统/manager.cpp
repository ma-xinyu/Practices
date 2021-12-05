#include"manager.h"

//默认构造
Manager::Manager()
{
}

//有参构造
Manager::Manager(string name,string password)
{
	//初始化管理员信息
	this->m_name=name;
	this->m_password=password;
	//初始化容器 并且获取到文件中学生和老师的信息
	this->initial();

	//初始化机房信息 因为在这里机房信息不变 所以直接写在这里
	//如果要改动机房信息 可另外提供接口
	ifstream ifs;
	ifs.open(computer_file,ios::in);

	ComputerRoom com;
	while(ifs>>com.m_cid && ifs>>com.m_max)
	{
		vc.push_back(com);
	}
	ifs.close();
	cout<<"机房的数量为："<<vc.size()<<endl;
}

//菜单界面
void Manager::opermeun()
{
	cout<<"欢迎管理员："<<this->m_name<<" 登陆！"<<endl;
	cout<<"\t\t -------------------------\n";
	cout<<"\t\t|                         |\n";
	cout<<"\t\t|       1.添加账号        |\n";
	cout<<"\t\t|                         |\n";
	cout<<"\t\t|       2.查看账号        |\n";
	cout<<"\t\t|                         |\n";
	cout<<"\t\t|       3.查看机房        |\n";
	cout<<"\t\t|                         |\n";
	cout<<"\t\t|       4.清空预约        |\n";
	cout<<"\t\t|                         |\n";
	cout<<"\t\t|       0.注销登陆        |\n";
	cout<<"\t\t|                         |\n";
	cout<<"\t\t -------------------------\n";
	cout<<"请选择您的操作："<<endl;
}

//添加账号
void Manager::addperson()
{
	cout<<"请输入添加账号的类型"<<endl;
	cout<<"1.添加学生"<<endl;
	cout<<"2.添加教师"<<endl;

	string filename;//操作文件名
	string tip;//提示id名

	string error;//错误重复提示

	ofstream ofs;//文件操作对象

	int select=0;
	cin>>select;//接受用户选项

	if(select==1)
	{
		//添加的是学生
		filename = student_file;
		tip = "请输入学号：";
		error = "学号重复，请重新输入";
	}
	else
	{
		//添加的是教师
		filename = teacher_file;
		tip = "请输入职工号：";
		error = "职工号重复，请重新输入";
	}

	//利用追加的方式 写文件
	ofs.open(filename,ios::out|ios::app);
	
	int id;//学号或职工号
	string name;//姓名
	string password;//密码

	while(true)
	{	
		cout<<tip<<endl;
		cin>>id;
		bool ret = check(id,select);//检测接口
		if(ret)//有重复
		{
			cout<<error<<endl;//重复执行 cin>>id 的操作
		}
		else
		{
			break;//跳出重复向下执行
		}
	}

	//cout<<tip<<endl;
	//cin>>id;
	cout<<"请输入姓名："<<endl;
	cin>>name;
	cout<<"请输入密码："<<endl;
	cin>>password;

	//向文件中添加数据
	ofs<<id<<" "<<name<<" "<<password<<" "<<endl;
	ofs.close();
	cout<<"添加成功！"<<endl;

	system("pause");
	system("cls");

	//初始化容器 及时更新文件信息
	this->initial();
}

void prints(Student &s)
{
	cout<<"学号："<<s.m_id<<" 姓名："<<s.m_name<<" 密码："<<s.m_password<<endl;
}
void printt(Teacher &t)
{
	cout<<"职工号："<<t.m_tid<<" 姓名："<<t.m_name<<" 密码："<<t.m_password<<endl;
}

//查看账号
void Manager::showperosn()
{
	cout<<"请选择查看的内容："<<endl;
	cout<<"1.查看所有学生"<<endl;
	cout<<"2.查看所有教师"<<endl;

	int select=0;
	cin>>select;

	if(select==1)
	{
		//查看学生
		cout<<"所有学生信息如下："<<endl;
		for_each(vs.begin(),vs.end(),prints);
	}
	else
	{
		//查看老师
		cout<<"所有老师信息如下："<<endl;
		for_each(vt.begin(),vt.end(),printt);
	}

	system("pause");
	system("cls");
}

//查看机房信息
void Manager::showcomputer()
{
	cout<<"机房信息如下："<<endl;
	for(vector<ComputerRoom>::iterator it=vc.begin();it!=vc.end();it++)
	{
		cout<<"机房编号："<<it->m_cid<<" 机房最大容量："<<it->m_max<<endl;
	}
	system("pause");
	system("cls");
}

//清空预约记录
void Manager::clean()
{
	ofstream ofs(order_file,ios::trunc);
	ofs.close();
	cout<<"清空成功！"<<endl;
	system("pause");
	system("cls");
}

//初始化容器
void Manager::initial()
{
	//清空容器
	vs.clear();
	vt.clear();

	//读取信息 学生
	ifstream ifs;
	ifs.open(student_file,ios::in);
	if(!ifs.is_open())
	{
		cout<<"读取文件失败"<<endl;
		return;
	}
	Student s;
	while(ifs>>s.m_id && ifs>>s.m_name && ifs>>s.m_password)
	{
		vs.push_back(s);
	}
	cout<<"当前学生数量为："<<vs.size()<<endl;;
	ifs.close();

	//读取信息 教师
	ifs.open(teacher_file,ios::in);
	if(!ifs.is_open())
	{
		cout<<"读取文件失败"<<endl;
		return;
	}
	Teacher t;
	while(ifs>>t.m_tid && ifs>>t.m_name && ifs>>t.m_password)
	{
		vt.push_back(t);
	}
	cout<<"当前教师数量为："<<vt.size()<<endl;;
	ifs.close();
}

//检测重复(在加入新人时检测) 参数1：学号/职工号 参数2：学生/老师
bool Manager::check(int id,int type)
{
	if(type==1)
	{
		//检测学生
		for(vector<Student>::iterator it=vs.begin();it!=vs.end();it++)
		{
			if(id==it->m_id)
			{
				return true;
			}
		}
	}
	else
	{
		//检测老师
		for(vector<Teacher>::iterator it=vt.begin();it!=vt.end();it++)
		{
			if(id==it->m_tid)
			{
				return true;
			}
		}
	}
	//无重复
	return false;
}