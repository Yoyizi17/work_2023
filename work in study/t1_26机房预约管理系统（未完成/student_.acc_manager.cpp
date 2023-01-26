#include"student_.acc_manager.h"

bool StudentAccManager::Is_accPassTrue(MroomBook_Manager& mm,string& n_num)
{
	cout << "������ѧ�Ż�������" << endl;
	string acc_name;
	cin >> acc_name;
	cout << "����������" << endl;
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
			cout << "��ӭʹ�û���ԤԼϵͳ��" << it->sm_name << "ͬѧ��" << endl;
			n_num = acc_name;
			return true;
		}
	}
	cout << "�˺Ż����������" << endl;
	system("pause");
	return false;
}

void StudentAccManager::AddAccount(MroomBook_Manager& mm)
{
	string num;
	string name;
	string password;
	cout << "������ѧ��" << endl;
	while (true)
	{
		cin >> num;
		if (!Is_repeat(mm, num))
			cout << "ѧ���Ѵ��ڣ����������룺";
		else
			break;
	}
	cout << "����������" << endl;
	cin >> name;
	cout << "����������" << endl;
	cin >> password;

	mm.vstu.insert(Student(num, name, password));//�򴢴�ѧ����Ϣ�������д�������

	ofstream ofs(STUFILE, ios::out | ios::app);//�򴢴�ѧ����Ϣ���ļ��д洢����
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
