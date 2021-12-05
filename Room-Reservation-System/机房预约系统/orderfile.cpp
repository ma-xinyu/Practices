#include"orderfile.h"

//构造函数
OrderFile::OrderFile()
{
	ifstream ifs;
	ifs.open(order_file,ios::in);

	string date;//星期
	string interval;//上午/下午
	string stuid;//学生编号
	string stuname;//学生姓名
	string roomid;//机房编号
	string status;//预约状态

	this->m_size=0;//记录的条数

	while(ifs>>date && ifs>>interval && ifs>>stuid && ifs>>stuname && ifs>>roomid && ifs>>status)//以空格为界取出来的
	{
		/*cout<<date<<endl;
		cout<<interval<<endl;
		cout<<stuid<<endl;
		cout<<stuname<<endl;
		cout<<room<<endl;
		cout<<status<<endl;
		cout<<endl;*/

		//date:1
		string key;
		string value;
		map<string,string>m;

		//date
		int pos = date.find(":");//返回4
		if(pos!=-1)
		{
			key=date.substr(0,pos);
		    value=date.substr(pos+1,date.size());
			m.insert(make_pair(key,value));
		}
		//interval
		pos = interval.find(":");
		if(pos!=-1)
		{
			key=interval.substr(0,pos);
		    value=interval.substr(pos+1,date.size());
			m.insert(make_pair(key,value));
		}
		//stuid
		pos = stuid.find(":");
		if(pos!=-1)
		{
			key=stuid.substr(0,pos);
		    value=stuid.substr(pos+1,date.size());
			m.insert(make_pair(key,value));
		}
		//stuname
		pos = stuname.find(":");
		if(pos!=-1)
		{
			key=stuname.substr(0,pos);
		    value=stuname.substr(pos+1,date.size());
			m.insert(make_pair(key,value));
		}
		//roomid
		pos = roomid.find(":");
		if(pos!=-1)
		{
			key=roomid.substr(0,pos);
		    value=roomid.substr(pos+1,date.size());
			m.insert(make_pair(key,value));
		}
		//status
		pos = status.find(":");
		if(pos!=-1)
		{
			key=status.substr(0,pos);
		    value=status.substr(pos+1,date.size());
			m.insert(make_pair(key,value));
		}

		//将小map放到大map中
		this->mo.insert(make_pair(this->m_size,m));
		this->m_size++;

		/*cout<<"key "<<key<<endl;
		cout<<"value "<<value<<endl;*/
	}
	ifs.close();
	/*//测试最大的map
	for(map<int,map<string,string>>::iterator it=mo.begin();it!=mo.end();it++)
	{
		cout<<"条数="<<it->first<<" value="<<endl;
		for(map<string,string>::iterator mit=(*it).second.begin();mit!=(*it).second.end();mit++)
		{
			cout<<"key="<<mit->first<<" value="<<mit->second<<" ";
		}
		cout<<endl;
	}*/
}

//更新预约信息
void OrderFile::update()
{
	if(this->m_size==0)
	{
		return;//预约记录为0
	}

	ofstream ofs(order_file,ios::out|ios::trunc);
	for(int i=0;i<m_size;i++)
	{
		ofs<<"date:"<<this->mo[i]["date"]<<" ";
		ofs<<"interval:"<<this->mo[i]["interval"]<<" ";
		ofs<<"stuid:"<<this->mo[i]["stuid"]<<" ";
		ofs<<"stuname:"<<this->mo[i]["stuname"]<<" ";
		ofs<<"roomid:"<<this->mo[i]["roomid"]<<" ";
		ofs<<"status:"<<this->mo[i]["status"]<<endl;
	}
	ofs.close();
}