//��ͨԱ���ļ�
#pragma once
#include<iostream>
#include"Worker.h"
using namespace std;
class Employee : public Worker
{
public:
	Employee(int id,string name,int depid);
	//��ʾ��Ϣ
	virtual void showinfo();
	//��ȡ��λ����
	virtual string getdep();
};