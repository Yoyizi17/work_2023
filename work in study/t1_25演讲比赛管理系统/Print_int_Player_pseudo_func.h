#pragma once
#include"player.h"
#include"histroy.h"
class Print_int_Player
{
public:
	void operator()(pair<int, Player>& p)
	{
		cout << "��ţ�" << p.first << "\tѡ������" << p.second.m_name << "\t�÷֣�" << p.second.m_score << endl;
	}
};

class PrintHistroty
{
public:
	void operator()(Histroy& h)
	{
		cout << h.m_rank << "   ��ţ�" << h.m_num << "   ѡ��������" << h.m_name << "   �÷֣�" << h.m_score << endl;
	}
};