#include"manager.h"

//Ĭ�Ϲ���
Manager::Manager()
{
}

//�вι���
Manager::Manager(string name,string password)
{
	//��ʼ������Ա��Ϣ
	this->m_name=name;
	this->m_password=password;
	//��ʼ������ ���һ�ȡ���ļ���ѧ������ʦ����Ϣ
	this->initial();

	//��ʼ��������Ϣ ��Ϊ�����������Ϣ���� ����ֱ��д������
	//���Ҫ�Ķ�������Ϣ �������ṩ�ӿ�
	ifstream ifs;
	ifs.open(computer_file,ios::in);

	ComputerRoom com;
	while(ifs>>com.m_cid && ifs>>com.m_max)
	{
		vc.push_back(com);
	}
	ifs.close();
	cout<<"����������Ϊ��"<<vc.size()<<endl;
}

//�˵�����
void Manager::opermeun()
{
	cout<<"��ӭ����Ա��"<<this->m_name<<" ��½��"<<endl;
	cout<<"\t\t -------------------------\n";
	cout<<"\t\t|                         |\n";
	cout<<"\t\t|       1.����˺�        |\n";
	cout<<"\t\t|                         |\n";
	cout<<"\t\t|       2.�鿴�˺�        |\n";
	cout<<"\t\t|                         |\n";
	cout<<"\t\t|       3.�鿴����        |\n";
	cout<<"\t\t|                         |\n";
	cout<<"\t\t|       4.���ԤԼ        |\n";
	cout<<"\t\t|                         |\n";
	cout<<"\t\t|       0.ע����½        |\n";
	cout<<"\t\t|                         |\n";
	cout<<"\t\t -------------------------\n";
	cout<<"��ѡ�����Ĳ�����"<<endl;
}

//����˺�
void Manager::addperson()
{
	cout<<"����������˺ŵ�����"<<endl;
	cout<<"1.���ѧ��"<<endl;
	cout<<"2.��ӽ�ʦ"<<endl;

	string filename;//�����ļ���
	string tip;//��ʾid��

	string error;//�����ظ���ʾ

	ofstream ofs;//�ļ���������

	int select=0;
	cin>>select;//�����û�ѡ��

	if(select==1)
	{
		//��ӵ���ѧ��
		filename = student_file;
		tip = "������ѧ�ţ�";
		error = "ѧ���ظ�������������";
	}
	else
	{
		//��ӵ��ǽ�ʦ
		filename = teacher_file;
		tip = "������ְ���ţ�";
		error = "ְ�����ظ�������������";
	}

	//����׷�ӵķ�ʽ д�ļ�
	ofs.open(filename,ios::out|ios::app);
	
	int id;//ѧ�Ż�ְ����
	string name;//����
	string password;//����

	while(true)
	{	
		cout<<tip<<endl;
		cin>>id;
		bool ret = check(id,select);//���ӿ�
		if(ret)//���ظ�
		{
			cout<<error<<endl;//�ظ�ִ�� cin>>id �Ĳ���
		}
		else
		{
			break;//�����ظ�����ִ��
		}
	}

	//cout<<tip<<endl;
	//cin>>id;
	cout<<"������������"<<endl;
	cin>>name;
	cout<<"���������룺"<<endl;
	cin>>password;

	//���ļ����������
	ofs<<id<<" "<<name<<" "<<password<<" "<<endl;
	ofs.close();
	cout<<"��ӳɹ���"<<endl;

	system("pause");
	system("cls");

	//��ʼ������ ��ʱ�����ļ���Ϣ
	this->initial();
}

void prints(Student &s)
{
	cout<<"ѧ�ţ�"<<s.m_id<<" ������"<<s.m_name<<" ���룺"<<s.m_password<<endl;
}
void printt(Teacher &t)
{
	cout<<"ְ���ţ�"<<t.m_tid<<" ������"<<t.m_name<<" ���룺"<<t.m_password<<endl;
}

//�鿴�˺�
void Manager::showperosn()
{
	cout<<"��ѡ��鿴�����ݣ�"<<endl;
	cout<<"1.�鿴����ѧ��"<<endl;
	cout<<"2.�鿴���н�ʦ"<<endl;

	int select=0;
	cin>>select;

	if(select==1)
	{
		//�鿴ѧ��
		cout<<"����ѧ����Ϣ���£�"<<endl;
		for_each(vs.begin(),vs.end(),prints);
	}
	else
	{
		//�鿴��ʦ
		cout<<"������ʦ��Ϣ���£�"<<endl;
		for_each(vt.begin(),vt.end(),printt);
	}

	system("pause");
	system("cls");
}

//�鿴������Ϣ
void Manager::showcomputer()
{
	cout<<"������Ϣ���£�"<<endl;
	for(vector<ComputerRoom>::iterator it=vc.begin();it!=vc.end();it++)
	{
		cout<<"������ţ�"<<it->m_cid<<" �������������"<<it->m_max<<endl;
	}
	system("pause");
	system("cls");
}

//���ԤԼ��¼
void Manager::clean()
{
	ofstream ofs(order_file,ios::trunc);
	ofs.close();
	cout<<"��ճɹ���"<<endl;
	system("pause");
	system("cls");
}

//��ʼ������
void Manager::initial()
{
	//�������
	vs.clear();
	vt.clear();

	//��ȡ��Ϣ ѧ��
	ifstream ifs;
	ifs.open(student_file,ios::in);
	if(!ifs.is_open())
	{
		cout<<"��ȡ�ļ�ʧ��"<<endl;
		return;
	}
	Student s;
	while(ifs>>s.m_id && ifs>>s.m_name && ifs>>s.m_password)
	{
		vs.push_back(s);
	}
	cout<<"��ǰѧ������Ϊ��"<<vs.size()<<endl;;
	ifs.close();

	//��ȡ��Ϣ ��ʦ
	ifs.open(teacher_file,ios::in);
	if(!ifs.is_open())
	{
		cout<<"��ȡ�ļ�ʧ��"<<endl;
		return;
	}
	Teacher t;
	while(ifs>>t.m_tid && ifs>>t.m_name && ifs>>t.m_password)
	{
		vt.push_back(t);
	}
	cout<<"��ǰ��ʦ����Ϊ��"<<vt.size()<<endl;;
	ifs.close();
}

//����ظ�(�ڼ�������ʱ���) ����1��ѧ��/ְ���� ����2��ѧ��/��ʦ
bool Manager::check(int id,int type)
{
	if(type==1)
	{
		//���ѧ��
		for(vector<Student>::iterator it=vs.begin();it!=vs.end();it++)
		{
			if(id==it->m_id)
			{
				return true;
			}
		}
	}
	else
	{
		//�����ʦ
		for(vector<Teacher>::iterator it=vt.begin();it!=vt.end();it++)
		{
			if(id==it->m_tid)
			{
				return true;
			}
		}
	}
	//���ظ�
	return false;
}