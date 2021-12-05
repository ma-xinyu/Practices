#include"演讲管理.h"

//构造函数
Manager::Manager()
{
	//初始化容器和属性
	this->initial();

	//创建12个选手
	this->create();

	//获取往届记录
	this->load();
}

//菜单界面
void Manager::show_menu()
{
	cout<<"****************************"<<endl;
	cout<<"******欢迎参加演讲比赛******"<<endl;
	cout<<"*******1.开始演讲比赛*******"<<endl;
	cout<<"*******2.查看往届比赛*******"<<endl;
	cout<<"*******3.清空比赛记录*******"<<endl;
	cout<<"*******0.退出比赛程序*******"<<endl;
	cout<<"****************************"<<endl;
	cout<<endl;
}

//退出系统
void Manager::exitsystem()
{
	cout<<"欢迎下次使用"<<endl;
	//system("pause");
	exit(0);
}


//初始化容器和属性
void Manager::initial()
{
	//容器都为空
	this->v1.clear();
	this->v2.clear();
	this->v.clear();
	this->m.clear();
	this->count=1;

	//将用于记录的容器也清空
	this->mr.clear();
}

//创建12名选手
void Manager::create()
{
	string nameSeed = "ABCDEFGHIJKL";
	for(int i=0;i<nameSeed.size();i++)
	{
		string name = "选手";
		name+=nameSeed[i];

		//创建了选手
		Speaker sp;
		sp.m_name=name;
		for(int j=0;j<2;j++)
		{
			sp.m_score[j]=0;
		}
		//创建选手编号 放到v1容器中
		this->v1.push_back(i+10001);

		//选手编号和对应选手 放到map容器中
		this->m.insert(make_pair(i+10001,sp));
	}
}

//开始比赛 比赛流程控制
void Manager::start()
{
	//第一轮比赛开始
	//1.抽签
	this->draw();

	//2.比赛
	this->contest();

	//3.显示晋级结果
	this->showscore();

	//第二轮比赛开始
	this->count++;
	//1.抽签
	this->draw();

	//2.比赛
	this->contest();

	//3.显示最终结果
	this->showscore();

	//4.保存分数到文件中
	this->save();
	
	//没有实时更新
	//重置结果 获取记录
	//初始化容器和属性
	this->initial();
	//创建12个选手
	this->create();
	//获取往届记录
	this->load();

	cout<<"本届比赛已结束！"<<endl;
	system("pause");
	system("cls");
}

//抽签
void Manager::draw()
{
	cout<<"第"<<this->count<<"轮的比赛选手正在抽签"<<endl;
	cout<<"----------------------------"<<endl;
	cout<<"抽签后的顺序是："<<endl;
	if(this->count==1)
	{
		//第一轮比赛
		random_shuffle(v1.begin(),v1.end());
		for(vector<int>::iterator it=v1.begin();it!=v1.end();it++)
		{
			cout<<*it<<" ";
		}
		cout<<endl;
	}
	else
	{
		//第二轮比赛
		random_shuffle(v2.begin(),v2.end());
		for(vector<int>::iterator it=v2.begin();it!=v2.end();it++)
		{
			cout<<*it<<" ";
		}
		cout<<endl;
	}
	cout<<"----------------------------"<<endl;
	system("pause");
	cout<<endl;
}

//比赛
void Manager::contest()
{
	cout<<"------------第"<<this->count<<"轮的比赛正式开始------------"<<endl;
	cout<<endl;

	//准备临时容器 存放小组成绩
	multimap<double,int,greater<double>>group;
	int num = 0;//记录人员的个数 六人一组

	vector<int>v_Src;//比赛选手的容器
	if(this->count==1)
	{
		v_Src = v1;
	}
	else
	{
		v_Src = v2;
	}
	//遍历所有选手进行比赛
	for(vector<int>::iterator it=v_Src.begin();it!=v_Src.end();it++)
	{
		num++;
		//评委打分
		deque<double>d;
		for(int i=0;i<10;i++)
		{
			double score = (rand()%401+600)/10.f; //60-100
			//cout<<score<<" ";
			d.push_back(score);
		}
		//cout<<endl;

		sort(d.begin(),d.end(),greater<double>());//排序
		d.pop_back(); //去除最低分
		d.pop_front();//去除最高分

		double sum = accumulate(d.begin(),d.end(),0);//总分
		double avg = sum/(double)d.size();//平均分

		//打印平均分
		//cout<<"编号："<<*it<<" 姓名："<<this->m[*it].m_name<<" 获取平均分："<<avg<<endl;

		//将平均分放入map容器中
		this->m[*it].m_score[this->count-1] = avg;

		//将打分数据放入临时小组容器中
		group.insert(make_pair(avg,*it));//key是平均值 value是具体选手的编号
		//每六人取出前三
		if(num % 6==0)
		{
			cout<<"第"<<num/6<<"小组比赛名次如下："<<endl;
			for(multimap<double,int,greater<double>>::iterator it=group.begin();it!=group.end();it++)
			{
				cout<<"编号："<<it->second<<" 姓名："<<this->m[it->second].m_name<<" 获取平均分："<<this->m[it->second].m_score[this->count-1]<<endl;
			}
			//取走前三名
			int countnum=0;
			for(multimap<double,int,greater<double>>::iterator it=group.begin();it!=group.end() && countnum<3;it++,countnum++)
			{
				if(this->count==1)
				{
					v2.push_back((*it).second);
				}
				else
				{
					v.push_back((*it).second);
				}
			}
			group.clear();//小组容器清空
			cout<<endl;
		}
	}
	cout<<"--------------第"<<this->count<<"轮比赛结束！--------------"<<endl;
	system("pause");
}

//显示得分
void Manager::showscore()
{
	cout<<"-----------第"<<this->count<<"轮晋级选手信息如下-----------"<<endl;
	cout<<endl;

	vector<int>vs;
	if(this->count==1)
	{
		vs=v2;
	}
	else
	{
		vs=v;
	}
	for(vector<int>::iterator it=vs.begin();it!=vs.end();it++)
	{
		cout<<"编号："<<*it<<" 姓名："<<this->m[*it].m_name<<" 获取平均分："<<this->m[*it].m_score[this->count-1]<<endl;
	}
	cout<<endl;

	system("pause");
	system("cls");
	this->show_menu();
}

//保存记录分数
void Manager::save()
{
	ofstream ofs;
	ofs.open("speech.cvs",ios::out|ios::app);//用追加的方式写文件
	//将每个选手的数据写入
	for(vector<int>::iterator it=v.begin();it!=v.end();it++)
	{
		ofs<<*it<<","<<this->m[*it].m_score[1]<<",";
	}
	ofs<<endl;

	//关闭文件
	ofs.close();
	cout<<"记录已经保存"<<endl;

	//记录完成 更改状态
	this->isempty=false;
}

//读取记录分数
void Manager::load()
{
	ifstream ifs("speech.cvs",ios::in);//读文件

	if(!ifs.is_open())
	{
		this->isempty=true;
		//cout<<"文件不存在"<<endl;
		ifs.close();
		return;
	}
	//文件清空情况
	char ch;
	ifs>>ch;
	if(ifs.eof())
	{
		this->isempty=true;
		//cout<<"文件为空"<<endl;
		ifs.close();
		return;
	}

	//文件不为空
	this->isempty=false;
	ifs.putback(ch);//将读走的第一个字符取回来
	string data;
	int index=0;
	while(ifs>>data)
	{
		//10002,86.375,10009,81,10010,78,
		//cout<<data<<endl;
		//zhangsan@sina.com

		vector<string>vr;//存放6个string字符串

		int pos = -1;//查到，位置的变量
		int startpos=0;

		while(1)
		{
			pos = data.find(",",startpos);
			if(pos==-1)
			{
				//没找到
				break;
			}
			string temp = data.substr(startpos,pos-startpos);
			//cout<<temp<<endl;
			vr.push_back(temp);
			startpos=pos+1;
		}	
		this->mr.insert(make_pair(index,vr));
		index++;//每一届的都有
	}
	ifs.close();
	/*for(map<int,vector<string>>::iterator it=mr.begin();it!=mr.end();it++)
	{
		cout<<it->first<<"冠军编号："<<it->second[0]<<" 分数："<<it->second[1]<<endl;
	}*/
}

//显示往届得分
void Manager::showrecord()
{
	//判断文件是否为空或者不存在
	if(this->isempty)
	{
		cout<<"文件为空或者不存在!"<<endl;
	}
	else
	{
		for(int i=0;i<this->mr.size();i++)
		{
			cout<<"第"<<i+1<<"届比赛  "
				<<"冠军编号："<<this->mr[i][0]<<" 得分："<<this->mr[i][1]<<" "
				<<"亚军编号："<<this->mr[i][2]<<" 得分："<<this->mr[i][3]<<" "
				<<"季军编号："<<this->mr[i][4]<<" 得分："<<this->mr[i][5]<<endl;
		}
	}
	system("pause");
	system("cls");
}

//清空记录
void Manager::clear()
{
	cout<<"确实清空？"<<endl;
	cout<<"1、是"<<endl;
	cout<<"2、否"<<endl;

	int select=0;
	cin>>select;
	if(select==1)
	{
		//清空  删除并重新创建新的（清空）
		ofstream ofs("speech.cvs",ios::trunc);
		ofs.close();
		//初始化容器和属性
		this->initial();
		//创建12个选手
		this->create();
		//获取往届记录
		this->load();
		cout<<"清空成功"<<endl;
	}
	else
	{
		cout<<"未进行清空操作"<<endl;
	}
	system("pause");
	system("cls");
}

//析构函数
Manager::~Manager()
{

}