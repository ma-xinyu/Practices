#pragma once//��ֹͷ�ļ��ظ�����
#include<iostream>
#include<string>
#include<map>
#include<fstream>
#include"globafile.h"
using namespace std;

class OrderFile
{
public:
	//���캯��
	OrderFile();

	//����ԤԼ��Ϣ
	void update();

	//��¼ԤԼ����
	int m_size;

	//��¼������Ϣ������ key��¼ԤԼ������ value��¼�����ֵ����Ϣ
	map<int,map<string,string>>mo;
};