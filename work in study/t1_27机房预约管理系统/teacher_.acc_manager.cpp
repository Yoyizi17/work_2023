#include"teacher_.acc_manager.h"

bool TeacherAccManager::Is_accPassTrue(MroomBook_Manager& mm, string& n_num)
{
	cout << "������ְ���Ż�������" << endl;
	string acc_name;
	cin >> acc_name;
	cout << "����������" << endl;
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
			cout << "��ӭʹ�û���ԤԼϵͳ��" << it->tm_name << "��ʦ��" << endl;
			n_num = acc_name;
			return true;
		}
	}
	cout << "�˺Ż����������" << endl;
	system("pause");
	return false;
}

void TeacherAccManager::AddAccount(MroomBook_Manager& mm)
{
	string num;
	string name;
	string password;
	cout << "������ְ����" << endl;
	while (true)
	{
		cin >> num;
		if (!Is_repeat(mm, num))
			cout << "ְ�����Ѵ��ڣ����������룺";
		else
			break;
	}
	cout << "����������" << endl;
	cin >> name;
	cout << "����������" << endl;
	cin >> password;

	mm.vtea.push_back(Teacher(num, name, password));//�򴢴���ʦ��Ϣ�������д�������

	ofstream ofs(TEAFILE, ios::out | ios::app);//�򴢴���ʦ��Ϣ���ļ��д洢����
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
