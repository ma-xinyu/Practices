#include"employee.h"

Employee::Employee(int id,string name,int depid)
{
	m_id=id;
	m_name=name;
	m_depid=depid;
}
//显示信息
void Employee::showinfo()
{
	cout<<"职工编号："<<m_id
		<<"\t职工姓名："<<m_name
		<<"\t职工岗位："<<getdep()
		<<"\t岗位职责：完成经理交给的任务"<<endl;
}
//获取岗位名称
string Employee::getdep()
{
	return string("员工");
}