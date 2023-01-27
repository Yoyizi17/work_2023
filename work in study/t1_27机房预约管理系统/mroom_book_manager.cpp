#include"mroom_book_manager.h"
#include"student_.acc_manager.h"
#include"teacher_.acc_manager.h"
#include"admin_.acc_manager.h"

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
	vtea.push_back(Teacher("1", "老王", "456"));
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
		cout << "请选择：";
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
			cout << "欢迎下次使用！" << endl;
			break;
		default:
			cout << "输入错误，请重新输入：";
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
	cout << "*        0.退出登录                *" << endl;
	cout << "************************************" << endl;
}

multiset< BookInformathion>::iterator MroomBook_Manager::Display_My(MroomBook_Manager& mm, string num)
{
	cout << "您的记录如下：" << endl;
	int i = 1;
	auto it = mm.vbook.begin();
	for (; it != mm.vbook.end(); it++)
	{
		if (it->B_num == num ||
			it->B_name == num &&
			it->B_state != 3)
		{
			/*cout << "学号：" << it->sm_num << "    姓名：" << it->sm_name;*/
			cout << i << ".";
			if (it->B_state == 1)cout << "    预约的机房：机房1";
			else if (it->B_mroom == 2)cout << "    预约的机房：机房2";
			else cout << "    预约的机房：机房三";

			switch (it->B_day)
			{
			case 1:
				cout << "    预约日期：星期一";
				break;
			case 2:
				cout << "    预约日期：星期二";
				break;
			case 3:
				cout << "    预约日期：星期三";
				break;
			case 4:
				cout << "    预约日期：星期四";
				break;
			case 5:
				cout << "    预约日期：星期五";
				break;
			}

			if (it->B_time == 1)cout << "    预约时间：上午";
			else cout << "    预约时间：下午";

			switch (it->B_state)
			{
			case 1:
				cout << "    审核中" << endl;
				break;
			case 2:
				cout << "    已通过" << endl;
				break;
			case 3:
				cout << "    取消预约" << endl;
				break;
			}
		}
	}
	system("pause");
	return it;
}

void MroomBook_Manager::Display_All_1(MroomBook_Manager& mm)
{
	cout << "所有人的预约信息如下" << endl;
	for (auto it = mm.vbook.begin(); it != mm.vbook.end(); it++)
	{
		if (it->B_state !=3)
		{
			cout << "学号：" << it->B_num << "    姓名：" << it->B_name;

			if (it->B_mroom == 1)cout << "    预约的机房：机房1";
			else if (it->B_mroom == 2)cout << "    预约的机房：机房2";
			else cout << "    预约的机房：机房三";

			switch (it->B_day)
			{
			case 1:
				cout << "    预约日期：星期一";
				break;
			case 2:
				cout << "    预约日期：星期二";
				break;
			case 3:
				cout << "    预约日期：星期三";
				break;
			case 4:
				cout << "    预约日期：星期四";
				break;
			case 5:
				cout << "    预约日期：星期五";
				break;
			}

			if (it->B_time == 1)cout << "    预约时间：上午";
			else cout << "    预约时间：下午";

			switch (it->B_state)
			{
			case 1:
				cout << "    审核中" << endl;
				break;
			case 2:
				cout << "    已通过" << endl;
				break;
			}
		}
	}
	system("pause");
}

void MroomBook_Manager::AddBook(MroomBook_Manager& mm, string num)
{
	auto it = mm.vstu.begin();
	for (; it != mm.vstu.end(); it++)//找到这个学生的姓名和学号，方便创建预约信息
	{
		if (it->sm_name == num || it->sm_num == num)
			break;
	}

	int mroom = 0;
	while (mroom < 1 || mroom>3)
	{
		cout << "你要预约的机房是:" << endl;
		cout << "1.机房 1" << endl;
		cout << "2.机房 2" << endl;
		cout << "3.机房 3" << endl;
		cin >> mroom;
		if (mroom < 1 || mroom>3)
			cout << "输入有误，请重新输入：";
	}

	int day = 0;
	while (day < 1 || day>5)
	{
		cout << "你要预约的日期是：" << endl;
		cout << "1.星期一" << endl;
		cout << "2.星期二" << endl;
		cout << "3.星期三" << endl;
		cout << "4.星期四" << endl;
		cout << "5.星期五" << endl;
		cin >> day;
		if (day < 1 || day>5)
			cout << "输入有误，请重新输入：";
	}

	int time = 0;
	while (time < 1 || time>2)
	{
		cout << "你要预约的时间是：" << endl;
		cout << "1.上午" << endl;
		cout << "2.下午" << endl;
		cin >> time;
		if (time < 1 || time>2)
			cout << "输入有误，请重新输入：";
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
		cout << "你暂时还没有任何可以取消的预约！" << endl;
		return;
	}
	
	for (int i = 1; i <= count; i++, it++)
	{
		cout << i << ".";
		cout << "学号：" << it->B_num << "    姓名：" << it->B_name;

		if (it->B_mroom == 1)cout << "    预约的机房：机房1";
		else if (it->B_mroom == 2)cout << "    预约的机房：机房2";
		else cout << "    预约的机房：机房三";

		switch (it->B_day)
		{
		case 1:
			cout << "    预约日期：星期一";
			break;
		case 2:
			cout << "    预约日期：星期二";
			break;
		case 3:
			cout << "    预约日期：星期三";
			break;
		case 4:
			cout << "    预约日期：星期四";
			break;
		case 5:
			cout << "    预约日期：星期五";
			break;
		}

		if (it->B_time == 1)cout << "    预约时间：上午";
		else cout << "    预约时间：下午";

		switch (it->B_state)
		{
		case 1:
			cout << "    审核中" << endl;
			break;
		case 2:
			cout << "    已通过" << endl;
			break;
		}
	}
	cout << "请选择你要取消的预约：";
	int i = -1;
	while (i < 0 || i > count)
	{
		cin >> i;
		if (i < 0 || i > count)
			cout << "输入不合法，请重新输入：";
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
		TeacherMenu();//打印菜单
		cout << "请选择" << endl;
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
			cout << "输入错误，请重新输入" << endl;
		}
	} while (input);
}

void MroomBook_Manager::TeacherMenu()
{
	cout << "************************************" << endl;
	cout << "*        1.审核预约信息            *" << endl;
	cout << "*        2.查看所有预约信息        *" << endl;
	cout << "*        0.退出登录                *" << endl;
	cout << "************************************" << endl;
}

void MroomBook_Manager::AuditBook()
{
	int exit = 1;
	int count = 0;
	while(exit!=0)
	{
		count = 0;
		cout << "所有人的预约信息如下" << endl;
		for (auto it = vbook.begin(); it != vbook.end(); it++)
		{
			if (it->B_state ==1)
			{
				count++;
				cout << "学号：" << it->B_num << "    姓名：" << it->B_name;

				if (it->B_mroom == 1)cout << "    预约的机房：机房1";
				else if (it->B_mroom == 2)cout << "    预约的机房：机房2";
				else cout << "    预约的机房：机房三";

				switch (it->B_day)
				{
				case 1:
					cout << "    预约日期：星期一";
					break;
				case 2:
					cout << "    预约日期：星期二";
					break;
				case 3:
					cout << "    预约日期：星期三";
					break;
				case 4:
					cout << "    预约日期：星期四";
					break;
				case 5:
					cout << "    预约日期：星期五";
					break;
				}

				if (it->B_time == 1)cout << "    预约时间：上午";
				else cout << "    预约时间：下午";

				switch (it->B_state)
				{
				case 1:
					cout << "    审核中" << endl;
					break;
				case 2:
					cout << "    已通过" << endl;
					break;
				}
			}
		}
		if (count == 0)
		{
			cout << "暂无可以处理的预约信息！" << endl;
			system("pause");
			return;
		}
		
		cout << "请输入你要审核通过的预约信息:";
		auto it = vbook.begin();
		int num = 10000;
		while(num>count)
		{
			cin >> num;
			if (num > count)
			{
				cout << "输入不合法，请重新输入：";
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

		cout << "已通过" << endl;
		cout << "1.继续审核" << endl;
		cout << "0.退出" << endl;

		cin >> exit;
		system("cls");
	}

	this->UpdataFile();
}

void MroomBook_Manager::Display_All_2()
{
	for (auto it = vbook.begin(); it != vbook.end(); it++)
	{ 
		cout << "学号：" << it->B_num << "    姓名：" << it->B_name;

		if (it->B_mroom == 1)cout << "    预约的机房：机房1";
		else if (it->B_mroom == 2)cout << "    预约的机房：机房2";
		else cout << "    预约的机房：机房三";

		switch (it->B_day)
		{
		case 1:
			cout << "    预约日期：星期一";
			break;
		case 2:
			cout << "    预约日期：星期二";
			break;
		case 3:
			cout << "    预约日期：星期三";
			break;
		case 4:
			cout << "    预约日期：星期四";
			break;
		case 5:
			cout << "    预约日期：星期五";
			break;
		}

		if (it->B_time == 1)cout << "    预约时间：上午";
		else cout << "    预约时间：下午";

		switch (it->B_state)
		{
		case 1:
			cout << "    审核中" << endl;
			break;
		case 2:
			cout << "    已通过" << endl;
			break;
		case 3:
			cout << "    取消预约" << endl;
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
		AdminMenu();//打印菜单
		cout << "请选择" << endl;
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
			cout << "输入错误，请重新输入" << endl;
		}
	} while (input);
}

void MroomBook_Manager::AdminMenu()
{
	cout << "************************************" << endl;
	cout << "*        1.新增学生账号            *" << endl;
	cout << "*        2.新增老师账号            *" << endl;
	cout << "*        2.清空预约信息            *" << endl;
	cout << "*        0.退出登录                *" << endl;
	cout << "************************************" << endl;
}

void MroomBook_Manager::AddStudent()
{
	AccountManager* Login = new StudentAccManager;
	Login->AddAccount(*this);
	cout << "创建学生账号成功" << endl;

	system("pause");
}

void MroomBook_Manager::AddTeacher()
{
	AccountManager* Login = new TeacherAccManager;
	Login->AddAccount(*this);
	cout << "创建老师账号成功" << endl;
	system("pause");
}

void MroomBook_Manager::Distorty()
{
	ofstream ofs(BOOKIN, ios::out);
	ofs.close();
	vbook.clear();
	cout << "清除成功" << endl;

	system("pause");
}

