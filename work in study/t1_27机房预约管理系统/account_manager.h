#pragma once
#include<iostream>
#include"mroom_book_manager.h"
using namespace std;

class AccountManager
{
public:
	bool virtual Is_accPassTrue(MroomBook_Manager& mm,string& n_num)
	{
		return 1;
	}
	void virtual AddAccount(MroomBook_Manager& mm) {

	}
	bool virtual Is_repeat(MroomBook_Manager& mm, string name) 
	{
		return 1;
	}
};