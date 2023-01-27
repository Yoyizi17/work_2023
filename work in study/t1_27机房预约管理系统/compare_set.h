#pragma once


class Compare_set
{
public:
	bool operator()(const Student& s1,const Student& s2)const
	{
		if (s1.sm_num < s2.sm_num)
			return true;
		else
			return false;
	}

	bool operator()(const BookInformathion& b1, const BookInformathion& b2)const
	{
		if (b1.B_num < b2.B_num||(b1.B_num==b2.B_num&&b1.B_state<b2.B_state))
			return true;
		else
			return false;
	}
};