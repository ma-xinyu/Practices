#include<iostream>
#include<string>
using namespace std;

void showmenu()
{
	cout<<"************************"<<endl;
	cout<<"***** 1.添加联系人 *****"<<endl;
	cout<<"***** 2.显示联系人 *****"<<endl;
	cout<<"***** 3.删除联系人 *****"<<endl;//3，4，5都基于姓名的查找进行
	cout<<"***** 4.查找联系人 *****"<<endl;
	cout<<"***** 5.修改联系人 *****"<<endl;
	cout<<"***** 6.清空联系人 *****"<<endl;
	cout<<"***** 0.退出通讯录 *****"<<endl;
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
	//判断是否满
	if (book->count==max)
	{
		cout<<"通讯录已满，无法再添加联系人！"<<endl;
	}
	else 
	{
		string name;//姓名
		cout<<"请输入姓名"<<endl;
		cin>>name;
		book->arr[book->count].name=name;

		int sex;//性别
		cout<<"请输入性别（1为男 2为女）"<<endl;
		while (true)//1 2退出，其他循环到输入正确为止
		{
			cin>>sex;
			if(sex==1||sex==2)
			{
				book->arr[book->count].sex=sex;
				break;
			}
			else
			{
				cout<<"输入有误，try again please"<<endl;
			}
		}

		int age;//年龄
		cout<<"请输入年龄"<<endl;
		cin>>age;
		book->arr[book->count].age=age;

		string number;//电话
		cout<<"请输入电话号码"<<endl;
		cin>>number;
		book->arr[book->count].number=number;

		string address;//住址
		cout<<"请输入住址"<<endl;
		cin>>address;
		book->arr[book->count].address=address;

		//更新通讯录人数
		book->count++;
		cout<<"添加成功"<<endl;
		system("pause");//请按任意键继续
		system("cls");//清屏
	}
}

void show(index * book)
{
	//判断
	if(book->count==0)
	{
		cout<<"通讯录为空"<<endl;
	}
	else
	{
		for(int i=0;i<book->count;i++)
		{
			cout<<"姓名："<<book->arr[i].name<<'\t';
			cout<<"性别："<<(book->arr[i].sex==1?"男":"女")<<'\t';//(运算符优先级)
			cout<<"年龄："<<book->arr[i].age<<'\t';
			cout<<"电话："<<book->arr[i].number<<'\t';
			cout<<"地址："<<book->arr[i].address<<endl;
		}
	}		
	system("pause");//请按任意键继续
	system("cls");//清屏
}

//检测联系人是否存在 如果存在，返回联系人的位置（数组中的位置）；否则输出“查无此人”返回-1；
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
	cout<<"请输入要删除的联系人的姓名；"<<endl;
	string name;
	cin>>name;
	int ret=exist(book,name);//book已经是指针类型了
	if(ret!=-1)//ret是找到的那个人的数组下标
	{
		cout<<"找到此人"<<endl;//删除的本质：把后面的数据前移；人数count-1;
		for(int i=ret;i<book->count;i++)
		{
			book->arr[ret]=book->arr[ret+1];
			book->count--;
		}
		cout<<"删除联系人成功"<<endl;
	}
	else
	{
		cout<<"查无此人"<<endl;
	}
	system("pause");//请按任意键继续
	system("cls");//清屏
}

void find(index * book)
{
	cout<<"请输入您要查找的联系人姓名："<<endl;
	string name;
	cin>>name;
	int ret=exist(book,name);
	if(ret!=-1)
	{
		cout<<"姓名："<<book->arr[ret].name<<'\t';
		cout<<"性别："<<(book->arr[ret].sex==1?"男":"女")<<'\t';//(运算符优先级)
		cout<<"年龄："<<book->arr[ret].age<<'\t';
		cout<<"电话："<<book->arr[ret].number<<'\t';
		cout<<"地址："<<book->arr[ret].address<<endl;
	}
	else
	{
		cout<<"查无此人"<<endl;
	}
	system("pause");//请按任意键继续
	system("cls");//清屏
}

void change(index * book)
{
	cout<<"请输入您要修改的联系人姓名："<<endl;
	string name;
	cin>>name;
	int ret=exist(book,name);
	if(ret!=-1)
	{
		cout<<"输入您要修改的信息："<<endl;
		string name;//姓名
		cout<<"请输入姓名"<<endl;
		cin>>name;
		book->arr[ret].name=name;

		int sex;//性别
		cout<<"请输入性别（1为男 2为女）"<<endl;
		while (true)//1 2退出，其他循环到输入正确为止
		{
			cin>>sex;
			if(sex==1||sex==2)
			{
				book->arr[ret].sex=sex;
				break;
			}
			else
			{
				cout<<"输入有误，try again please"<<endl;
			}
		}

		int age;//年龄
		cout<<"请输入年龄"<<endl;
		cin>>age;
		book->arr[book->count].age=age;

		string number;//电话
		cout<<"请输入电话号码"<<endl;
		cin>>number;
		book->arr[book->count].number=number;

		string address;//住址
		cout<<"请输入住址"<<endl;
		cin>>address;
		book->arr[book->count].address=address;
	}
	else
	{
		cout<<"查无此人"<<endl;
	}
	system("pause");//请按任意键继续
	system("cls");//清屏
}

void clear(index * book)
{
	cout<<"确定要清空联系人吗？（1）确定  （2）不了"<<endl;
	int num;
	cin>>num;
	if(num==1)
	{
		book->count=0;//把内存清空，数据自然都清空了
		cout<<"通讯录已清空"<<endl;
	}
	else if (num==2)
	{
		cout<<"通讯录未清空,你只是虚晃一枪"<<endl;
	}
	system("pause");//请按任意键继续
	system("cls");//清屏

}

int main()
{
	index book;//通讯录
	book.count=0;

	int var;
	//菜单调用
	while(true)
	{
		showmenu();
		cin>>var;
		switch(var)//根据选择调用不同的函数
		{
		case 1:
			add(&book);//地址传递
			break;
		case 2:
			show(&book);//判断是否有人
			break;
		//基于姓名检测的函数
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
			cout<<"欢迎下次使用！"<<endl;
			system("pause");
			return 0;//退出系统
			break;
		default:
			break;
		}
	}
	system("pause");
	return 0;
}