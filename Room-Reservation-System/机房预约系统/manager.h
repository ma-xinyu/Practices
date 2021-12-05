#pragma once//��ֹͷ�ļ��ظ�����
#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include"student.h"
#include"teacher.h"
#include"computerRoom.h"
#include"identity.h"
#include"globafile.h"
#include<algorithm>
using namespace std;

class Manager:public Identity
{
public:
	//Ĭ�Ϲ���
	Manager();

	//�вι���
	Manager(string name,string password);

	//�˵�����
	virtual void opermeun();

	//����˺�
	void addperson();

	//�鿴�˺�
	void showperosn();

	//�鿴������Ϣ
	void showcomputer();

	//���ԤԼ��¼
	void clean();

	//ȥ��
	//��ʼ������
	void initial();

	//����ظ� ����1��ѧ��/ְ���� ����2��ѧ��/��ʦ
	bool check(int id,int type);

	//ѧ������
	vector<Student>vs;

	//��ʦ����
	vector<Teacher>vt;

	//��������
	vector<ComputerRoom>vc;
};