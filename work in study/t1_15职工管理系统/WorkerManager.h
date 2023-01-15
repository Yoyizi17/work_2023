#pragma once
#include"Worker.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"
#include<iostream>
#include<Windows.h>
using namespace std;

class WorkManager
{
public:
	WorkManager();

	void ShowMenu();

	void AddWork(WorkManager& wm);//增加职员信息
	void DisplayWorker(WorkManager& wm);//显示职员信息
	void Destoryworker(WorkManager& wm);//删除职员信息
	void Changeworker(WorkManager& wm);//更改职员信息
	void Findwork(WorkManager& wm);//检索职员信息
	void Sortwork(WorkManager& wm);//按照编号大小进行排序
	void Killallwork(WorkManager& wm);//删除所有职员

	~WorkManager();

	int size;
	AbstractWorker** worklist;
};
