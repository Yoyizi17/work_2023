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

	void AddWork(WorkManager& wm);//����ְԱ��Ϣ
	void DisplayWorker(WorkManager& wm);//��ʾְԱ��Ϣ
	void Destoryworker(WorkManager& wm);//ɾ��ְԱ��Ϣ
	void Changeworker(WorkManager& wm);//����ְԱ��Ϣ
	void Findwork(WorkManager& wm);//����ְԱ��Ϣ
	void Sortwork(WorkManager& wm);//���ձ�Ŵ�С��������
	void Killallwork(WorkManager& wm);//ɾ������ְԱ

	~WorkManager();

	int size;
	AbstractWorker** worklist;
};
