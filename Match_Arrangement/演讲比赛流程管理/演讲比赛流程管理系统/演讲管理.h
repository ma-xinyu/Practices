#pragma once
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<deque>
#include<functional>
#include<numeric>
#include<fstream>
#include<ctime>
#include"speaker.h"
using namespace std;

//����ݽ�����������
class Manager
{
public:
	//���캯��
	Manager();

	//�˵�����
	void show_menu();

	//�˳�ϵͳ
	void exitsystem();

	//��������
	~Manager();


	//��ʼ������������
	void initial();

	//����12��ѡ��
	void create();

	//��ʼ���� �������̿���
	void start();

	//��ǩ
	void draw();

	//����
	void contest();

	//��ʾ�÷�
	void showscore();

	//�����¼����
	void save();

	//��ȡ��¼����
	void load();
	//�ж��ļ��Ƿ�Ϊ��
	bool isempty;
	//��������¼������
	map<int,vector<string>>mr;

	//��ʾ����÷�
	void showrecord();

	//��ռ�¼
	void clear();

	//��Ա����
	//�����һ�ֱ���ѡ�ֱ�ŵ�����
	vector<int>v1;
	//�����һ�ֽ���ѡ�ֱ�ŵ�����
	vector<int>v2;
	//ʤ�������˱�ŵ�����
	vector<int>v;
	//��ű���Լ���Ӧ��ѡ������
	map<int,Speaker>m;
	//��ű�������
	int count;
};