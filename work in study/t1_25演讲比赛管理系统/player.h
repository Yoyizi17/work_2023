#pragma once
#include<iostream>
#include<string>

//#include"competition.h"

using namespace std;

class Competition;
class Compare_sort_Player;
class Print_int_Player;

class Player//����һ��ѡ���࣬��������ѡ��
{
	friend Competition;
	friend Compare_sort_Player;
	friend Print_int_Player;
protected:
	string m_name;
	int m_score;
public:
	Player(string name,int score);
};