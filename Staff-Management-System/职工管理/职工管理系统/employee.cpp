#include"employee.h"

Employee::Employee(int id,string name,int depid)
{
	m_id=id;
	m_name=name;
	m_depid=depid;
}
//��ʾ��Ϣ
void Employee::showinfo()
{
	cout<<"ְ����ţ�"<<m_id
		<<"\tְ��������"<<m_name
		<<"\tְ����λ��"<<getdep()
		<<"\t��λְ����ɾ�����������"<<endl;
}
//��ȡ��λ����
string Employee::getdep()
{
	return string("Ա��");
}