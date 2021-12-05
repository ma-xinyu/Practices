#include"WorkManager.h"

WorkManager::WorkManager()
{
	//1.�ļ�������
	ifstream ifs;
	ifs.open(filename,ios::in);//���ļ�
	if(!ifs.is_open())
	{
		cout<<"�ļ�������!"<<endl;
		//���ļ� ��ʼ������
		this->m_num=0;
		this->m_Array=NULL;
		this->m_fileEmpty=true;//�ļ��ǿյ�
		ifs.close();
		return;
	}
	//2.�ļ����ڣ�����Ϊ��
	char ch;
	ifs >> ch;
	if(ifs.eof())//�����ļ�β
	{
		cout<<"�ļ�Ϊ��!"<<endl;
		//���ļ� ��ʼ������
		this->m_num=0;
		this->m_Array=NULL;
		this->m_fileEmpty=true;//�ļ��ǿյ�
		ifs.close();
		return;
	}
	//3.�ļ����ڣ���������
	this->m_fileEmpty=false;
	int num=this->get_num();
	cout<<"ְ��������Ϊ��"<<num<<endl;
	this->m_num = num;
	//���ٿռ�
	this->m_Array = new Worker * [this->m_num];
	//���ļ��е����ݴ浽������
	this->initial();
	//����
	//for(int i=0;i<this->m_num;i++)
	//{
	//	cout<<"ְ����ţ�"<<this->m_Array[i]->m_id
	//		<<"������"<<this->m_Array[i]->m_name
	//		<<"��λ��ţ�"<<this->m_Array[i]->m_depid<<endl;
	//}
}
//չʾ�˵�
void WorkManager::show_Menu()
{
	cout<<"*************************************"<<endl;
	cout<<"******* ��ӭʹ��ְ������ϵͳ��*******"<<endl;
	cout<<"********** 0.�˳�����ϵͳ ***********"<<endl;
	cout<<"********** 1.����ְ����Ϣ ***********"<<endl;
	cout<<"********** 2.��ʾְ����Ϣ ***********"<<endl;
	cout<<"********** 3.ɾ����ְְ�� ***********"<<endl;
	cout<<"********** 4.�޸�ְ����Ϣ ***********"<<endl;
	cout<<"********** 5.����ְ����Ϣ ***********"<<endl;
	cout<<"********** 6.���ձ������ ***********"<<endl;
	cout<<"********** 7.������е��� ***********"<<endl;
	cout<<endl;
}

//�˳�ϵͳ
void WorkManager::Exit()
{
	cout<<"Byebye! Welcome to use the system again!"<<endl;
	system("pause");
	exit(0);//һ������exit,��ֱ���˳�����(ֱ���˳�ѭ������������)
}

//���Ա��
void WorkManager::add_Num()
{
	cout<<"�������ְ������"<<endl;
	int addnum=0;
	cin>>addnum;
	if(addnum>0)
	{
		//��� ������ӵ��¿ռ��С
		int newsize = this->m_num+addnum;
		//�����¿ռ�
		Worker ** newspace = new Worker * [newsize];
		//��ԭ�������ݿ������¿ռ���
		if (this->m_num!=NULL)
		{
			for (int i=0;i<m_num;i++)//i<this->m_num
			{
				newspace[i]=this->m_Array[i];
			}
		}
		//�������������
		for (int i=0;i<addnum;i++)
		{
			int id;
			string name;
			int depselect;
			cout<<"�������"<<i+1<<"����ְ���ı�ţ�"<<endl;
			cin>>id;
			cout<<"�������"<<i+1<<"����ְ����������"<<endl;
			cin>>name;
			cout<<"�������"<<i+1<<"����ְ���ĸ�λ��"<<endl;
			cout<<"��ѡ���ְ����λ��"<<endl;
			cout<<"1.��ͨԱ��"<<endl;
			cout<<"2.����"<<endl;
			cout<<"3.�ϰ�"<<endl;
			cin>>depselect;

			Worker * worker = NULL;
			switch(depselect)
			{
			case 1:
				worker = new Employee(id,name,1);
				break;
			case 2:
				worker = new Manager(id,name,2);
				break;
			case 3:
				worker = new Boss(id,name,3);
				break;
			default:
				break;
			}
			//��������ְ��ָ�룬���浽������
			newspace[this->m_num+i] = worker;
		}
		//�ͷ�ԭ���Ķ����ռ�
		delete[]this->m_Array;
		//�滻�¿ռ��ָ��
		this->m_Array=newspace;
		//��������
		this->m_num=newsize;
		//�����ļ���Ϊ�ձ�־
		this->m_fileEmpty=false;
		//��ʾ��ӳɹ�
		cout<<"�ɹ����"<<addnum<<"����Ա��"<<endl;

		this->save();//�������ݵ��ļ���
	}
	else
	{
		cout<<"Date error"<<endl;
	}
	//���ƽ���
	system("pause");
	system("cls");
}

//�����ļ�
void WorkManager::save()
{
	ofstream ofs;
	ofs.open(filename,ios::out);//д�ļ�
	//����д���ļ�
	for(int i=0;i<this->m_num;i++)
	{//����cout<<...
		ofs<<this->m_Array[i]->m_id<<" "
			<<this->m_Array[i]->m_name<<" "
			<<this->m_Array[i]->m_depid<<endl;
	}
	//�ر��ļ�
	ofs.close();
}

//ͳ������
int WorkManager::get_num()
{
	ifstream ifs;
	ifs.open(filename,ios::in);//���ļ� ���ļ�
	int id;
	string name;
	int desid;
	int num=0;
	while(ifs>>id && ifs>>name && ifs>>desid)
	{
		num++;
	}
	return num;
}

//��ʼ��Ա��
void WorkManager::initial()
{
	ifstream ifs;
	ifs.open(filename,ios::in);
	int id;
	string name;
	int desid;

	int index=0;
	while(ifs>>id && ifs>>name && ifs>>desid)
	{
		Worker * worker = NULL;
		if(desid==1)
		{
			worker = new Employee(id,name,desid);
		}
		else if(desid==2)
		{
			worker = new Manager(id,name,desid);
		}
		else if(desid==3)
		{
			worker = new Boss(id,name,desid);
		}
		this->m_Array[index]=worker;
		index++;
	}
	ifs.close();
}

//��ʾְ���ĳ�Ա����
void WorkManager::show()
{
	//�ж��ļ��Ƿ�Ϊ��
	if(this->m_fileEmpty)
	{
		cout<<"�ļ������ڻ��ļ�Ϊ�գ�"<<endl;
	}
	else 
	{
		for(int i=0;i<this->m_num;i++)
		{
			//���ö�̬���ó���ӿ�
			this->m_Array[i]->showinfo();
		}
	}
	system("pause");
	system("cls");
}

//�ж��Ƿ������ְ�� ������ڷ���ְ���������е�λ�ã������ڷ���-1
int WorkManager::isexist(int id)
{
	int index=-1;
	for(int i=0;i<this->m_num;i++)
	{
		if(this->m_Array[i]->m_id==id)
		{
			index=i;
			break;
		}
	}
	return index;
}

//ɾ��ְ��
void WorkManager::del()
{
	//�ж��ļ��Ƿ�Ϊ��
	if(this->m_fileEmpty)
	{
		cout<<"�ļ������ڻ��ļ�Ϊ�գ�"<<endl;
	}
	else
	{
		cout<<"����Ҫɾ����Ա���ı�ţ�"<<endl;
		int id;
		cin>>id;
		int index=this->isexist(id);//�ж��Ƿ����
		if(index!=-1)
		{
			cout<<"�ҵ�Ա����Ϣ"<<endl;
			//����ǰ��
			for(int i=index;i<this->m_num-1;i++)
			{
				this->m_Array[i] = this->m_Array[i+1];
			}
			this->m_num--;
			//ͬ�����µ��ļ���
			this->save();
			cout<<"ɾ���ɹ���"<<endl;
		}
		else
		{
			cout<<"��Ա�������� ɾ��ʧ��"<<endl;
		}
	}
	system("pause");
	system("cls");
}

//�޸�ְ��
void WorkManager::change()
{
	//�ж��ļ��Ƿ�Ϊ��
	if(this->m_fileEmpty)
	{
		cout<<"�ļ������ڻ��ļ�Ϊ�գ�"<<endl;
	}
	else
	{
		cout<<"�������޸�ְ���ı�ţ�"<<endl;
		int id;
		cin>>id;

		int index=this->isexist(id);//�ж��Ƿ����
		if(index!=-1)
		{
			delete this->m_Array[index];
			int newid=0;
			string newname="";
			int newdesid=0;

			cout<<"�鵽"<<id<<"��Ա�����������µı�ţ�"<<endl;
			cin>>newid;
			cout<<"�������µ�Ա��������"<<endl;
			cin>>newname;
			cout<<"�������µĸ�λ��"<<endl;
			cout<<"1.��ͨԱ��"<<endl;
			cout<<"2.����"<<endl;
			cout<<"3.�ϰ�"<<endl;
			cin>>newdesid;

			Worker * worker = NULL;
			switch(newdesid)
			{
			case 1:
				worker = new Employee(newid,newname,newdesid);
				break;
			case 2:
				worker = new Manager(newid,newname,newdesid);
				break;
			case 3:
				worker = new Boss(newid,newname,newdesid);
				break;
			default:
				break;
			}

			//�������ݵ�������
			this->m_Array[index]=worker;
			cout<<"�޸ĳɹ���"<<endl;
			//ͬ�����µ��ļ���
			this->save();
		}
		else
		{
			cout<<"��Ա�������� ɾ��ʧ��"<<endl;
		}
	}
	system("pause");
	system("cls");
}

//����ְ��
void WorkManager::find()
{
	if(this->m_fileEmpty)
	{
		cout<<"�ļ������ڻ��ļ�Ϊ�գ�"<<endl;
	}
	else
	{
		cout<<"��������ҵķ�ʽ��"<<endl;
		cout<<"1.��ְ����Ų���"<<endl;
		cout<<"2.��ְ����������"<<endl;

		int select=0;
		cin>>select;
		if (select==1)
		{
			int id;
			cout<<"����Ҫ���ҵ�Ա���ı�ţ�"<<endl;
			cin>>id;
			int index=this->isexist(id);//�ж��Ƿ����
			if(index!=-1)
			{
				cout<<"�ҵ�ְ������ְ������Ϣ���£�"<<endl;
				this->m_Array[index]->showinfo();
			}
			else
			{
				cout<<"��Ա��������"<<endl;
			}
		}
		else if (select==2)
		{
			string name;
			cout<<"����Ҫ���ҵ�Ա����������"<<endl;
			cin>>name;
			//�Ƿ�鵽�ı�־
			bool flag=false;

			for(int i=0;i<m_num;i++)
			{
				if(this->m_Array[i]->m_name==name)
				{
					cout<<"���ҳɹ���ְ���ı��Ϊ:"
						<<this->m_Array[i]->m_id<<'\t'
						<<this->m_Array[i]->m_id
						<<"��ְ������Ϣ���£�"<<endl;
					this->m_Array[i]->showinfo();
					flag=true;
				}
			}
			if(flag==false)
			{
				cout<<"��Ա��������"<<endl;
			}
			cout<<""<<endl;
		}
		else 
		{
			cout<<"�������!";
		}
	}
	system("pause");
	system("cls");
}

//������
void WorkManager::sort()
{
	if(this->m_fileEmpty)
	{
		cout<<"�ļ������ڻ��ļ�Ϊ�գ�"<<endl;
		system("pause");
	    system("cls");
	}
	else
	{
		cout<<"��ѡ������ʽ"<<endl;
		cout<<"1.����������"<<endl;
		cout<<"2.����������"<<endl;

		int select=0;
		cin>>select;
		for(int i=0;i<m_num;i++)
		{
			int minormax=i;
			for(int j=i+1;j<m_num;j++)
			{
				if(select==1)//����
				{
					if(this->m_Array[minormax]->m_id > this->m_Array[j]->m_id)
					{
						minormax=j;
					}
				}
				else//����
				{
					if(this->m_Array[minormax]->m_id < this->m_Array[j]->m_id)
					{
						minormax=j;
					}
				}
			}
			//�жϴ�С ��������
			if(i!=minormax)
			{
				Worker * temp=this->m_Array[i];
				this->m_Array[i]=this->m_Array[minormax];
				this->m_Array[minormax]=temp;
			}
		}
		cout<<"����ɹ������Ϊ��"<<endl;
		this->save();
		this->show();//show��������������������ü���
	}
}

//����ļ�
void WorkManager::clean()
{
	cout<<"ȷ����գ�"<<endl;
	cout<<"1.ȷ��"<<endl;
	cout<<"2.����"<<endl;
	int select=0;
	cin>>select;

	if(select==1)
	{
		ofstream ofs(filename,ios::trunc);//ɾ���ļ������´���
		ofs.close();

		if(this->m_Array!=NULL)
		{
			//ɾ��������ÿ��ְ������
			for(int i=0;i<this->m_num;i++)
			{
				delete this->m_Array[i];
				this->m_Array[i]=NULL;
			}
			delete[]this->m_Array;
			this->m_Array=NULL;
			this->m_num=0;
			this->m_fileEmpty=true;
		}
		cout<<"��ճɹ���"<<endl;
	}
	else
	{
		cout<<"��ֻ�����һǹ ��û�����"<<endl;
	}
	system("pause");
	system("cls");
}

WorkManager::~WorkManager()
{
	//�ͷ�
	if(this->m_Array!=NULL)
	{
		for(int i=0;i<this->m_num;i++)
		{
			if(this->m_Array[i]!=NULL)
			{
				delete this->m_Array[i];
			}
		}//ÿ��Ԫ���ͷ�
		delete[]this->m_Array;
		this->m_Array=NULL;
	}
}