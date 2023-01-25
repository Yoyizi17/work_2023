#pragma once
#include<iostream>
#include<fstream>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<functional>

#include"player.h"
#include"calculation_pseudo_func.h"
#include"Print_int_Player_pseudo_func.h"
#include"histroy.h"
using namespace std;

#define PLAYSIZE 12
#define FILENAME "history.txt"

/*
创建一个比赛类.实现   1.初始化选手信息。
                      2.随机分配编号。分组，并进行第一轮比赛，并展示比分榜单。
					  3.重新分组（淘汰六人），并进行第二轮比赛，并展示比分榜单，并恭贺前三名，并将前三名写入文档。
*/

class Competition
{

private:
	vector<Player> vplayer;//存放选手信息
	vector<int> numlist;//存放编号
	vector<pair<int, Player>> num_player;//用来使选手和随机编号获得平行对应关系
	vector<vector<pair<int, Player>>> vGroup;//二维数组，维护比赛每轮进行中分出的小组

	vector<Histroy> HistroyList;//用来储存历代获奖者信息
public:
	Competition();

	void GetHistroy(ifstream& ifs);
	void Init_competion_information();
	int Get_AverageScore();

	void Compe_1();//举办比赛
	void DispalyHistroty();//显示历史榜单
	void ClearHistroty();//清空历史记录

	~Competition();
};