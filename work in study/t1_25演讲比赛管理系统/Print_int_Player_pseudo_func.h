#pragma once
#include"player.h"
#include"histroy.h"
class Print_int_Player
{
public:
	void operator()(pair<int, Player>& p)
	{
		cout << "编号：" << p.first << "\t选手姓名" << p.second.m_name << "\t得分：" << p.second.m_score << endl;
	}
};

class PrintHistroty
{
public:
	void operator()(Histroy& h)
	{
		cout << h.m_rank << "   编号：" << h.m_num << "   选手姓名：" << h.m_name << "   得分：" << h.m_score << endl;
	}
};