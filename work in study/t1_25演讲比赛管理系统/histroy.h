#pragma once
#include<string>

using namespace std;

class PrintHistroty;
class Histroy
{
	friend Competition;
	friend PrintHistroty;
protected:
	string m_rank;
	int m_num;
	string m_name;
	int m_score;
protected:
	Histroy(string rank, int num, string name, int score)
	{
		m_rank = rank;
		m_num = num;
		m_name = name;
		m_score = score;
	}
};