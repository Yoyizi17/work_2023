#include<iostream>
using namespace std;
#include<string>
#include<vector>
#include<map>
#include<algorithm>

class Person
{
public:
	string m_name;
	int m_age;

	Person(string name, int age)
	{
		m_name = name;
		m_age = age;
	}

	
};

class BIJIAO
{
public:
	bool operator()(const Person& p)
	{
		if (40<p.m_age)
			return true;
		else
			return false;
	}
};

int main()
{
	vector<Person> v;
	Person p1("����", 10);
	Person p2("����", 20);
	Person p3("����", 33);
	Person p4("����", 44);
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);


	vector<Person>::iterator it = find_if(v.begin(), v.end(), BIJIAO());
	if (it == v.end())
		cout << "�Ҳ���";
	else

	{
		cout << "�ҵ��ˣ�" << it->m_name << "  " << it->m_age;
	}
	return 0;
}

//class Print
//{
//public:
//	void operator()(int val)
//	{
//		cout << val << "  ";
//	}
//};
//
//class Trans
//{
//public:
//	int operator()(int val)
//	{
//		return val*2;
//	}
//};
//
//int main()
//{
//	vector<int> v1;
//	for (int i = 0; i < 10; i++)
//	{
//		v1.push_back(i);
//	}
//
//	vector<int> v2;
//	v2.resize(v1.size());
//
//	transform(v1.begin(), v1.end(), v2.begin(),Trans());
//	for_each(v2.begin(), v2.end(), Print());
//	return 0;
//}

//class Is_wanna
//{
//public:
//	bool operator()(int val)
//	{
//		if (val > 5)
//			return true;
//		else
//			return false;
//	}
//};
//
//int main()
//{
//	/*vector<int> v;
//	for (int i = 0; i < 10; i++)
//	{
//		v.push_back(i);
//	}
//
//	vector<int>::iterator it = find_if(v.begin(), v.end(), Is_wanna());
//	if (it == v.end())
//		cout << "�Ҳ������5������";
//	else
//		cout << "�ҵ��ˣ�����v�д���5�������ǣ�" << *it;*/
//
//
//
//	return 0;
//}

//class MyAdd
//{
//public:
//	int operator()(int a, int b)
//	{
//		return a + b;
//	}
//};
//
//int main()
//{
//	int a = 20;
//	int b = 90;
//	MyAdd myadd;
//	cout << myadd(a, b);
//	return 0;
//}

//#define PLAN 1
//#define ARTIST 2
//#define DEVELOP 3
//
//class Person
//{
//public:
//	string m_name;
//	int m_wages;
//
//	Person(string name, int wages)
//	{
//		m_name = name;
//		m_wages = wages;
//	}
//};
//
//void Initwork(vector<Person>& vwork)
//{
//	srand((unsigned int)time(NULL));
//	string nameseed = "123456789x";
//	for (int i = 0; i<10; i++)
//	{
//		string name = "Ա�� ";
//		name += nameseed[i];
//
//		int wages = rand() % 10001 + 10000;
//		vwork.push_back(Person(name, wages));
//	}
//}
//
//void Initwork_m(vector<Person>& vwork, multimap<int, Person>& mwork)
//{
//	srand((unsigned int)time(NULL));
//	for (auto it = vwork.begin(); it != vwork.end(); it++)
//	{
//		int position = rand() % 3 + 1;
//		mwork.insert(make_pair(position, *it));
//	}
//}
//
//void ChooseDisplay(multimap<int, Person>& m)
//{
//	
//	
//}
//
//int main()
//{
//	vector<Person> vwork;
//	Initwork(vwork);
//	multimap<int, Person> mwork;
//	Initwork_m(vwork,mwork);
//
//	ChooseDisplay(mwork);
//
//	/*for (auto it = vwork.begin(); it != vwork.end(); it++)
//	{
//		cout << "������" << it->m_name << "\t���ʣ�" << it->m_wages << endl;
//	}
//	for (auto it = mwork.begin(); it != mwork.end(); it++)
//	{
//		cout << "ְλ��" << it->first << "\t������" << it->second.m_name << "\t����" << it->second.m_wages << endl;
//	}
//	return 0;*/
//}