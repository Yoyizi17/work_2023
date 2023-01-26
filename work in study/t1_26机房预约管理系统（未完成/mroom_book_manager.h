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
	set<Student, Compare_set> vstu;//用来储存所有学生账号信息
	vector<Teacher> vtea;//用来储存所有老师账号信息
	vector<Admin> vadm;//用来储存所有管理员账号信息
public:
	MroomBook_Manager();
	void Login(MroomBook_Manager& mm);

	void StudentLogin(MroomBook_Manager& mm);
	void StudentMenu();
};