#pragma once
#include"Worker.h"
#include<iostream>
#include<string>
#include<string.h>
using namespace std;

class Employee :public AbstractWorker
{
public:

	Employee();
	Employee(int ID,string name,int Dept);

	virtual void ShowInfo();//显示职工信息

	virtual string GetDept();//获取岗位名称

};