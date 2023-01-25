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
	Player p1("����", 0);
	Player p2("����", 0);
	Player p3("����", 0);
	Player p4("����", 0);
	Player p5("����", 0);
	Player p6("���", 0);
	Player p7("����", 0);
	Player p8("è��", 0);
	Player p9("����", 0);
	Player px("����", 0);
	Player px1("�޼�", 0);
	Player px2("ׯ��", 0);

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

	random_shuffle(vplayer.begin(), vplayer.end(), pointer_to_unary_function<int, int>(Rand));//�����ѡ���б�

	//vector<int> numlist = { 10000,10002,10003,10004,10005,10006,10007,10008,10009,10010,10011,10012 };//��������б�
	for (int i = 0; i < PLAYSIZE; i++)
	{
		numlist.push_back(i + 10000);
	}
	random_shuffle(numlist.begin(), numlist.end(), pointer_to_unary_function<int, int>(Rand));//���������б�

	auto it = vplayer.begin();//ʹ��ź�ѡ�ֲ���ƽ�й�ϵ
	for (int i = 0; i < PLAYSIZE; i++, ++it)
	{
		num_player.push_back(make_pair(numlist[i], *it));
	}

}



void Competition::Compe_1()
{
	cout << "��һ���ݽ�������ʼ�ˣ�" << endl;

	Init_competion_information();//�������������ѡ�֣�������num_player����Ϊ����ѡ����ά��

	cout << "���������ɣ�---->>" << endl;




	for (int ii = 1; ii <= PLAYSIZE / 6; ii++)//ÿ�ֱ���ͨ��ѭ���ķ�ʽʵ�֣��򻯴���
	{
		//�������˷ֿ������ڶ��ڼ����˽��и������������շ�������,�������˽�����ά����ά��

		for (int f = 0; f < PLAYSIZE / ii / 6; f++)
		{
			vGroup.push_back(vector<pair<int, Player>>(num_player.begin() + (f * 6), num_player.begin() + ((f + 1) * 6)));
		}
		
		//��ӡ����
		int jjj = 1;
		for (auto it = vGroup.begin(); it != vGroup.end(); it++)
		{
			cout << "-------------------------------------------" << endl;
			if (vGroup.size() == 1)
				cout << "������" << endl;
			else
			    cout << "��" << jjj << "�飺" << endl;
			for_each (it->begin(), it->end(), Print_int_Player());
			jjj++;
		}
		jjj = 0;

		system("pause");


		cout << "----------------------------------------------" << endl;
		cout << "----------------------------------------------" << endl;
		if (ii == PLAYSIZE / 6)
			cout << "������" << endl;
		else
		    cout << "��" << ii << "�ֱ�����ʼ��" << endl << endl;

		////�����֣����ҽ�ƽ���ַŵ�ѡ����Ϣ��
		for (auto it = vGroup.begin(); it != vGroup.end(); it++)
		{
			for (auto vit = it->begin(); vit != it->end(); vit++)
			{
				vit->second.m_score = Get_AverageScore();
			}
		}


		//��ӡ�������������ʹ�ӡͬʱ���У�
		if (ii == PLAYSIZE / 6)
			cout << "����������£�" << endl;
		else
		    cout << "��" << ii << "�ֱ���������£�" << endl;

		int iii = 1;
		for (vector<vector<pair<int,Player>>>::iterator it = vGroup.begin(); it != vGroup.end(); it++)
		{
			sort(it->begin(), it->end(), Compare_sort_Player());
			cout << "-------------------------------------------" << endl;
			cout << "��" << iii << "�飺" << endl;
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


	cout << "��ϲ���²���ѡ�֣�" << endl;
	auto it = num_player.begin();
	cout << "�ھ���" << "   ��ţ�" << it->first << "   ѡ��������" << it->second.m_name << "   �÷֣�" << it->second.m_score << endl; it++;
	cout << "�Ǿ���" << "   ��ţ�" << it->first << "   ѡ��������" << it->second.m_name << "   �÷֣�" << it->second.m_score << endl; it++;
	cout << "������" << "   ��ţ�" << it->first << "   ѡ��������" << it->second.m_name << "   �÷֣�" << it->second.m_score << endl;

	it = num_player.begin();
	ofstream ofs(FILENAME, ios::out|ios::app);
	ofs << "�ھ�" << "   "
		<< it->first << "   "
		<< it->second.m_name << "   "
		<< it->second.m_score << endl; it++;
	ofs << "�Ǿ�" << "   "
		<< it->first << "   "
		<< it->second.m_name << "   "
		<< it->second.m_score << endl; it++;
	ofs << "����" << "   "
		<< it->first << "   "
		<< it->second.m_name << "   "
		<< it->second.m_score << endl;
	ofs.close();


	it = num_player.begin();
	HistroyList.push_back(Histroy("�ھ�", it->first, it->second.m_name, it->second.m_score)); it++;
	HistroyList.push_back(Histroy("�Ǿ�", it->first, it->second.m_name, it->second.m_score)); it++;
	HistroyList.push_back(Histroy("����", it->first, it->second.m_name, it->second.m_score)); 

	cout << "�ѱ��浽��ʷ��¼" << endl;
}

void Competition::DispalyHistroty()
{
	if (HistroyList.size() == 0)
	{
		cout << "������ʷ��¼" << endl;
		return;
	}
	for_each(HistroyList.begin(), HistroyList.end(), PrintHistroty());
}

void Competition::ClearHistroty()
{
	ofstream ofs(FILENAME, ios::out);
	ofs.close();
	HistroyList.clear();
	cout << "�����" << endl;
}

Competition::~Competition()
{

}
