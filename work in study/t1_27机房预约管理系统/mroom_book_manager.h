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
#include"book_infomation.h"


#include"compare_set.h"

using namespace std;

#define STUDENT 1
#define TEATHER 2
#define ADMIN 3
#define EXIT 0

#define STUFILE "student.txt"
#define TEAFILE "teacher.txt"
#define BOOKIN "bookin.txt"

class StudentAccManager;
class TeacherAccManager;
class AdminAccManager;
class BookInformathionManager;
class Compare_set2;

class MroomBook_Manager
{
	friend Student;
	friend Teacher;
	friend Admin;
	friend StudentAccManager;
	friend TeacherAccManager;
	friend AdminAccManager;
	friend BookInformathionManager;
protected:
	set<Student, Compare_set> vstu;//用来储存所有学生账号信息
	vector<Teacher> vtea;//用来储存所有老师账号信息
	vector<Admin> vadm;//用来储存所有管理员账号信息
	multiset< BookInformathion, Compare_set> vbook;//用来储存所有预约消息
public:
	MroomBook_Manager();
	void InitALL();//从文件中读取学生、老师、预约信息等
	void Login(MroomBook_Manager& mm);

	void UpdataFile();
//学生接口
	void StudentLogin(MroomBook_Manager& mm);
	void StudentMenu();
	multiset< BookInformathion>::iterator Display_My(MroomBook_Manager& mm, string num); //查看我的预约信息接口
	void Display_All_1(MroomBook_Manager& mm);//查看所有人预约信息接口。（不显示“取消预约”状态的预约信息。）
	void AddBook(MroomBook_Manager& mm, string num);//增加预约信息接口。
	void CancelBook(MroomBook_Manager& mm, string num);//取消预约信息
//老师接口
	void TeacherLogin(MroomBook_Manager& mm);
	void TeacherMenu();
	void AuditBook();//审核预约信息接口
	void Display_All_2();//查看所有人预约信息接口。（显示“取消预约”状态的预约信息。）
//管理员接口
	void AdminLogin(MroomBook_Manager& mm);
	void AdminMenu();
	void AddStudent();
	void AddTeacher();
	void Distorty();
};