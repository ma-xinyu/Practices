#include"manager.h"

Manager::Manager(int id,string name,int depid)
{
	m_id=id;
	m_name=name;
	m_depid=depid;
}
//显示信息
void Manager::showinfo()
{
	cout<<"职工编号："<<m_id
		<<"\t职工姓名："<<m_name
		<<"\t职工岗位："<<getdep()
		<<"\t岗位职责：完成老板交给的任务，并下发任务给普通员工"<<endl;
}
//获取岗位名称
string Manager::getdep()
{
	return string("经理");
}