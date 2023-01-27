#pragma once
#include<iostream>
using namespace std;

class Compare_set;
class BookInformathionManager;
class TeacherAccManager;
class MroomBook_Manager;

class Teacher
{   
	friend Compare_set;
	friend BookInformathionManager;
	class MroomBook_Manager;
	friend TeacherAccManager;
protected:
	string tm_num;
	string tm_name;
	string tm_passsword;
public:
	Teacher(string num, string name, string password)
	{
		this->tm_num = num;
		this->tm_name = name;
		this->tm_passsword = password;
	}
};