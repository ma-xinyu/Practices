#pragma once//��ֹͷ�ļ��ظ�����
#include<iostream>
#include<string>
#include<vector>
#include"orderfile.h"
#include"identity.h"
using namespace std;

class Teacher:public Identity
{
public:
	//Ĭ�Ϲ���
	Teacher();

	//�вι���
	Teacher(int tid,string name,string password);

	//�˵����
	virtual void opermeun();

	//�鿴����ԤԼ
	void showallorder();

	//���ԤԼ
	void validroder();

	//ְ�����
	int m_tid;
};