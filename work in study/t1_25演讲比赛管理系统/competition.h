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
����һ��������.ʵ��   1.��ʼ��ѡ����Ϣ��
                      2.��������š����飬�����е�һ�ֱ�������չʾ�ȷְ񵥡�
					  3.���·��飨��̭���ˣ��������еڶ��ֱ�������չʾ�ȷְ񵥣�������ǰ����������ǰ����д���ĵ���
*/

class Competition
{

private:
	vector<Player> vplayer;//���ѡ����Ϣ
	vector<int> numlist;//��ű��
	vector<pair<int, Player>> num_player;//����ʹѡ�ֺ������Ż��ƽ�ж�Ӧ��ϵ
	vector<vector<pair<int, Player>>> vGroup;//��ά���飬ά������ÿ�ֽ����зֳ���С��

	vector<Histroy> HistroyList;//������������������Ϣ
public:
	Competition();

	void GetHistroy(ifstream& ifs);
	void Init_competion_information();
	int Get_AverageScore();

	void Compe_1();//�ٰ����
	void DispalyHistroty();//��ʾ��ʷ��
	void ClearHistroty();//�����ʷ��¼

	~Competition();
};