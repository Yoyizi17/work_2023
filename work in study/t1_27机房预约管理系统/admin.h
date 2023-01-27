#pragma once
#include<iostream>
using namespace std;

class AdminAccManager;

class Admin
{
	friend AdminAccManager;
protected:
	string am_num;
	string am_name;
	string am_passsword;
public:
	Admin(string num, string name, string password)
	{
		this->am_num = num;
		this->am_name = name;
		this->am_passsword = password;
	}
};