#pragma once//��ֹͷ�ļ��ظ�����
#include<iostream>
using namespace std;

//��ݳ������ ����
class Identity
{
public:
	//�����˵� ���麯��
	virtual void opermeun() = 0;//��̬�Ļ���

	//�û���
	string m_name;

	//����
	string m_password;
};