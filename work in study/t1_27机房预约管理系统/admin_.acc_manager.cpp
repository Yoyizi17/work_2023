#include"admin_.acc_manager.h"

bool AdminAccManager::Is_accPassTrue(MroomBook_Manager& mm, string& n_num)
{
	cout << "���������Ա�Ż�������" << endl;
	string acc_name;
	cin >> acc_name;
	cout << "����������" << endl;
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
			cout << "��ӭʹ�û���ԤԼϵͳ��" << it->am_name << "������" << endl;
			n_num = acc_name;
			return true;
		}
	}
	cout << "�˺Ż����������" << endl;
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
