//�ϰ��ļ�
#pragma once
#include<iostream>
#include"Worker.h"
using namespace std;
class Boss : public Worker
{
public:
	Boss(int id,string name,int depid);
	//��ʾ��Ϣ
	virtual void showinfo();
	//��ȡ��λ����
	virtual string getdep();
};