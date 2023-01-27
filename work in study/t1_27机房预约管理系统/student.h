#pragma once
#include<iostream>
using namespace std;

class Compare_set;
class BookInformathionManager;
class StudentAccManager;
class MroomBook_Manager;

class Student
{
	friend Compare_set;
	friend BookInformathionManager;
	friend StudentAccManager;
	friend MroomBook_Manager;
protected:
	string sm_num;
	string sm_name;
	string sm_passsword;
public:
	Student();
	Student(string num, string name, string password)
	{
		this->sm_num = num;
		this->sm_name = name;
		this->sm_passsword = password;
	}
	Student(string name, string password)
	{
		this->sm_num = "bakana";
		this->sm_name = name;
		this->sm_passsword = password;
	}
};