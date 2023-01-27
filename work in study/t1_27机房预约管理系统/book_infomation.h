#pragma once
#include<iostream>

using namespace std;

class Compare_set;
class MroomBook_Manager;

class BookInformathion
{
	friend Compare_set;
	friend MroomBook_Manager;
protected:
	string B_num;//��
	string B_name;//����
	int B_mroom;//��������Ӧ1~3
	int B_day;//���ڣ���Ӧ1~5
	int B_time;//ʱ�䣺1.���磬2,����
	int B_state;//ԤԼ��״̬��1.����У�2.��ͨ����3.ȡ��ԤԼ
public:
	BookInformathion(string num, string name, int mroom, int day, int time, int state)
	{
		this->B_num = num;
		this->B_name = name;
		this->B_mroom = mroom;
		this->B_day = day;
		this->B_time = time;
		this->B_state = state;
	}

	bool operator==(const BookInformathion& b)const
	{
		if ((this->B_name == b.B_name || this->B_num == b.B_num)&&this->B_state!=3)
			return true;
		else
			return false;
	}
};