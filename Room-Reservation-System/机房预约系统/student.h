#pragma once//��ֹͷ�ļ��ظ�����
#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include"globafile.h"
#include"computerRoom.h"
#include"identity.h"
#include"orderfile.h"
using namespace std;

class Student:public Identity
{
public:
	//Ĭ�Ϲ���
	Student();

	//�вι��� ������ѧ�š�����������
	Student(int id,string name,string password);

	//�˵�����
	virtual void opermeun();

	//����ԤԼ
	void applyorder();

	//�鿴�Լ���ԤԼ
	void showmyorder();

	//�鿴����ԤԼ
	void showallroder();

	//ȡ��ԤԼ
	void cancel();

	//ѧ��ѧ��
	int m_id;

	//��������
	vector<ComputerRoom>vc;
};