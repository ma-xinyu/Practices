#include"�ݽ�����.h"

//���캯��
Manager::Manager()
{
	//��ʼ������������
	this->initial();

	//����12��ѡ��
	this->create();

	//��ȡ�����¼
	this->load();
}

//�˵�����
void Manager::show_menu()
{
	cout<<"****************************"<<endl;
	cout<<"******��ӭ�μ��ݽ�����******"<<endl;
	cout<<"*******1.��ʼ�ݽ�����*******"<<endl;
	cout<<"*******2.�鿴�������*******"<<endl;
	cout<<"*******3.��ձ�����¼*******"<<endl;
	cout<<"*******0.�˳���������*******"<<endl;
	cout<<"****************************"<<endl;
	cout<<endl;
}

//�˳�ϵͳ
void Manager::exitsystem()
{
	cout<<"��ӭ�´�ʹ��"<<endl;
	//system("pause");
	exit(0);
}


//��ʼ������������
void Manager::initial()
{
	//������Ϊ��
	this->v1.clear();
	this->v2.clear();
	this->v.clear();
	this->m.clear();
	this->count=1;

	//�����ڼ�¼������Ҳ���
	this->mr.clear();
}

//����12��ѡ��
void Manager::create()
{
	string nameSeed = "ABCDEFGHIJKL";
	for(int i=0;i<nameSeed.size();i++)
	{
		string name = "ѡ��";
		name+=nameSeed[i];

		//������ѡ��
		Speaker sp;
		sp.m_name=name;
		for(int j=0;j<2;j++)
		{
			sp.m_score[j]=0;
		}
		//����ѡ�ֱ�� �ŵ�v1������
		this->v1.push_back(i+10001);

		//ѡ�ֱ�źͶ�Ӧѡ�� �ŵ�map������
		this->m.insert(make_pair(i+10001,sp));
	}
}

//��ʼ���� �������̿���
void Manager::start()
{
	//��һ�ֱ�����ʼ
	//1.��ǩ
	this->draw();

	//2.����
	this->contest();

	//3.��ʾ�������
	this->showscore();

	//�ڶ��ֱ�����ʼ
	this->count++;
	//1.��ǩ
	this->draw();

	//2.����
	this->contest();

	//3.��ʾ���ս��
	this->showscore();

	//4.����������ļ���
	this->save();
	
	//û��ʵʱ����
	//���ý�� ��ȡ��¼
	//��ʼ������������
	this->initial();
	//����12��ѡ��
	this->create();
	//��ȡ�����¼
	this->load();

	cout<<"��������ѽ�����"<<endl;
	system("pause");
	system("cls");
}

//��ǩ
void Manager::draw()
{
	cout<<"��"<<this->count<<"�ֵı���ѡ�����ڳ�ǩ"<<endl;
	cout<<"----------------------------"<<endl;
	cout<<"��ǩ���˳���ǣ�"<<endl;
	if(this->count==1)
	{
		//��һ�ֱ���
		random_shuffle(v1.begin(),v1.end());
		for(vector<int>::iterator it=v1.begin();it!=v1.end();it++)
		{
			cout<<*it<<" ";
		}
		cout<<endl;
	}
	else
	{
		//�ڶ��ֱ���
		random_shuffle(v2.begin(),v2.end());
		for(vector<int>::iterator it=v2.begin();it!=v2.end();it++)
		{
			cout<<*it<<" ";
		}
		cout<<endl;
	}
	cout<<"----------------------------"<<endl;
	system("pause");
	cout<<endl;
}

//����
void Manager::contest()
{
	cout<<"------------��"<<this->count<<"�ֵı�����ʽ��ʼ------------"<<endl;
	cout<<endl;

	//׼����ʱ���� ���С��ɼ�
	multimap<double,int,greater<double>>group;
	int num = 0;//��¼��Ա�ĸ��� ����һ��

	vector<int>v_Src;//����ѡ�ֵ�����
	if(this->count==1)
	{
		v_Src = v1;
	}
	else
	{
		v_Src = v2;
	}
	//��������ѡ�ֽ��б���
	for(vector<int>::iterator it=v_Src.begin();it!=v_Src.end();it++)
	{
		num++;
		//��ί���
		deque<double>d;
		for(int i=0;i<10;i++)
		{
			double score = (rand()%401+600)/10.f; //60-100
			//cout<<score<<" ";
			d.push_back(score);
		}
		//cout<<endl;

		sort(d.begin(),d.end(),greater<double>());//����
		d.pop_back(); //ȥ����ͷ�
		d.pop_front();//ȥ����߷�

		double sum = accumulate(d.begin(),d.end(),0);//�ܷ�
		double avg = sum/(double)d.size();//ƽ����

		//��ӡƽ����
		//cout<<"��ţ�"<<*it<<" ������"<<this->m[*it].m_name<<" ��ȡƽ���֣�"<<avg<<endl;

		//��ƽ���ַ���map������
		this->m[*it].m_score[this->count-1] = avg;

		//��������ݷ�����ʱС��������
		group.insert(make_pair(avg,*it));//key��ƽ��ֵ value�Ǿ���ѡ�ֵı��
		//ÿ����ȡ��ǰ��
		if(num % 6==0)
		{
			cout<<"��"<<num/6<<"С������������£�"<<endl;
			for(multimap<double,int,greater<double>>::iterator it=group.begin();it!=group.end();it++)
			{
				cout<<"��ţ�"<<it->second<<" ������"<<this->m[it->second].m_name<<" ��ȡƽ���֣�"<<this->m[it->second].m_score[this->count-1]<<endl;
			}
			//ȡ��ǰ����
			int countnum=0;
			for(multimap<double,int,greater<double>>::iterator it=group.begin();it!=group.end() && countnum<3;it++,countnum++)
			{
				if(this->count==1)
				{
					v2.push_back((*it).second);
				}
				else
				{
					v.push_back((*it).second);
				}
			}
			group.clear();//С���������
			cout<<endl;
		}
	}
	cout<<"--------------��"<<this->count<<"�ֱ���������--------------"<<endl;
	system("pause");
}

//��ʾ�÷�
void Manager::showscore()
{
	cout<<"-----------��"<<this->count<<"�ֽ���ѡ����Ϣ����-----------"<<endl;
	cout<<endl;

	vector<int>vs;
	if(this->count==1)
	{
		vs=v2;
	}
	else
	{
		vs=v;
	}
	for(vector<int>::iterator it=vs.begin();it!=vs.end();it++)
	{
		cout<<"��ţ�"<<*it<<" ������"<<this->m[*it].m_name<<" ��ȡƽ���֣�"<<this->m[*it].m_score[this->count-1]<<endl;
	}
	cout<<endl;

	system("pause");
	system("cls");
	this->show_menu();
}

//�����¼����
void Manager::save()
{
	ofstream ofs;
	ofs.open("speech.cvs",ios::out|ios::app);//��׷�ӵķ�ʽд�ļ�
	//��ÿ��ѡ�ֵ�����д��
	for(vector<int>::iterator it=v.begin();it!=v.end();it++)
	{
		ofs<<*it<<","<<this->m[*it].m_score[1]<<",";
	}
	ofs<<endl;

	//�ر��ļ�
	ofs.close();
	cout<<"��¼�Ѿ�����"<<endl;

	//��¼��� ����״̬
	this->isempty=false;
}

//��ȡ��¼����
void Manager::load()
{
	ifstream ifs("speech.cvs",ios::in);//���ļ�

	if(!ifs.is_open())
	{
		this->isempty=true;
		//cout<<"�ļ�������"<<endl;
		ifs.close();
		return;
	}
	//�ļ�������
	char ch;
	ifs>>ch;
	if(ifs.eof())
	{
		this->isempty=true;
		//cout<<"�ļ�Ϊ��"<<endl;
		ifs.close();
		return;
	}

	//�ļ���Ϊ��
	this->isempty=false;
	ifs.putback(ch);//�����ߵĵ�һ���ַ�ȡ����
	string data;
	int index=0;
	while(ifs>>data)
	{
		//10002,86.375,10009,81,10010,78,
		//cout<<data<<endl;
		//zhangsan@sina.com

		vector<string>vr;//���6��string�ַ���

		int pos = -1;//�鵽��λ�õı���
		int startpos=0;

		while(1)
		{
			pos = data.find(",",startpos);
			if(pos==-1)
			{
				//û�ҵ�
				break;
			}
			string temp = data.substr(startpos,pos-startpos);
			//cout<<temp<<endl;
			vr.push_back(temp);
			startpos=pos+1;
		}	
		this->mr.insert(make_pair(index,vr));
		index++;//ÿһ��Ķ���
	}
	ifs.close();
	/*for(map<int,vector<string>>::iterator it=mr.begin();it!=mr.end();it++)
	{
		cout<<it->first<<"�ھ���ţ�"<<it->second[0]<<" ������"<<it->second[1]<<endl;
	}*/
}

//��ʾ����÷�
void Manager::showrecord()
{
	//�ж��ļ��Ƿ�Ϊ�ջ��߲�����
	if(this->isempty)
	{
		cout<<"�ļ�Ϊ�ջ��߲�����!"<<endl;
	}
	else
	{
		for(int i=0;i<this->mr.size();i++)
		{
			cout<<"��"<<i+1<<"�����  "
				<<"�ھ���ţ�"<<this->mr[i][0]<<" �÷֣�"<<this->mr[i][1]<<" "
				<<"�Ǿ���ţ�"<<this->mr[i][2]<<" �÷֣�"<<this->mr[i][3]<<" "
				<<"������ţ�"<<this->mr[i][4]<<" �÷֣�"<<this->mr[i][5]<<endl;
		}
	}
	system("pause");
	system("cls");
}

//��ռ�¼
void Manager::clear()
{
	cout<<"ȷʵ��գ�"<<endl;
	cout<<"1����"<<endl;
	cout<<"2����"<<endl;

	int select=0;
	cin>>select;
	if(select==1)
	{
		//���  ɾ�������´����µģ���գ�
		ofstream ofs("speech.cvs",ios::trunc);
		ofs.close();
		//��ʼ������������
		this->initial();
		//����12��ѡ��
		this->create();
		//��ȡ�����¼
		this->load();
		cout<<"��ճɹ�"<<endl;
	}
	else
	{
		cout<<"δ������ղ���"<<endl;
	}
	system("pause");
	system("cls");
}

//��������
Manager::~Manager()
{

}