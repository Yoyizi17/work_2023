#pragma once
#include"Worker.h"
#include<iostream>
#include<string>
using namespace std;

class Boss :public AbstractWorker
{
public:

	Boss();
	Boss(int ID, string name, int Dept);

	virtual void ShowInfo();//显示职工信息

	virtual string GetDept();//获取岗位名称

};