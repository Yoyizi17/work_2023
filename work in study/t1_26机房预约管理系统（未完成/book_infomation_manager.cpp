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
	cout << "您的记录如下：" << endl;

	for (auto it = mm.vstu.begin(); it != mm.vstu.end(); it++)
	{
		if (it->sm_name == num ||
			it->sm_num == num)
		{
			cout << "学号：" << it->sm_num << "    姓名：" << it->sm_name;

			if (this->B_mroom == 1)cout << "    预约的机房：机房1";
			else if (this->B_mroom == 2)cout << "    预约的机房：机房2";
			else cout << "    预约的机房：机房三";

			switch (this->B_day)
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

			if (this->B_time == 1)cout << "    预约时间：上午";
			else cout << "    预约时间：下午";

			switch (this->B_state)
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
}
