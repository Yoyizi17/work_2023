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
	string B_num;//号
	string B_name;//名字
	int B_mroom;//机房：对应1~3
	int B_day;//星期：对应1~5
	int B_time;//时间：1.上午，2,下午
	int B_state;//预约的状态：1.审核中，2.已通过，3.取消预约
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