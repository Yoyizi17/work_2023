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
	string B_num;//��
	string B_name;//����
	int B_mroom;//��������Ӧ1~3
	int B_day;//���ڣ���Ӧ1~5
	int B_time;//ʱ�䣺1.���磬2,����
	int B_state;//ԤԼ��״̬��1.����У�2.��ͨ����3.ȡ��ԤԼ
public:
	BookInformathionManager(string num,string name,int mroom,int day,int time,int state);

	void Display_My(MroomBook_Manager& mm,string num);
};