/*12�˲μ� ���������� ��һ��Ϊ��̭�����ڶ���Ϊ����
ÿ��ѡ���б�� ��10001-10012
������ʽ�����������ÿ��6��
��һ�ַ�Ϊ����С�� ��ǩ����
ʮ����ί��� ȥ����ߺ���� ��ƽ��ֵ
��̭���ں����� ǰ��������
�ڶ���Ϊ���� ǰ����Ϊʤ��
ÿ�ֱ�������Ҫ��ʾ����ѡ�ֵ���Ϣ*/

/*��ʼ�ݽ�����������������������̣�ÿ�������׶ζ�Ҫ���û�һ����ʾ���û�������������¸��׶�
�鿴�����¼���鿴֮ǰ������ǰ������ÿ�α��������¼���ļ��У��ļ���.csv��׺������
��ձ�����¼�����ļ����������
�˳��������򣺿����˳���ǰ����*/

#include<iostream>
#include"�ݽ�����.h"
using namespace std;

int main()
{
	//���������
	srand((unsigned int)time(NULL));
	
	//�������������
	Manager sm;

	int choice=0;//�洢�û���ѡ��
	while(1)
	{
		sm.show_menu();
		cout<<"��������ѡ��"<<endl;
		cin>>choice;
		switch(choice)
		{
		case 1://��ʼ����
			sm.start();
			break;
		case 2://�鿴��¼
			sm.showrecord();
			break;
		case 3://��ռ�¼
			sm.clear();
			break;
		case 0://�˳�ϵͳ
			sm.exitsystem();
			break;
		default:
			system("cls");
			break;
		}
	}
	system("pause");
	return 0;
}

	////����12��ѡ�ֵĴ���
	//for(map<int,Speaker>::iterator it=sm.m.begin();it!=sm.m.end();it++)
	//{
	//	cout<<"ѡ�ֱ�ţ�"<<it->first<<" ������"<<it->second.m_name<<" �ɼ���"<<it->second.m_score[0]<<endl;
	//}