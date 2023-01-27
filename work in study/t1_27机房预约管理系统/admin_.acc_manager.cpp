#include"admin_.acc_manager.h"

bool AdminAccManager::Is_accPassTrue(MroomBook_Manager& mm, string& n_num)
{
	cout << "请输入管理员号或者姓名" << endl;
	string acc_name;
	cin >> acc_name;
	cout << "请输入密码" << endl;
	string acc_password;
	cin >> acc_password;

	auto it = mm.vadm.begin();
	for (; it != mm.vadm.end(); it++)
	{
		if (it->am_name == acc_name ||
			it->am_num == acc_name &&
			it->am_passsword == acc_password)
		{
			system("cls");
			cout << "欢迎使用机房预约系统，" << it->am_name << "先生！" << endl;
			n_num = acc_name;
			return true;
		}
	}
	cout << "账号或者密码错误" << endl;
	system("pause");
	return false;
}

void AdminAccManager::AddAccount(MroomBook_Manager& mm)
{
	return;
}

bool AdminAccManager::Is_repeat(MroomBook_Manager& mm, string& name)
{
	return false;
}
