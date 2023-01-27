#include"teacher_.acc_manager.h"

bool TeacherAccManager::Is_accPassTrue(MroomBook_Manager& mm, string& n_num)
{
	cout << "请输入职工号或者姓名" << endl;
	string acc_name;
	cin >> acc_name;
	cout << "请输入密码" << endl;
	string acc_password;
	cin >> acc_password;

	auto it = mm.vtea.begin();
	for (; it != mm.vtea.end(); it++)
	{
		if (it->tm_name == acc_name ||
			it->tm_num == acc_name &&
			it->tm_passsword == acc_password)
		{
			system("cls");
			cout << "欢迎使用机房预约系统，" << it->tm_name << "老师！" << endl;
			n_num = acc_name;
			return true;
		}
	}
	cout << "账号或者密码错误" << endl;
	system("pause");
	return false;
}

void TeacherAccManager::AddAccount(MroomBook_Manager& mm)
{
	string num;
	string name;
	string password;
	cout << "请输入职工号" << endl;
	while (true)
	{
		cin >> num;
		if (!Is_repeat(mm, num))
			cout << "职工号已存在，请重新输入：";
		else
			break;
	}
	cout << "请输入姓名" << endl;
	cin >> name;
	cout << "请设置密码" << endl;
	cin >> password;

	mm.vtea.push_back(Teacher(num, name, password));//向储存老师信息的数组中存贮数据

	ofstream ofs(TEAFILE, ios::out | ios::app);//向储存老师信息的文件中存储数据
	ofs << num << "   " << name << "   " << password << endl;
	ofs.close();
}

bool TeacherAccManager::Is_repeat(MroomBook_Manager& mm, string& num)
{
	for (auto it = mm.vtea.begin(); it != mm.vtea.end(); ++it)
	{
		if (it->tm_num == num)
			return false;
	}
	return true;
}
