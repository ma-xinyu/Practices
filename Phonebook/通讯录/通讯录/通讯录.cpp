#include<iostream>
#include<string>
using namespace std;

void showmenu()
{
	cout<<"************************"<<endl;
	cout<<"***** 1.�����ϵ�� *****"<<endl;
	cout<<"***** 2.��ʾ��ϵ�� *****"<<endl;
	cout<<"***** 3.ɾ����ϵ�� *****"<<endl;//3��4��5�����������Ĳ��ҽ���
	cout<<"***** 4.������ϵ�� *****"<<endl;
	cout<<"***** 5.�޸���ϵ�� *****"<<endl;
	cout<<"***** 6.�����ϵ�� *****"<<endl;
	cout<<"***** 0.�˳�ͨѶ¼ *****"<<endl;
	cout<<"************************"<<endl;
}

struct peoson
{
	string name;
	int sex;//1 man;2 woman
	int age;
	string number;
	string address;
};
#define max 1000
struct index
{
	peoson arr[max];
	int count;
};

void add(index * book)
{
	//�ж��Ƿ���
	if (book->count==max)
	{
		cout<<"ͨѶ¼�������޷��������ϵ�ˣ�"<<endl;
	}
	else 
	{
		string name;//����
		cout<<"����������"<<endl;
		cin>>name;
		book->arr[book->count].name=name;

		int sex;//�Ա�
		cout<<"�������Ա�1Ϊ�� 2ΪŮ��"<<endl;
		while (true)//1 2�˳�������ѭ����������ȷΪֹ
		{
			cin>>sex;
			if(sex==1||sex==2)
			{
				book->arr[book->count].sex=sex;
				break;
			}
			else
			{
				cout<<"��������try again please"<<endl;
			}
		}

		int age;//����
		cout<<"����������"<<endl;
		cin>>age;
		book->arr[book->count].age=age;

		string number;//�绰
		cout<<"������绰����"<<endl;
		cin>>number;
		book->arr[book->count].number=number;

		string address;//סַ
		cout<<"������סַ"<<endl;
		cin>>address;
		book->arr[book->count].address=address;

		//����ͨѶ¼����
		book->count++;
		cout<<"��ӳɹ�"<<endl;
		system("pause");//�밴���������
		system("cls");//����
	}
}

void show(index * book)
{
	//�ж�
	if(book->count==0)
	{
		cout<<"ͨѶ¼Ϊ��"<<endl;
	}
	else
	{
		for(int i=0;i<book->count;i++)
		{
			cout<<"������"<<book->arr[i].name<<'\t';
			cout<<"�Ա�"<<(book->arr[i].sex==1?"��":"Ů")<<'\t';//(��������ȼ�)
			cout<<"���䣺"<<book->arr[i].age<<'\t';
			cout<<"�绰��"<<book->arr[i].number<<'\t';
			cout<<"��ַ��"<<book->arr[i].address<<endl;
		}
	}		
	system("pause");//�밴���������
	system("cls");//����
}

//�����ϵ���Ƿ���� ������ڣ�������ϵ�˵�λ�ã������е�λ�ã���������������޴��ˡ�����-1��
int exist(index * book,string name)
{
	for(int i=0;i<book->count;i++)
	{
		if(book->arr[i].name==name)
		{
			return i;
		}
	}
	return -1;
}

void dele(index * book)
{
	cout<<"������Ҫɾ������ϵ�˵�������"<<endl;
	string name;
	cin>>name;
	int ret=exist(book,name);//book�Ѿ���ָ��������
	if(ret!=-1)//ret���ҵ����Ǹ��˵������±�
	{
		cout<<"�ҵ�����"<<endl;//ɾ���ı��ʣ��Ѻ��������ǰ�ƣ�����count-1;
		for(int i=ret;i<book->count;i++)
		{
			book->arr[ret]=book->arr[ret+1];
			book->count--;
		}
		cout<<"ɾ����ϵ�˳ɹ�"<<endl;
	}
	else
	{
		cout<<"���޴���"<<endl;
	}
	system("pause");//�밴���������
	system("cls");//����
}

void find(index * book)
{
	cout<<"��������Ҫ���ҵ���ϵ��������"<<endl;
	string name;
	cin>>name;
	int ret=exist(book,name);
	if(ret!=-1)
	{
		cout<<"������"<<book->arr[ret].name<<'\t';
		cout<<"�Ա�"<<(book->arr[ret].sex==1?"��":"Ů")<<'\t';//(��������ȼ�)
		cout<<"���䣺"<<book->arr[ret].age<<'\t';
		cout<<"�绰��"<<book->arr[ret].number<<'\t';
		cout<<"��ַ��"<<book->arr[ret].address<<endl;
	}
	else
	{
		cout<<"���޴���"<<endl;
	}
	system("pause");//�밴���������
	system("cls");//����
}

void change(index * book)
{
	cout<<"��������Ҫ�޸ĵ���ϵ��������"<<endl;
	string name;
	cin>>name;
	int ret=exist(book,name);
	if(ret!=-1)
	{
		cout<<"������Ҫ�޸ĵ���Ϣ��"<<endl;
		string name;//����
		cout<<"����������"<<endl;
		cin>>name;
		book->arr[ret].name=name;

		int sex;//�Ա�
		cout<<"�������Ա�1Ϊ�� 2ΪŮ��"<<endl;
		while (true)//1 2�˳�������ѭ����������ȷΪֹ
		{
			cin>>sex;
			if(sex==1||sex==2)
			{
				book->arr[ret].sex=sex;
				break;
			}
			else
			{
				cout<<"��������try again please"<<endl;
			}
		}

		int age;//����
		cout<<"����������"<<endl;
		cin>>age;
		book->arr[book->count].age=age;

		string number;//�绰
		cout<<"������绰����"<<endl;
		cin>>number;
		book->arr[book->count].number=number;

		string address;//סַ
		cout<<"������סַ"<<endl;
		cin>>address;
		book->arr[book->count].address=address;
	}
	else
	{
		cout<<"���޴���"<<endl;
	}
	system("pause");//�밴���������
	system("cls");//����
}

void clear(index * book)
{
	cout<<"ȷ��Ҫ�����ϵ���𣿣�1��ȷ��  ��2������"<<endl;
	int num;
	cin>>num;
	if(num==1)
	{
		book->count=0;//���ڴ���գ�������Ȼ�������
		cout<<"ͨѶ¼�����"<<endl;
	}
	else if (num==2)
	{
		cout<<"ͨѶ¼δ���,��ֻ�����һǹ"<<endl;
	}
	system("pause");//�밴���������
	system("cls");//����

}

int main()
{
	index book;//ͨѶ¼
	book.count=0;

	int var;
	//�˵�����
	while(true)
	{
		showmenu();
		cin>>var;
		switch(var)//����ѡ����ò�ͬ�ĺ���
		{
		case 1:
			add(&book);//��ַ����
			break;
		case 2:
			show(&book);//�ж��Ƿ�����
			break;
		//�����������ĺ���
		case 3:
			dele(&book);
			break;
		case 4:
			find(&book);
			break;
		case 5:
			change(&book);
			break;
		case 6:
			clear(&book);
			break;
		case 0:
			cout<<"��ӭ�´�ʹ�ã�"<<endl;
			system("pause");
			return 0;//�˳�ϵͳ
			break;
		default:
			break;
		}
	}
	system("pause");
	return 0;
}