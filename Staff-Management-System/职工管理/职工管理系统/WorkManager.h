#pragma once//��ֹͷ�ļ��ظ�����
#include<iostream>//�������������ͷ�ļ�
#include<fstream>
#include"Worker.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"
using namespace std;//ʹ�ñ�׼�����ռ�
#define filename "file.txt"

class WorkManager
{
public:
	//���캯��
	WorkManager();
	//���ܣ�չʾ�˵�
	void show_Menu();
	//���ܣ��˳�ϵͳ
	void Exit();
	//��¼ְ������
	int m_num;
	//ְ������ָ��
	Worker ** m_Array;//����ָ���ָ��
	//���ְ��
	void add_Num();
	//�����ļ�
	void save();
	//�ж��ļ��Ƿ�Ϊ�յı�־
	bool m_fileEmpty;
	//ͳ������
	int get_num();
	//��ʼ��Ա��
	void initial();
	//��ʾְ���ĳ�Ա����
	void show();
	//�ж��Ƿ������ְ�� ������ڷ���ְ���������е�λ�ã������ڷ���-1
	int isexist(int id);
	//ɾ��ְ��
	void del();
	//�޸�ְ��
	void change();
	//����ְ��
	void find();
	//������
	void sort();
	//����ļ�
	void clean();
	//��������
	~WorkManager();//ֻд��������дʵ��
};