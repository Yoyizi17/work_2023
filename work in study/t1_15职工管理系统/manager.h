#pragma once
#include"Worker.h"
#include<iostream>
#include<string>
using namespace std;

class Manager :public AbstractWorker
{
public:

	Manager();
	Manager(int ID, string name, int Dept);

	virtual void ShowInfo();//显示职工信息

	virtual string GetDept();//获取岗位名称

};