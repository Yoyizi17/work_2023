#include "competition.h"

int Rand(int n)
{
	return rand() % n;
}

Competition::Competition()
{
	srand((unsigned int)time(NULL));

	ifstream ifs(FILENAME,ios::in);
	if (!ifs.is_open())
		return;

	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		ifs.close();
		return;
	}
	ifs.close();
	ifs.open(FILENAME, ios::in);
	GetHistroy(ifs);
}

void Competition::GetHistroy(ifstream& ifs)
{
	while (!ifs.eof())
	{
		string rank;
		int num;
		string name;
		int score;
		ifs >> rank >> num >> name >> score;
		if(!ifs.eof())
		    HistroyList.push_back(Histroy(rank, num, name, score));
	}
	ifs.close();
}


int Competition::Get_AverageScore()
{
	set<int> s;
	for (int jj = 0; jj < 10; jj++)
	{
		s.insert(rand() % 41 + 60);
	}
	auto be = ++s.begin();
	auto en = --s.end();
	int score_num = 0;
	while (be != en)
	{
		score_num += *(be++);
	}

	return score_num/8;
}

void Competition::Init_competion_information()
{
	vplayer.clear();
	numlist.clear();
	num_player.clear();
	Player p1("张三", 0);
	Player p2("李四", 0);
	Player p3("王五", 0);
	Player p4("赵六", 0);
	Player p5("余罪", 0);
	Player p6("汪淼", 0);
	Player p7("二狗", 0);
	Player p8("猫蛋", 0);
	Player p9("程心", 0);
	Player px("天明", 0);
	Player px1("罗辑", 0);
	Player px2("庄颜", 0);

	vplayer.push_back(p1);
	vplayer.push_back(p2);
	vplayer.push_back(p3);
	vplayer.push_back(p4);
	vplayer.push_back(p5);
	vplayer.push_back(p6);
	vplayer.push_back(p7);
	vplayer.push_back(p8);
	vplayer.push_back(p9);
	vplayer.push_back(px);
	vplayer.push_back(px1);
	vplayer.push_back(px2);

	random_shuffle(vplayer.begin(), vplayer.end(), pointer_to_unary_function<int, int>(Rand));//随机化选手列表

	//vector<int> numlist = { 10000,10002,10003,10004,10005,10006,10007,10008,10009,10010,10011,10012 };//创建编号列表
	for (int i = 0; i < PLAYSIZE; i++)
	{
		numlist.push_back(i + 10000);
	}
	random_shuffle(numlist.begin(), numlist.end(), pointer_to_unary_function<int, int>(Rand));//随机化编号列表

	auto it = vplayer.begin();//使编号和选手产生平行关系
	for (int i = 0; i < PLAYSIZE; i++, ++it)
	{
		num_player.push_back(make_pair(numlist[i], *it));
	}

}



void Competition::Compe_1()
{
	cout << "新一届演讲比赛开始了！" << endl;

	Init_competion_information();//将编号随机分配给选手，并交由num_player，作为总入选名单维护

	cout << "随机分组完成！---->>" << endl;




	for (int ii = 1; ii <= PLAYSIZE / 6; ii++)//每轮比赛通过循环的方式实现，简化代码
	{
		//将几组人分开，利于对于几组人进行各组排名（按照分数排序）,将几组人交给二维数组维护

		for (int f = 0; f < PLAYSIZE / ii / 6; f++)
		{
			vGroup.push_back(vector<pair<int, Player>>(num_player.begin() + (f * 6), num_player.begin() + ((f + 1) * 6)));
		}
		
		//打印各组
		int jjj = 1;
		for (auto it = vGroup.begin(); it != vGroup.end(); it++)
		{
			cout << "-------------------------------------------" << endl;
			if (vGroup.size() == 1)
				cout << "决赛组" << endl;
			else
			    cout << "第" << jjj << "组：" << endl;
			for_each (it->begin(), it->end(), Print_int_Player());
			jjj++;
		}
		jjj = 0;

		system("pause");


		cout << "----------------------------------------------" << endl;
		cout << "----------------------------------------------" << endl;
		if (ii == PLAYSIZE / 6)
			cout << "决赛！" << endl;
		else
		    cout << "第" << ii << "轮比赛开始！" << endl << endl;

		////随机打分，并且将平均分放到选手信息里
		for (auto it = vGroup.begin(); it != vGroup.end(); it++)
		{
			for (auto vit = it->begin(); vit != it->end(); vit++)
			{
				vit->second.m_score = Get_AverageScore();
			}
		}


		//打印比赛结果（排序和打印同时进行）
		if (ii == PLAYSIZE / 6)
			cout << "决赛结果如下：" << endl;
		else
		    cout << "第" << ii << "轮比赛结果如下：" << endl;

		int iii = 1;
		for (vector<vector<pair<int,Player>>>::iterator it = vGroup.begin(); it != vGroup.end(); it++)
		{
			sort(it->begin(), it->end(), Compare_sort_Player());
			cout << "-------------------------------------------" << endl;
			cout << "第" << iii << "组：" << endl;
			for_each(it->begin(), it->end(), Print_int_Player());
			iii++;
		}
		iii = 0;

		if(num_player.size()>3)
		{
			vector<pair<int, Player>> newc;
			for (auto it = vGroup.begin(); it != vGroup.end(); it++)
			{
				for (auto vit = it->begin(); vit != it->begin() + 3; vit++)
				{
					newc.push_back(*vit);
				}
			}

			num_player = newc;
			vGroup.clear();
		}
		
		system("pause");
	}


	cout << "恭喜以下参赛选手：" << endl;
	auto it = num_player.begin();
	cout << "冠军：" << "   编号：" << it->first << "   选手姓名：" << it->second.m_name << "   得分：" << it->second.m_score << endl; it++;
	cout << "亚军：" << "   编号：" << it->first << "   选手姓名：" << it->second.m_name << "   得分：" << it->second.m_score << endl; it++;
	cout << "季军：" << "   编号：" << it->first << "   选手姓名：" << it->second.m_name << "   得分：" << it->second.m_score << endl;

	it = num_player.begin();
	ofstream ofs(FILENAME, ios::out|ios::app);
	ofs << "冠军" << "   "
		<< it->first << "   "
		<< it->second.m_name << "   "
		<< it->second.m_score << endl; it++;
	ofs << "亚军" << "   "
		<< it->first << "   "
		<< it->second.m_name << "   "
		<< it->second.m_score << endl; it++;
	ofs << "季军" << "   "
		<< it->first << "   "
		<< it->second.m_name << "   "
		<< it->second.m_score << endl;
	ofs.close();


	it = num_player.begin();
	HistroyList.push_back(Histroy("冠军", it->first, it->second.m_name, it->second.m_score)); it++;
	HistroyList.push_back(Histroy("亚军", it->first, it->second.m_name, it->second.m_score)); it++;
	HistroyList.push_back(Histroy("季军", it->first, it->second.m_name, it->second.m_score)); 

	cout << "已保存到历史记录" << endl;
}

void Competition::DispalyHistroty()
{
	if (HistroyList.size() == 0)
	{
		cout << "暂无历史记录" << endl;
		return;
	}
	for_each(HistroyList.begin(), HistroyList.end(), PrintHistroty());
}

void Competition::ClearHistroty()
{
	ofstream ofs(FILENAME, ios::out);
	ofs.close();
	HistroyList.clear();
	cout << "已清空" << endl;
}

Competition::~Competition()
{

}
