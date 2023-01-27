#include"student_.acc_manager.h"

bool StudentAccManager::Is_accPassTrue(MroomBook_Manager& mm,string& n_num)
{
	cout << "请输入学号或者姓名" << endl;
	string acc_name;
	cin >> acc_name;
	cout << "请输入密码" << endl;
	string acc_password;
	cin >> acc_password;

	auto it = mm.vstu.begin();
	for (; it != mm.vstu.end(); it++)
	{
		if (it->sm_name == acc_name ||
			it->sm_num == acc_name &&
			it->sm_passsword == acc_password)
		{
			system("cls");
			cout << "欢迎使用机房预约系统，" << it->sm_name << "同学！" << endl;
			n_num = acc_name;
			return true;
		}
	}
	cout << "账号或者密码错误" << endl;
	system("pause");
	return false;
}

void StudentAccManager::AddAccount(MroomBook_Manager& mm)
{
	string num;
	string name;
	string password;
	cout << "请输入学号" << endl;
	while (true)
	{
		cin >> num;
		if (!Is_repeat(mm, num))
			cout << "学号已存在，请重新输入：";
		else
			break;
	}
	cout << "请输入姓名" << endl;
	cin >> name;
	cout << "请设置密码" << endl;
	cin >> password;

	mm.vstu.insert(Student(num, name, password));//向储存学生信息的数组中存贮数据

	ofstream ofs(STUFILE, ios::out | ios::app);//向储存学生信息的文件中存储数据
	ofs << num << "   " << name << "   " << password << endl;
	ofs.close();
}

bool StudentAccManager::Is_repeat(MroomBook_Manager& mm, string& num)
{
	for (auto it = mm.vstu.begin(); it != mm.vstu.end(); ++it)
	{
		if (it->sm_num == num)
			return false;
	}
	return true;
}
