#include"manager.h"

Manager::Manager(int id,string name,int depid)
{
	m_id=id;
	m_name=name;
	m_depid=depid;
}
//��ʾ��Ϣ
void Manager::showinfo()
{
	cout<<"ְ����ţ�"<<m_id
		<<"\tְ��������"<<m_name
		<<"\tְ����λ��"<<getdep()
		<<"\t��λְ������ϰ彻�������񣬲��·��������ͨԱ��"<<endl;
}
//��ȡ��λ����
string Manager::getdep()
{
	return string("����");
}