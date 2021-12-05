#include"student.h"

//Ĭ�Ϲ���
Student::Student()
{
}

//�вι��� ������ѧ�š�����������
Student::Student(int id,string name,string password)
{
	//��ʼ������
	this->m_id=id;
	this->m_name=name;
	this->m_password=password;

	//��ʼ��������Ϣ
	ifstream ifs;
	ifs.open(computer_file,ios::in);
	ComputerRoom com;
	while(ifs>>com.m_cid && ifs>>com.m_max)
	{
		//��������Ϣ�ŵ� ������
		vc.push_back(com);
	}
	ifs.close();
}

//�˵�����
void Student::opermeun()
{
	cout<<"��ӭѧ����"<<this->m_name<<" ��½��"<<endl;
	cout<<"\t\t -------------------------\n";
	cout<<"\t\t|                         |\n";
	cout<<"\t\t|       1.����ԤԼ        |\n";
	cout<<"\t\t|                         |\n";
	cout<<"\t\t|       2.�鿴�ҵ�ԤԼ    |\n";
	cout<<"\t\t|                         |\n";
	cout<<"\t\t|       3.�鿴����ԤԼ    |\n";
	cout<<"\t\t|                         |\n";
	cout<<"\t\t|       4.ȡ��ԤԼ        |\n";
	cout<<"\t\t|                         |\n";
	cout<<"\t\t|       0.ע����½        |\n";
	cout<<"\t\t|                         |\n";
	cout<<"\t\t -------------------------\n";
	cout<<"��ѡ�����Ĳ�����"<<endl;
}

//����ԤԼ
void Student::applyorder()
{
	cout<<"��������ʱ��Ϊ��һ�����壡"<<endl;
	int date=0;//����
	int interval=0;//����/����
	int room=0;//�������

	//����
	cout<<"����������ԤԼ��ʱ�䣺"<<endl;
	cout<<"1.��һ"<<endl;
	cout<<"2.�ܶ�"<<endl;
	cout<<"3.����"<<endl;
	cout<<"4.����"<<endl;
	cout<<"5.����"<<endl;
	while(1)
	{
		cin>>date;
		if(date>=1 && date<=5)
		{
			break;
		}
		cout<<"�����������������룡"<<endl;
	}

	//ʱ���
	cout<<"����������ԤԼʱ��Σ�"<<endl;
	cout<<"1.����"<<endl;
	cout<<"2.����"<<endl;
	while(1)
	{
		cin>>interval;
		if(interval>=1 && interval<=2)
		{
			break;
		}
		cout<<"�����������������룡"<<endl;
	}

	//������Ϣ
	cout<<"��ѡ�������"<<endl;
	for(int i=0;i<vc.size();i++)
	{
		cout<<vc[i].m_cid<<"�Ż�������Ϊ��"<<vc[i].m_max<<endl;
	}
	//cout<<vc[0].m_cid<<""<<vc[0].m_max<<endl;
	while(1)
	{
		cin>>room;
		if(room>=1 && room<=3)
		{
			break;
		}
		cout<<"�����������������룡"<<endl;
	}

	cout<<"ԤԼ�ɹ��������"<<endl;

	//д�� order
	ofstream ofs;
	ofs.open(order_file,ios::app);//׷��
	ofs<<"date:"<<date<<" ";
	ofs<<"interval:"<<interval<<" ";
	ofs<<"stuid:"<<this->m_id<<" ";
	ofs<<"stuname:"<<this->m_name<<" ";
	ofs<<"roomid:"<<room<<" ";
	ofs<<"status:"<<1<<endl;
	ofs.close();

	system("pause");
	system("cls");
}

//�鿴�Լ���ԤԼ
void Student::showmyorder()
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
		//string ת int
		//string ���� .c_str() ת const char *
		//���� atoi(const char * )ת int
		if(atoi(of.mo[i]["stuid"].c_str()) == this->m_id)//����֮��ĶԱ�
		{
			cout<<"ԤԼʱ�䣺��"<<of.mo[i]["date"]<<" ";
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
	}
	system("pause");
	system("cls");
}

//�鿴����ԤԼ
void Student::showallroder()
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

//ȡ��ԤԼ
void Student::cancel()
{
	OrderFile of;
	if(of.m_size==0)
	{
		cout<<"��ԤԼ"<<endl;
		system("pause");
		system("cls");
		return;
	}

	cout<<"����л�ԤԼ�ɹ���ԤԼ����ȡ����������Ҫȡ����ԤԼ��¼"<<endl;
	vector<int>v;//�������������е�ԤԼ�ı��
	int index=1;
	for(int i=0;i<of.m_size;i++)
	{
		//���ж����Լ���ԤԼ
		if(atoi(of.mo[i]["stuid"].c_str()) == this->m_id)
		{
			//��ɸѡ״̬ ����л�ԤԼ�ɹ���
			if(of.mo[i]["status"]=="1"||of.mo[i]["status"]=="2")
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
				else if(of.mo[i]["status"]=="2")
				{
					status += "ԤԼ�ɹ�";
				}
				cout<<status<<endl;
			}
		}
	}

	cout<<"������Ҫȡ���ļ�¼��0��ʾ����"<<endl;
	int select = 0;
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
				of.mo[v[select-1]]["status"] = "0";
				//����
				of.update();
				cout<<"��ȡ��ԤԼ"<<endl;
				break;
			}
		}
		cout<<"������������������"<<endl;
	}
	system("pause");
	system("cls");
}