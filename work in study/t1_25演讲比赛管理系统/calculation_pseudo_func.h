#pragma once
#include"player.h"
class Compare_sort_Player
{
public:
	bool operator()(const pair<int,Player>& p1, const pair<int,Player>& p2)
	{
		if (p1.second.m_score > p2.second.m_score)
			return true;
		else
			return false;
	}
};