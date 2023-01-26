#pragma once
#include<iostream>
using namespace std;

class Teacher
{
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