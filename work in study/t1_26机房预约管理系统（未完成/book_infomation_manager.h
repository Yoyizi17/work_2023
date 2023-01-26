#pragma once
#include<iostream>

#include"mroom_book_manager.h"
using namespace std;

class MroomBook_Manager;
class Student;

class BookInformathionManager
{
	friend MroomBook_Manager;
	friend Student;
protected:
	string B_num;//号
	string B_name;//名字
	int B_mroom;//机房：对应1~3
	int B_day;//星期：对应1~5
	int B_time;//时间：1.上午，2,下午
	int B_state;//预约的状态：1.审核中，2.已通过，3.取消预约
public:
	BookInformathionManager(string num,string name,int mroom,int day,int time,int state);

	void Display_My(MroomBook_Manager& mm,string num);
};