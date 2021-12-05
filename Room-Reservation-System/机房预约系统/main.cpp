#include<iostream>
#include<string>
#include<fstream>
#include"globafile.h"
#include"identity.h"
using namespace std;
#include"student.h"
#include"teacher.h"
#include"manager.h"

//�������Ա���Ӳ˵�
void managermenu(Identity * &manager)//����ָ�����ʹ�����
{
	while(1)
	{
		//���ù���Ա���Ӳ˵�
		manager->opermeun();

		//������ָ�� תΪ�����ָ�룬�����������������еĽӿ�
		Manager * man = (Manager*)manager;

		int select=0;
		//�����û���ѡ��
		cin>>select;
		if(select==1)//����˺�
		{
			//cout<<"����˺�"<<endl;
			man->addperson();
		}
		else if(select==2)//�鿴�˺�
		{
			//cout<<"�鿴�˺�"<<endl;
			man->showperosn();
		}
		else if(select==3)//�鿴����
		{
			//cout<<"�鿴����"<<endl;
			man->showcomputer();
		}
		else if(select==4)//���ԤԼ
		{
			//cout<<"���ԤԼ"<<endl;
			man->clean();
		}
		else
		{
			delete manager;//���ٶ�������
			cout<<"ע���ɹ�"<<endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//����ѧ�����Ӳ˵�
void studentmenu(Identity * &student)//����ָ�����ʹ�����
{
	while(1)
	{
		//����ѧ�����Ӳ˵�
		student->opermeun();

		//������ָ�� תΪ�����ָ�룬�����������������еĽӿ�
		Student * stu = (Student*)student;

		int select=0;
		//�����û���ѡ��
		cin>>select;
		if(select==1)//����ԤԼ
		{
			//cout<<"����ԤԼ"<<endl;
			stu->applyorder();
		}
		else if(select==2)//�鿴����ԤԼ
		{
			//cout<<"�鿴����ԤԼ"<<endl;
			stu->showmyorder();
		}
		else if(select==3)//�鿴����ԤԼ
		{
			//cout<<"�鿴����ԤԼ"<<endl;
			stu->showallroder();
		}
		else if(select==4)//ȡ��ԤԼ
		{
			//cout<<"ȡ��ԤԼ"<<endl;
			stu->cancel();
		}
		else
		{
			delete student;//���ٶ�������
			cout<<"ע���ɹ�"<<endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//�����ʦ���Ӳ˵�
void Teachermenu(Identity * &teacher)//����ָ�����ʹ�����
{
	while(1)
	{
		//���ý�ʦ���Ӳ˵�
		teacher->opermeun();

		//������ָ�� תΪ�����ָ�룬�����������������еĽӿ�
		Teacher * tea = (Teacher*)teacher;

		int select=0;
		//�����û���ѡ��
		cin>>select;
		if(select==1)//�鿴����ԤԼ
		{
			//cout<<"�鿴����ԤԼ"<<endl;
			tea->showallorder();
		}
		else if(select==2)//���ԤԼ
		{
			//cout<<"���ԤԼ"<<endl;
			tea->validroder();
		}
		else
		{
			delete teacher;//���ٶ�������
			cout<<"ע���ɹ�"<<endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//��½����  ������1�������ļ���  ������2�������������
void loginin(string filename,int type)
{
	//����ָ�� ָ���������
	Identity * person = NULL;

	//���ļ�
	ifstream ifs;
	ifs.open(filename,ios::in);

	//�ж��ļ��Ƿ����
	if(!ifs.is_open())
	{
		cout<<"�ļ�������"<<endl;
		ifs.close();
		return;
	}

	//׼�������û�����Ϣ
	int id=0;
	string name;
	string password;

	//�ж����
	if(type==1)//ѧ��
	{
		cout<<"���������ѧ�ţ�"<<endl;
		cin>>id;
	}
	else if(type==2)
	{
		cout<<"����������ְ���ţ�"<<endl;
		cin>>id;
	}
	cout<<"�������û�����"<<endl;
	cin>>name;
	cout<<"���������룺"<<endl;
	cin>>password;

	if(type==1)
	{
		//ѧ�������֤
		int fid;//���ļ���ȡ��id��
		string fname;//���ļ���ȡ������
		string fpassword;//���ļ���ȡ������
		while(ifs>>fid && ifs>>fname && ifs>>fpassword)
		{
			//���û������Ա�
			if(fid==id && fname==name && fpassword==password)
			{
				cout<<"ѧ����֤��½�ɹ���"<<endl;
				system("pause");
				system("cls");
				//����ѧ������
				person = new Student(id,name,password);
				//����ѧ����ݵ��Ӳ˵�
				studentmenu(person);

				return;
			}
		}
	}
	else if(type==2)
	{
		//��ʦ�����֤
		int fid;//���ļ���ȡ��id��
		string fname;//���ļ���ȡ������
		string fpassword;//���ļ���ȡ������
		while(ifs>>fid && ifs>>fname && ifs>>fpassword)
		{
			//���û������Ա�
			if(fid==id && fname==name && fpassword==password)
			{
				cout<<"��ʦ��֤��½�ɹ���"<<endl;
				system("pause");
				system("cls");
				//������ʦ����
				person = new Teacher(id,name,password);
				//�����ʦ��ݵ��Ӳ˵�
				Teachermenu(person);

				return;
			}
		}
	}
	else if(type==3)
	{
		//����Ա�����֤
		string fname;//���ļ���ȡ������
		string fpassword;//���ļ���ȡ������
		while(ifs>>fname && ifs>>fpassword)
		{
			//���û������Ա�
			if(fname==name && fpassword==password)
			{
				cout<<"����Ա��֤��½�ɹ���"<<endl;
				system("pause");
				system("cls");
				//��������Ա����
				person = new Manager(name,password);
				//�������Ա��ݵ��Ӳ˵�
				managermenu(person);

				return;
			}
		}

	}
	//������
	cout<<"��֤��½ʧ�ܣ�"<<endl;
	system("pause");
	system("cls");
	return;
}

int main()
{
	int select=0;
	while(1)
	{
		cout<<"----------------��ӭ����Martin�Ļ���ԤԼϵͳ----------------"<<endl;
		cout<<endl;
		cout<<"�������������"<<endl;
		cout<<"\t\t -------------------------\n";
		cout<<"\t\t|                         |\n";
		cout<<"\t\t|       1.ѧ������        |\n";
		cout<<"\t\t|                         |\n";
		cout<<"\t\t|       2.��    ʦ        |\n";
		cout<<"\t\t|                         |\n";
		cout<<"\t\t|       3.�� �� Ա        |\n";
		cout<<"\t\t|                         |\n";
		cout<<"\t\t|       0.��    ��        |\n";
		cout<<"\t\t|                         |\n";
		cout<<"\t\t -------------------------\n";
		cout<<"��������ѡ��"<<endl;
		cin>>select;

		switch(select)
		{
		case 1://ѧ��
			loginin(student_file,1);
			break;
		case 2://��ʦ
			loginin(teacher_file,2);
			break;
		case 3://����Ա
			loginin(admin_file,3);
			break;
		case 0://�˳�ϵͳ
			cout<<"��ӭ��һ��ʹ��"<<endl;
			//system("pause");
			return 0;
			break;
		default:
			cout<<"��������������ѡ��"<<endl;
			system("pause");
			system("cls");
			break;
		}
	}

	system("pause");
	return 0;
}