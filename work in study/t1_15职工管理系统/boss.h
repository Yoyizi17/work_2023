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

	virtual void ShowInfo();//��ʾְ����Ϣ

	virtual string GetDept();//��ȡ��λ����

};