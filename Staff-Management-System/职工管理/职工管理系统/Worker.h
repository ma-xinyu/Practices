#pragma once
#include<iostream>
#include<string>
using namespace std;

class Worker//�����಻ʵ�֣����ý���.cpp
{
public:
	//��ʾ��Ϣ
	virtual void showinfo()=0;
	//��ȡ��λ����
	virtual string getdep()=0;
	int m_id;
	string m_name;
	int m_depid;
};