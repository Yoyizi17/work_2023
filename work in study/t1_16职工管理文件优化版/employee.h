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

	virtual void ShowInfo();//��ʾְ����Ϣ

	virtual string GetDept();//��ȡ��λ����

};