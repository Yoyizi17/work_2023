#pragma once
#include"student.h"

class Student;

class Compare_set
{
	friend Student;
public:
	bool operator()(const Student& s1,const Student& s2)const
	{
		if (s1.sm_num < s2.sm_num)
			return true;
		else
			return false;
	}
};