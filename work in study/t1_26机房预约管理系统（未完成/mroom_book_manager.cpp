#include"mroom_book_manager.h"
#include"student_.acc_manager.h"

void mune()
{
	cout << "******************************" << endl;
	cout << "*    欢迎使用机房预约系统    *" << endl;
	cout << "*        1.学生登陆          *" << endl;
	cout << "*        2.老师登陆          *" << endl;
	cout << "*        3.管理员登陆        *" << endl;
	cout << "*        0.退出系统          *" << endl;
	cout << "******************************" << endl;
}

MroomBook_Manager::MroomBook_Manager()
{
	vstu.insert(Student("1", "张三", "123"));
}

void MroomBook_Manager::Login(MroomBook_Manager& mm)
{
	
	int input;

	do
	{
		mune();
		cout << "请选择：";
		cin >> input;
		switch (input)
		{
		case STUDENT:
			mm.StudentLogin(mm);
			system("cls");
			break;
		case TEATHER:
			break;
		case ADMIN:
			break;
		case EXIT:
			cout << "欢迎下次使用！" << endl;
			break;
		default:
			cout << "输入错误，请重新输入：";
			break;
		}
	} while (input);
}

void MroomBook_Manager::StudentLogin(MroomBook_Manager& mm)
{
	string num;//用来记录这个学生的学号或者姓名。
	AccountManager* Login = new  StudentAccManager;
	if (!Login->Is_accPassTrue(mm,num))
		return;
	int input;
	do
	{
		StudentMenu();//打印菜单
		cout << "请选择" << endl;
		cin >> input;
		switch (input)
		{
		case 1:
			cout << "已执行 1" << endl;
			break;
		case 2:
			cout << "已执行 2" << endl;
			break;
		case 3:
			cout << "已执行 3" << endl;
			break;
		case 4:
			cout << "已执行 4" << endl;
			break;
		case 0:
			break;
		default:
			cout << "输入错误，请重新输入" << endl;
		}
	} while (input);
}

void MroomBook_Manager::StudentMenu()
{
	cout << "************************************" << endl;
	cout << "*        1.查看我的预约信息        *" << endl;
	cout << "*        2.查看所有预约信息        *" << endl;
	cout << "*        3.新增我的预约            *" << endl;
	cout << "*        4.取消我的预约            *" << endl;
	cout << "*        0.退出系统                *" << endl;
	cout << "************************************" << endl;
}
