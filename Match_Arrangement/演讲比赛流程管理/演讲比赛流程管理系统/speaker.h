#pragma once
#include<iostream>
#include<string>
using namespace std;

//选手类
class Speaker
{
public:
	string m_name;
	double m_score[2];//因为最多有两轮的成绩
};