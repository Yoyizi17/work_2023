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

	virtual void ShowInfo();//��ʾְ����Ϣ

	virtual string GetDept();//��ȡ��λ����

};