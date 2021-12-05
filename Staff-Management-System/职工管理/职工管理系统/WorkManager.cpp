#include"WorkManager.h"

WorkManager::WorkManager()
{
	//1.文件不存在
	ifstream ifs;
	ifs.open(filename,ios::in);//读文件
	if(!ifs.is_open())
	{
		cout<<"文件不存在!"<<endl;
		//空文件 初始化属性
		this->m_num=0;
		this->m_Array=NULL;
		this->m_fileEmpty=true;//文件是空的
		ifs.close();
		return;
	}
	//2.文件存在，但是为空
	char ch;
	ifs >> ch;
	if(ifs.eof())//读到文件尾
	{
		cout<<"文件为空!"<<endl;
		//空文件 初始化属性
		this->m_num=0;
		this->m_Array=NULL;
		this->m_fileEmpty=true;//文件是空的
		ifs.close();
		return;
	}
	//3.文件存在，且有数据
	this->m_fileEmpty=false;
	int num=this->get_num();
	cout<<"职工的人数为："<<num<<endl;
	this->m_num = num;
	//开辟空间
	this->m_Array = new Worker * [this->m_num];
	//将文件中的数据存到数组中
	this->initial();
	//测试
	//for(int i=0;i<this->m_num;i++)
	//{
	//	cout<<"职工编号："<<this->m_Array[i]->m_id
	//		<<"姓名："<<this->m_Array[i]->m_name
	//		<<"岗位编号："<<this->m_Array[i]->m_depid<<endl;
	//}
}
//展示菜单
void WorkManager::show_Menu()
{
	cout<<"*************************************"<<endl;
	cout<<"******* 欢迎使用职工管理系统！*******"<<endl;
	cout<<"********** 0.退出管理系统 ***********"<<endl;
	cout<<"********** 1.增加职工信息 ***********"<<endl;
	cout<<"********** 2.显示职工信息 ***********"<<endl;
	cout<<"********** 3.删除离职职工 ***********"<<endl;
	cout<<"********** 4.修改职工信息 ***********"<<endl;
	cout<<"********** 5.查找职工信息 ***********"<<endl;
	cout<<"********** 6.按照编号排序 ***********"<<endl;
	cout<<"********** 7.清空所有档案 ***********"<<endl;
	cout<<endl;
}

//退出系统
void WorkManager::Exit()
{
	cout<<"Byebye! Welcome to use the system again!"<<endl;
	system("pause");
	exit(0);//一旦调用exit,会直接退出程序(直接退出循环，结束程序)
}

//添加员工
void WorkManager::add_Num()
{
	cout<<"输入添加职工数量"<<endl;
	int addnum=0;
	cin>>addnum;
	if(addnum>0)
	{
		//添加 计算添加的新空间大小
		int newsize = this->m_num+addnum;
		//开辟新空间
		Worker ** newspace = new Worker * [newsize];
		//将原来的数据拷贝到新空间下
		if (this->m_num!=NULL)
		{
			for (int i=0;i<m_num;i++)//i<this->m_num
			{
				newspace[i]=this->m_Array[i];
			}
		}
		//批量添加新数据
		for (int i=0;i<addnum;i++)
		{
			int id;
			string name;
			int depselect;
			cout<<"请输入第"<<i+1<<"个新职工的编号："<<endl;
			cin>>id;
			cout<<"请输入第"<<i+1<<"个新职工的姓名："<<endl;
			cin>>name;
			cout<<"请输入第"<<i+1<<"个新职工的岗位："<<endl;
			cout<<"请选择该职工岗位："<<endl;
			cout<<"1.普通员工"<<endl;
			cout<<"2.经理"<<endl;
			cout<<"3.老板"<<endl;
			cin>>depselect;

			Worker * worker = NULL;
			switch(depselect)
			{
			case 1:
				worker = new Employee(id,name,1);
				break;
			case 2:
				worker = new Manager(id,name,2);
				break;
			case 3:
				worker = new Boss(id,name,3);
				break;
			default:
				break;
			}
			//将创建的职工指针，保存到数组中
			newspace[this->m_num+i] = worker;
		}
		//释放原来的堆区空间
		delete[]this->m_Array;
		//替换新空间的指向
		this->m_Array=newspace;
		//更新人数
		this->m_num=newsize;
		//更新文件不为空标志
		this->m_fileEmpty=false;
		//提示添加成功
		cout<<"成功添加"<<addnum<<"名新员工"<<endl;

		this->save();//保存数据到文件中
	}
	else
	{
		cout<<"Date error"<<endl;
	}
	//完善界面
	system("pause");
	system("cls");
}

//保存文件
void WorkManager::save()
{
	ofstream ofs;
	ofs.open(filename,ios::out);//写文件
	//数据写入文件
	for(int i=0;i<this->m_num;i++)
	{//类似cout<<...
		ofs<<this->m_Array[i]->m_id<<" "
			<<this->m_Array[i]->m_name<<" "
			<<this->m_Array[i]->m_depid<<endl;
	}
	//关闭文件
	ofs.close();
}

//统计人数
int WorkManager::get_num()
{
	ifstream ifs;
	ifs.open(filename,ios::in);//打开文件 读文件
	int id;
	string name;
	int desid;
	int num=0;
	while(ifs>>id && ifs>>name && ifs>>desid)
	{
		num++;
	}
	return num;
}

//初始化员工
void WorkManager::initial()
{
	ifstream ifs;
	ifs.open(filename,ios::in);
	int id;
	string name;
	int desid;

	int index=0;
	while(ifs>>id && ifs>>name && ifs>>desid)
	{
		Worker * worker = NULL;
		if(desid==1)
		{
			worker = new Employee(id,name,desid);
		}
		else if(desid==2)
		{
			worker = new Manager(id,name,desid);
		}
		else if(desid==3)
		{
			worker = new Boss(id,name,desid);
		}
		this->m_Array[index]=worker;
		index++;
	}
	ifs.close();
}

//显示职工的成员函数
void WorkManager::show()
{
	//判断文件是否为空
	if(this->m_fileEmpty)
	{
		cout<<"文件不存在或文件为空！"<<endl;
	}
	else 
	{
		for(int i=0;i<this->m_num;i++)
		{
			//利用多态调用程序接口
			this->m_Array[i]->showinfo();
		}
	}
	system("pause");
	system("cls");
}

//判断是否有这个职工 如果存在返回职工在数组中的位置，不存在返回-1
int WorkManager::isexist(int id)
{
	int index=-1;
	for(int i=0;i<this->m_num;i++)
	{
		if(this->m_Array[i]->m_id==id)
		{
			index=i;
			break;
		}
	}
	return index;
}

//删除职工
void WorkManager::del()
{
	//判断文件是否为空
	if(this->m_fileEmpty)
	{
		cout<<"文件不存在或文件为空！"<<endl;
	}
	else
	{
		cout<<"输入要删除的员工的编号："<<endl;
		int id;
		cin>>id;
		int index=this->isexist(id);//判断是否存在
		if(index!=-1)
		{
			cout<<"找到员工信息"<<endl;
			//数据前移
			for(int i=index;i<this->m_num-1;i++)
			{
				this->m_Array[i] = this->m_Array[i+1];
			}
			this->m_num--;
			//同步更新到文件中
			this->save();
			cout<<"删除成功！"<<endl;
		}
		else
		{
			cout<<"此员工不存在 删除失败"<<endl;
		}
	}
	system("pause");
	system("cls");
}

//修改职工
void WorkManager::change()
{
	//判断文件是否为空
	if(this->m_fileEmpty)
	{
		cout<<"文件不存在或文件为空！"<<endl;
	}
	else
	{
		cout<<"请输入修改职工的编号："<<endl;
		int id;
		cin>>id;

		int index=this->isexist(id);//判断是否存在
		if(index!=-1)
		{
			delete this->m_Array[index];
			int newid=0;
			string newname="";
			int newdesid=0;

			cout<<"查到"<<id<<"号员工，请输入新的编号："<<endl;
			cin>>newid;
			cout<<"请输入新的员工姓名："<<endl;
			cin>>newname;
			cout<<"请输入新的岗位："<<endl;
			cout<<"1.普通员工"<<endl;
			cout<<"2.经理"<<endl;
			cout<<"3.老板"<<endl;
			cin>>newdesid;

			Worker * worker = NULL;
			switch(newdesid)
			{
			case 1:
				worker = new Employee(newid,newname,newdesid);
				break;
			case 2:
				worker = new Manager(newid,newname,newdesid);
				break;
			case 3:
				worker = new Boss(newid,newname,newdesid);
				break;
			default:
				break;
			}

			//更新数据到数组中
			this->m_Array[index]=worker;
			cout<<"修改成功！"<<endl;
			//同步更新到文件中
			this->save();
		}
		else
		{
			cout<<"此员工不存在 删除失败"<<endl;
		}
	}
	system("pause");
	system("cls");
}

//查找职工
void WorkManager::find()
{
	if(this->m_fileEmpty)
	{
		cout<<"文件不存在或文件为空！"<<endl;
	}
	else
	{
		cout<<"请输入查找的方式："<<endl;
		cout<<"1.按职工编号查找"<<endl;
		cout<<"2.按职工姓名查找"<<endl;

		int select=0;
		cin>>select;
		if (select==1)
		{
			int id;
			cout<<"输入要查找的员工的编号："<<endl;
			cin>>id;
			int index=this->isexist(id);//判断是否存在
			if(index!=-1)
			{
				cout<<"找到职工！该职工的信息如下："<<endl;
				this->m_Array[index]->showinfo();
			}
			else
			{
				cout<<"此员工不存在"<<endl;
			}
		}
		else if (select==2)
		{
			string name;
			cout<<"输入要查找的员工的姓名："<<endl;
			cin>>name;
			//是否查到的标志
			bool flag=false;

			for(int i=0;i<m_num;i++)
			{
				if(this->m_Array[i]->m_name==name)
				{
					cout<<"查找成功，职工的编号为:"
						<<this->m_Array[i]->m_id<<'\t'
						<<this->m_Array[i]->m_id
						<<"号职工的信息如下："<<endl;
					this->m_Array[i]->showinfo();
					flag=true;
				}
			}
			if(flag==false)
			{
				cout<<"此员工不存在"<<endl;
			}
			cout<<""<<endl;
		}
		else 
		{
			cout<<"输入错误!";
		}
	}
	system("pause");
	system("cls");
}

//排序功能
void WorkManager::sort()
{
	if(this->m_fileEmpty)
	{
		cout<<"文件不存在或文件为空！"<<endl;
		system("pause");
	    system("cls");
	}
	else
	{
		cout<<"请选择排序方式"<<endl;
		cout<<"1.按升序排列"<<endl;
		cout<<"2.按降序排列"<<endl;

		int select=0;
		cin>>select;
		for(int i=0;i<m_num;i++)
		{
			int minormax=i;
			for(int j=i+1;j<m_num;j++)
			{
				if(select==1)//升序
				{
					if(this->m_Array[minormax]->m_id > this->m_Array[j]->m_id)
					{
						minormax=j;
					}
				}
				else//降序
				{
					if(this->m_Array[minormax]->m_id < this->m_Array[j]->m_id)
					{
						minormax=j;
					}
				}
			}
			//判断大小 交换数据
			if(i!=minormax)
			{
				Worker * temp=this->m_Array[i];
				this->m_Array[i]=this->m_Array[minormax];
				this->m_Array[minormax]=temp;
			}
		}
		cout<<"排序成功！结果为："<<endl;
		this->save();
		this->show();//show函数里有清零操作，不用加了
	}
}

//清空文件
void WorkManager::clean()
{
	cout<<"确定清空？"<<endl;
	cout<<"1.确定"<<endl;
	cout<<"2.返回"<<endl;
	int select=0;
	cin>>select;

	if(select==1)
	{
		ofstream ofs(filename,ios::trunc);//删除文件后重新创建
		ofs.close();

		if(this->m_Array!=NULL)
		{
			//删除堆区的每个职工对象
			for(int i=0;i<this->m_num;i++)
			{
				delete this->m_Array[i];
				this->m_Array[i]=NULL;
			}
			delete[]this->m_Array;
			this->m_Array=NULL;
			this->m_num=0;
			this->m_fileEmpty=true;
		}
		cout<<"清空成功！"<<endl;
	}
	else
	{
		cout<<"你只是虚晃一枪 并没有清空"<<endl;
	}
	system("pause");
	system("cls");
}

WorkManager::~WorkManager()
{
	//释放
	if(this->m_Array!=NULL)
	{
		for(int i=0;i<this->m_num;i++)
		{
			if(this->m_Array[i]!=NULL)
			{
				delete this->m_Array[i];
			}
		}//每个元素释放
		delete[]this->m_Array;
		this->m_Array=NULL;
	}
}