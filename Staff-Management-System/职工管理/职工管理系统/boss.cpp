#include"boss.h"

Boss::Boss(int id,string name,int depid)
{
	m_id=id;
	m_name=name;
	m_depid=depid;
}
//显示信息
void Boss::showinfo()
{
	cout<<"职工编号："<<m_id
		<<"\t职工姓名："<<m_name
		<<"\t职工岗位："<<getdep()
		<<"\t岗位职责：管理公司所有事物"<<endl;
}
//获取岗位名称
string Boss::getdep()
{
	return string("老板");
}