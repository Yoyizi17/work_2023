#pragma once
#include"account_manager.h"

class TeacherAccManager : public AccountManager
{
public:
	string name;
	bool  Is_accPassTrue(MroomBook_Manager& mm, string& n_num);
	void  AddAccount(MroomBook_Manager& mm);
	bool Is_repeat(MroomBook_Manager& mm, string& name);
};
