#include"boss.h"

Boss::Boss(int id,string name,int depid)
{
	m_id=id;
	m_name=name;
	m_depid=depid;
}
//��ʾ��Ϣ
void Boss::showinfo()
{
	cout<<"ְ����ţ�"<<m_id
		<<"\tְ��������"<<m_name
		<<"\tְ����λ��"<<getdep()
		<<"\t��λְ�𣺹���˾��������"<<endl;
}
//��ȡ��λ����
string Boss::getdep()
{
	return string("�ϰ�");
}