#include"mroom_book_manager.h"
#include"student_.acc_manager.h"
#include"teacher_.acc_manager.h"
#include"admin_.acc_manager.h"

void mune()
{
	cout << "******************************" << endl;
	cout << "*    ��ӭʹ�û���ԤԼϵͳ    *" << endl;
	cout << "*        1.ѧ����½          *" << endl;
	cout << "*        2.��ʦ��½          *" << endl;
	cout << "*        3.����Ա��½        *" << endl;
	cout << "*        0.�˳�ϵͳ          *" << endl;
	cout << "******************************" << endl;
}

MroomBook_Manager::MroomBook_Manager()
{
	vstu.insert(Student("1", "����", "123"));
	vtea.push_back(Teacher("1", "����", "456"));
	vadm.push_back(Admin("1","kkk", "123456"));
}

void MroomBook_Manager::InitALL()
{
	ifstream ifs(STUFILE, ios::in);
	if (!ifs.is_open());
	else
	{
		char c;
		ifs >> c;
		while (!ifs.eof())
		{
			ifs.putback(c);
			string num;
			string name;
			string password;
			ifs >> num;
			ifs >> name;
			ifs >> password;
			vstu.insert(Student(num, name, password));
			ifs >> c;
		}
		ifs.close();
	}

	ifstream ifs1(TEAFILE, ios::in);
	if (!ifs1.is_open());
	else
	{
		char c;
		ifs1 >> c;
		while (!ifs1.eof())
		{
			ifs1.putback(c);
			string num;
			string name;
			string password;
			ifs1 >> num;
			ifs1 >> name;
			ifs1 >> password;
			vtea.push_back(Teacher(num, name, password));
			ifs1 >> c;
		}
		ifs1.close();
	}

	ifstream ifs2(BOOKIN, ios::in);
	if (!ifs2.is_open());
	else
	{
		char c;
		ifs2 >> c;
		while (!ifs2.eof())
		{
			ifs2.putback(c);
			string num;
			string name;
			int mroom;
			int day;
			int time;
			int state;
			ifs2 >> num;
			ifs2 >> name;
			ifs2 >> mroom;
			ifs2 >> day;
			ifs2 >> time;
			ifs2 >> state;
			vbook.insert(BookInformathion(num, name, mroom,day,time,state));
			ifs2 >> c;
		}
		ifs2.close();
	}
}

void MroomBook_Manager::Login(MroomBook_Manager& mm)
{
	
	int input;
	this->InitALL();
	do
	{
		mune();
		cout << "��ѡ��";
		cin >> input;
		switch (input)
		{
		case STUDENT:
			mm.StudentLogin(mm);
			system("cls");
			break;
		case TEATHER:
			mm.TeacherLogin(mm);
			break;
		case ADMIN:
			mm.AdminLogin(mm);
			break;
		case EXIT:
			cout << "��ӭ�´�ʹ�ã�" << endl;
			break;
		default:
			cout << "����������������룺";
			break;
		}
	} while (input);
}

void MroomBook_Manager::UpdataFile()
{
	ofstream ofs(BOOKIN, ios::out);
	for (auto it = vbook.begin(); it != vbook.end(); it++)
	{
		ofs << it->B_num << "   " << it->B_name << "   " << it->B_mroom << "   " << it->B_day << "   " << it->B_time << "   " << it->B_state << endl;
	}
	ofs.close();
}

void MroomBook_Manager::StudentLogin(MroomBook_Manager& mm)
{
	string num;//������¼���ѧ����ѧ�Ż���������
	AccountManager* Login = new  StudentAccManager;
	if (!Login->Is_accPassTrue(mm,num))
		return;

	int input;
	do
	{
		StudentMenu();//��ӡ�˵�
		cout << "��ѡ��" << endl;
		cin >> input;
		switch (input)
		{
		case 1:
			mm.Display_My(mm,num);
			system("cls");
			break;
		case 2:
			mm.Display_All_1(mm);
			system("cls");
			break;
		case 3:
			mm.AddBook(mm,num);
			system("cls");
			break;
		case 4:
			CancelBook(mm, num);
			system("cls");
			break;
		case 0:
			break;
		default:
			cout << "�����������������" << endl;
		}
	} while (input);
}

void MroomBook_Manager::StudentMenu()
{
	cout << "************************************" << endl;
	cout << "*        1.�鿴�ҵ�ԤԼ��Ϣ        *" << endl;
	cout << "*        2.�鿴����ԤԼ��Ϣ        *" << endl;
	cout << "*        3.�����ҵ�ԤԼ            *" << endl;
	cout << "*        4.ȡ���ҵ�ԤԼ            *" << endl;
	cout << "*        0.�˳���¼                *" << endl;
	cout << "************************************" << endl;
}

multiset< BookInformathion>::iterator MroomBook_Manager::Display_My(MroomBook_Manager& mm, string num)
{
	cout << "���ļ�¼���£�" << endl;
	int i = 1;
	auto it = mm.vbook.begin();
	for (; it != mm.vbook.end(); it++)
	{
		if (it->B_num == num ||
			it->B_name == num &&
			it->B_state != 3)
		{
			/*cout << "ѧ�ţ�" << it->sm_num << "    ������" << it->sm_name;*/
			cout << i << ".";
			if (it->B_state == 1)cout << "    ԤԼ�Ļ���������1";
			else if (it->B_mroom == 2)cout << "    ԤԼ�Ļ���������2";
			else cout << "    ԤԼ�Ļ�����������";

			switch (it->B_day)
			{
			case 1:
				cout << "    ԤԼ���ڣ�����һ";
				break;
			case 2:
				cout << "    ԤԼ���ڣ����ڶ�";
				break;
			case 3:
				cout << "    ԤԼ���ڣ�������";
				break;
			case 4:
				cout << "    ԤԼ���ڣ�������";
				break;
			case 5:
				cout << "    ԤԼ���ڣ�������";
				break;
			}

			if (it->B_time == 1)cout << "    ԤԼʱ�䣺����";
			else cout << "    ԤԼʱ�䣺����";

			switch (it->B_state)
			{
			case 1:
				cout << "    �����" << endl;
				break;
			case 2:
				cout << "    ��ͨ��" << endl;
				break;
			case 3:
				cout << "    ȡ��ԤԼ" << endl;
				break;
			}
		}
	}
	system("pause");
	return it;
}

void MroomBook_Manager::Display_All_1(MroomBook_Manager& mm)
{
	cout << "�����˵�ԤԼ��Ϣ����" << endl;
	for (auto it = mm.vbook.begin(); it != mm.vbook.end(); it++)
	{
		if (it->B_state !=3)
		{
			cout << "ѧ�ţ�" << it->B_num << "    ������" << it->B_name;

			if (it->B_mroom == 1)cout << "    ԤԼ�Ļ���������1";
			else if (it->B_mroom == 2)cout << "    ԤԼ�Ļ���������2";
			else cout << "    ԤԼ�Ļ�����������";

			switch (it->B_day)
			{
			case 1:
				cout << "    ԤԼ���ڣ�����һ";
				break;
			case 2:
				cout << "    ԤԼ���ڣ����ڶ�";
				break;
			case 3:
				cout << "    ԤԼ���ڣ�������";
				break;
			case 4:
				cout << "    ԤԼ���ڣ�������";
				break;
			case 5:
				cout << "    ԤԼ���ڣ�������";
				break;
			}

			if (it->B_time == 1)cout << "    ԤԼʱ�䣺����";
			else cout << "    ԤԼʱ�䣺����";

			switch (it->B_state)
			{
			case 1:
				cout << "    �����" << endl;
				break;
			case 2:
				cout << "    ��ͨ��" << endl;
				break;
			}
		}
	}
	system("pause");
}

void MroomBook_Manager::AddBook(MroomBook_Manager& mm, string num)
{
	auto it = mm.vstu.begin();
	for (; it != mm.vstu.end(); it++)//�ҵ����ѧ����������ѧ�ţ����㴴��ԤԼ��Ϣ
	{
		if (it->sm_name == num || it->sm_num == num)
			break;
	}

	int mroom = 0;
	while (mroom < 1 || mroom>3)
	{
		cout << "��ҪԤԼ�Ļ�����:" << endl;
		cout << "1.���� 1" << endl;
		cout << "2.���� 2" << endl;
		cout << "3.���� 3" << endl;
		cin >> mroom;
		if (mroom < 1 || mroom>3)
			cout << "�����������������룺";
	}

	int day = 0;
	while (day < 1 || day>5)
	{
		cout << "��ҪԤԼ�������ǣ�" << endl;
		cout << "1.����һ" << endl;
		cout << "2.���ڶ�" << endl;
		cout << "3.������" << endl;
		cout << "4.������" << endl;
		cout << "5.������" << endl;
		cin >> day;
		if (day < 1 || day>5)
			cout << "�����������������룺";
	}

	int time = 0;
	while (time < 1 || time>2)
	{
		cout << "��ҪԤԼ��ʱ���ǣ�" << endl;
		cout << "1.����" << endl;
		cout << "2.����" << endl;
		cin >> time;
		if (time < 1 || time>2)
			cout << "�����������������룺";
	}

	mm.vbook.insert(BookInformathion(it->sm_num, it->sm_name, mroom, day, time, 1));

	ofstream ofs(BOOKIN, ios::out | ios::app);
	ofs << it->sm_num << "   " << it->sm_name << "   " << mroom << "   " << day << "   " << time << "   " << 1 << endl;
	ofs.close();
}

void MroomBook_Manager::CancelBook(MroomBook_Manager& mm, string num)
{
	
	auto it = mm.vbook.find(BookInformathion("1", num, 1, 1, 1, 1));
	int count = mm.vbook.count(BookInformathion("1", num, 1, 1, 1, 1));
	auto temp = it;

	if (count == 0)
	{
		cout << "����ʱ��û���κο���ȡ����ԤԼ��" << endl;
		return;
	}
	
	for (int i = 1; i <= count; i++, it++)
	{
		cout << i << ".";
		cout << "ѧ�ţ�" << it->B_num << "    ������" << it->B_name;

		if (it->B_mroom == 1)cout << "    ԤԼ�Ļ���������1";
		else if (it->B_mroom == 2)cout << "    ԤԼ�Ļ���������2";
		else cout << "    ԤԼ�Ļ�����������";

		switch (it->B_day)
		{
		case 1:
			cout << "    ԤԼ���ڣ�����һ";
			break;
		case 2:
			cout << "    ԤԼ���ڣ����ڶ�";
			break;
		case 3:
			cout << "    ԤԼ���ڣ�������";
			break;
		case 4:
			cout << "    ԤԼ���ڣ�������";
			break;
		case 5:
			cout << "    ԤԼ���ڣ�������";
			break;
		}

		if (it->B_time == 1)cout << "    ԤԼʱ�䣺����";
		else cout << "    ԤԼʱ�䣺����";

		switch (it->B_state)
		{
		case 1:
			cout << "    �����" << endl;
			break;
		case 2:
			cout << "    ��ͨ��" << endl;
			break;
		}
	}
	cout << "��ѡ����Ҫȡ����ԤԼ��";
	int i = -1;
	while (i < 0 || i > count)
	{
		cin >> i;
		if (i < 0 || i > count)
			cout << "���벻�Ϸ������������룺";
	}
	for (; i > 1; temp++)
	{
		i--;
	}
	
	BookInformathion btemp = *temp;
	btemp.B_state = 3;
	mm.vbook.erase(temp);
	mm.vbook.insert(btemp);

	this->UpdataFile();
}

void MroomBook_Manager::TeacherLogin(MroomBook_Manager& mm)
{
	string num;
	AccountManager* Login = new  TeacherAccManager;
	if (!Login->Is_accPassTrue(mm, num))
		return;

	system("cls");


	int input;
	do
	{
		TeacherMenu();//��ӡ�˵�
		cout << "��ѡ��" << endl;
		cin >> input;
		switch (input)
		{
		case 1:
			this->AuditBook();
			system("cls");
			break;
		case 2:
			this->Display_All_2();
			system("cls");
			break;
		case 0:
			break;
		default:
			cout << "�����������������" << endl;
		}
	} while (input);
}

void MroomBook_Manager::TeacherMenu()
{
	cout << "************************************" << endl;
	cout << "*        1.���ԤԼ��Ϣ            *" << endl;
	cout << "*        2.�鿴����ԤԼ��Ϣ        *" << endl;
	cout << "*        0.�˳���¼                *" << endl;
	cout << "************************************" << endl;
}

void MroomBook_Manager::AuditBook()
{
	int exit = 1;
	int count = 0;
	while(exit!=0)
	{
		count = 0;
		cout << "�����˵�ԤԼ��Ϣ����" << endl;
		for (auto it = vbook.begin(); it != vbook.end(); it++)
		{
			if (it->B_state ==1)
			{
				count++;
				cout << "ѧ�ţ�" << it->B_num << "    ������" << it->B_name;

				if (it->B_mroom == 1)cout << "    ԤԼ�Ļ���������1";
				else if (it->B_mroom == 2)cout << "    ԤԼ�Ļ���������2";
				else cout << "    ԤԼ�Ļ�����������";

				switch (it->B_day)
				{
				case 1:
					cout << "    ԤԼ���ڣ�����һ";
					break;
				case 2:
					cout << "    ԤԼ���ڣ����ڶ�";
					break;
				case 3:
					cout << "    ԤԼ���ڣ�������";
					break;
				case 4:
					cout << "    ԤԼ���ڣ�������";
					break;
				case 5:
					cout << "    ԤԼ���ڣ�������";
					break;
				}

				if (it->B_time == 1)cout << "    ԤԼʱ�䣺����";
				else cout << "    ԤԼʱ�䣺����";

				switch (it->B_state)
				{
				case 1:
					cout << "    �����" << endl;
					break;
				case 2:
					cout << "    ��ͨ��" << endl;
					break;
				}
			}
		}
		if (count == 0)
		{
			cout << "���޿��Դ����ԤԼ��Ϣ��" << endl;
			system("pause");
			return;
		}
		
		cout << "��������Ҫ���ͨ����ԤԼ��Ϣ:";
		auto it = vbook.begin();
		int num = 10000;
		while(num>count)
		{
			cin >> num;
			if (num > count)
			{
				cout << "���벻�Ϸ������������룺";
				continue;
			}

			while (num > 1)
			{
				while (it->B_state != 1&&it!=vbook.end())
				{
					it++;
				}
				num--;
				it++;
			}
		}

		BookInformathion btemp = *it;
		btemp.B_state = 2;
		vbook.erase(it);
		vbook.insert(btemp);

		cout << "��ͨ��" << endl;
		cout << "1.�������" << endl;
		cout << "0.�˳�" << endl;

		cin >> exit;
		system("cls");
	}

	this->UpdataFile();
}

void MroomBook_Manager::Display_All_2()
{
	for (auto it = vbook.begin(); it != vbook.end(); it++)
	{ 
		cout << "ѧ�ţ�" << it->B_num << "    ������" << it->B_name;

		if (it->B_mroom == 1)cout << "    ԤԼ�Ļ���������1";
		else if (it->B_mroom == 2)cout << "    ԤԼ�Ļ���������2";
		else cout << "    ԤԼ�Ļ�����������";

		switch (it->B_day)
		{
		case 1:
			cout << "    ԤԼ���ڣ�����һ";
			break;
		case 2:
			cout << "    ԤԼ���ڣ����ڶ�";
			break;
		case 3:
			cout << "    ԤԼ���ڣ�������";
			break;
		case 4:
			cout << "    ԤԼ���ڣ�������";
			break;
		case 5:
			cout << "    ԤԼ���ڣ�������";
			break;
		}

		if (it->B_time == 1)cout << "    ԤԼʱ�䣺����";
		else cout << "    ԤԼʱ�䣺����";

		switch (it->B_state)
		{
		case 1:
			cout << "    �����" << endl;
			break;
		case 2:
			cout << "    ��ͨ��" << endl;
			break;
		case 3:
			cout << "    ȡ��ԤԼ" << endl;
		}
	}
	system("pause");
}

void MroomBook_Manager::AdminLogin(MroomBook_Manager& mm)
{
	string num;
	AccountManager* Login = new AdminAccManager;
	if (!Login->Is_accPassTrue(mm, num))
		return;

	system("cls");

	int input;
	do
	{
		AdminMenu();//��ӡ�˵�
		cout << "��ѡ��" << endl;
		cin >> input;
		switch (input)
		{
		case 1:
			this->AddStudent();
			system("cls");
			break;
		case 2:
			this->AddTeacher();
			system("cls");
			break;
		case 3:
			this->Distorty();
		case 0:
			break;
		default:
			cout << "�����������������" << endl;
		}
	} while (input);
}

void MroomBook_Manager::AdminMenu()
{
	cout << "************************************" << endl;
	cout << "*        1.����ѧ���˺�            *" << endl;
	cout << "*        2.������ʦ�˺�            *" << endl;
	cout << "*        2.���ԤԼ��Ϣ            *" << endl;
	cout << "*        0.�˳���¼                *" << endl;
	cout << "************************************" << endl;
}

void MroomBook_Manager::AddStudent()
{
	AccountManager* Login = new StudentAccManager;
	Login->AddAccount(*this);
	cout << "����ѧ���˺ųɹ�" << endl;

	system("pause");
}

void MroomBook_Manager::AddTeacher()
{
	AccountManager* Login = new TeacherAccManager;
	Login->AddAccount(*this);
	cout << "������ʦ�˺ųɹ�" << endl;
	system("pause");
}

void MroomBook_Manager::Distorty()
{
	ofstream ofs(BOOKIN, ios::out);
	ofs.close();
	vbook.clear();
	cout << "����ɹ�" << endl;

	system("pause");
}

