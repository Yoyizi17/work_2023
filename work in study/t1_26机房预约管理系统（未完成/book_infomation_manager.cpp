#include"book_infomation_manager.h"

BookInformathionManager::BookInformathionManager(string num, string name, int mroom, int day, int time, int state)
{
	this->B_num = num;
	this->B_name = name;
	this->B_mroom = mroom;
	this->B_day = day;
	this->B_time = time;
	this->B_state = state;
}

void BookInformathionManager::Display_My(MroomBook_Manager& mm,string num)
{
	cout << "���ļ�¼���£�" << endl;

	for (auto it = mm.vstu.begin(); it != mm.vstu.end(); it++)
	{
		if (it->sm_name == num ||
			it->sm_num == num)
		{
			cout << "ѧ�ţ�" << it->sm_num << "    ������" << it->sm_name;

			if (this->B_mroom == 1)cout << "    ԤԼ�Ļ���������1";
			else if (this->B_mroom == 2)cout << "    ԤԼ�Ļ���������2";
			else cout << "    ԤԼ�Ļ�����������";

			switch (this->B_day)
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

			if (this->B_time == 1)cout << "    ԤԼʱ�䣺����";
			else cout << "    ԤԼʱ�䣺����";

			switch (this->B_state)
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
}
