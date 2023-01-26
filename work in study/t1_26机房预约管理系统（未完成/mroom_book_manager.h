#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<set>

#include<algorithm>
#include<functional>

#include"student.h"
#include"teacher.h"
#include"admin.h"

#include"compare_set.h"

#include"student_.acc_manager.h"
using namespace std;

#define STUDENT 1
#define TEATHER 2
#define ADMIN 3
#define EXIT 0

#define STUFILE "student.txt"

class StudentAccManager;
class BookInformathionManager;

class MroomBook_Manager
{
	friend Student;
	friend Teacher;
	friend Admin;
	friend StudentAccManager;
	friend BookInformathionManager;
protected:
	set<Student, Compare_set> vstu;//������������ѧ���˺���Ϣ
	vector<Teacher> vtea;//��������������ʦ�˺���Ϣ
	vector<Admin> vadm;//�����������й���Ա�˺���Ϣ
public:
	MroomBook_Manager();
	void Login(MroomBook_Manager& mm);

	void StudentLogin(MroomBook_Manager& mm);
	void StudentMenu();
};