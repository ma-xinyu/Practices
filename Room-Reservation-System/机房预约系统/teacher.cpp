#include"teacher.h"	

//Ĭ�Ϲ���
Teacher::Teacher()
{
}

//�вι���
Teacher::Teacher(int tid,string name,string password)
{
	//��ʼ������
	this->m_tid=tid;
	this->m_name=name;
	this->m_password=password;
}

//�˵����
void Teacher::opermeun()
{
	cout<<"��ӭ��ʦ��"<<this->m_name<<" ��½��"<<endl;
	cout<<"\t\t -------------------------\n";
	cout<<"\t\t|                         |\n";
	cout<<"\t\t|       1.�鿴����ԤԼ    |\n";
	cout<<"\t\t|                         |\n";
	cout<<"\t\t|       2.���ԤԼ        |\n";
	cout<<"\t\t|                         |\n";
	cout<<"\t\t|       0.ע����½        |\n";
	cout<<"\t\t|                         |\n";
	cout<<"\t\t -------------------------\n";
	cout<<"��ѡ�����Ĳ�����"<<endl;
}

//�鿴����ԤԼ
void Teacher::showallorder()
{
	OrderFile of;
	if(of.m_size==0)
	{
		cout<<"��ԤԼ"<<endl;
		system("pause");
		system("cls");
		return;
	}

	for(int i=0;i<of.m_size;i++)
	{
		cout<<i+1<<"��";
		cout<<"ԤԼʱ�䣺��"<<of.mo[i]["date"]<<" ";
		cout<<"ѧ�ţ�"<<of.mo[i]["stuid"]<<" ";
		cout<<"������"<<of.mo[i]["stuname"]<<" ";
		cout<<"ʱ��Σ�"<<(of.mo[i]["interval"]=="1" ? "����":"����")<<" ";
		cout<<"�����ţ�"<<of.mo[i]["roomid"]<<" ";
		string status="ԤԼ״̬��";
		//1.����� 2.��ԤԼ -1.ԤԼʧ�� 0.ȡ��ԤԼ
		if(of.mo[i]["status"]=="1")
		{
			status += "�����";
		}
		else if(of.mo[i]["status"]=="2")
		{
			status += "ԤԼ�ɹ�";
		}
		else if(of.mo[i]["status"]=="-1")
		{
			status += "ԤԼʧ�ܣ����δͨ��";
		}
		else
		{
			status +="ԤԼ��ȡ��";
		}
		cout<<status<<endl;
	}
	system("pause");
	system("cls");
}

//���ԤԼ
void Teacher::validroder()
{
	OrderFile of;
	if(of.m_size==0)
	{
		cout<<"��ԤԼ"<<endl;
		system("pause");
		system("cls");
		return;
	}

	cout<<"����˵�ԤԼ��¼���£�"<<endl;
	vector<int>v;//�������������е�ԤԼ�ı��
	int index=1;
	for(int i=0;i<of.m_size;i++)
	{
			//ɸѡ״̬ ����е�
			if(of.mo[i]["status"]=="1")
			{
				v.push_back(i);
				cout<<index++<<"��";
				cout<<"ԤԼʱ�䣺��"<<of.mo[i]["date"]<<" ";
				cout<<"ʱ��Σ�"<<(of.mo[i]["interval"]=="1" ? "����":"����")<<" ";
				cout<<"�����ţ�"<<of.mo[i]["roomid"]<<" ";
				string status="ԤԼ״̬��";
				//1.����� 2.��ԤԼ -1.ԤԼʧ�� 0.ȡ��ԤԼ
				if(of.mo[i]["status"]=="1")
				{
					status += "�����";
				}
				cout<<status<<endl;
			}
	}

	cout<<"��������˵�ԤԼ��¼��0��ʾ����"<<endl;
	int select = 0;//�����û�ѡ���ԤԼ��¼
	int ret = 0;//����ԤԼ�����¼
	while(true)
	{
		cin>>select;
		if(select >= 0 && select <= v.size())
		{
			if(select == 0)
			{
				break;
			}
			else
			{
				cout<<"��������˽��"<<endl;
				cout<<"1.ͨ��"<<endl;
				cout<<"2.��ͨ��"<<endl;
				cin>>ret;
				if(ret==1)
				{
					//ͨ��
					of.mo[v[select-1]]["status"] = "2";
				}
				else
				{
					//��ͨ��
					of.mo[v[select-1]]["status"] = "-1";
				}
				//����
				of.update();
				cout<<"�������ϣ�"<<endl;
				break;
			}
		}
		cout<<"������������������"<<endl;
	}
	system("pause");
	system("cls");
}