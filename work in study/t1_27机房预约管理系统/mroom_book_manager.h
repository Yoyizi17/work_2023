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
	set<Student, Compare_set> vstu;//������������ѧ���˺���Ϣ
	vector<Teacher> vtea;//��������������ʦ�˺���Ϣ
	vector<Admin> vadm;//�����������й���Ա�˺���Ϣ
	multiset< BookInformathion, Compare_set> vbook;//������������ԤԼ��Ϣ
public:
	MroomBook_Manager();
	void InitALL();//���ļ��ж�ȡѧ������ʦ��ԤԼ��Ϣ��
	void Login(MroomBook_Manager& mm);

	void UpdataFile();
//ѧ���ӿ�
	void StudentLogin(MroomBook_Manager& mm);
	void StudentMenu();
	multiset< BookInformathion>::iterator Display_My(MroomBook_Manager& mm, string num); //�鿴�ҵ�ԤԼ��Ϣ�ӿ�
	void Display_All_1(MroomBook_Manager& mm);//�鿴������ԤԼ��Ϣ�ӿڡ�������ʾ��ȡ��ԤԼ��״̬��ԤԼ��Ϣ����
	void AddBook(MroomBook_Manager& mm, string num);//����ԤԼ��Ϣ�ӿڡ�
	void CancelBook(MroomBook_Manager& mm, string num);//ȡ��ԤԼ��Ϣ
//��ʦ�ӿ�
	void TeacherLogin(MroomBook_Manager& mm);
	void TeacherMenu();
	void AuditBook();//���ԤԼ��Ϣ�ӿ�
	void Display_All_2();//�鿴������ԤԼ��Ϣ�ӿڡ�����ʾ��ȡ��ԤԼ��״̬��ԤԼ��Ϣ����
//����Ա�ӿ�
	void AdminLogin(MroomBook_Manager& mm);
	void AdminMenu();
	void AddStudent();
	void AddTeacher();
	void Distorty();
};