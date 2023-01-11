#include<iostream>
#include<string.h>
using namespace std;

//class Person
//{
//public:
//	Person()
//	{
//		this->m_a = 10;
//		this->m_b = 100;
//	}
//	int m_a;
//	int m_b;
//};
//
//ostream& operator<<(ostream& cout, Person& p)
//{
//	cout << p.m_a << endl;
//	cout << p.m_b << endl;
//
//    return cout;
//}
//
//int main()
//{
//	Person p;
//	cout << p << "hello world" << endl;
//	return 0;
//}
//
//class Number
//{
//	friend ostream& operator<<(ostream& cout, Number n);
//public:
//	Number()
//	{
//		m_Num = 100;
//	}
//
//	Number& operator++()
//	{
//		this->m_Num++;
//		return *this;
//	}
//	Number operator++(int)
//	{
//		Number tmp = *this;
//		m_Num++;
//
//		return tmp;
//	}
//
//private:
//	int m_Num;
//};
//
//ostream& operator<<(ostream& cout, Number n)//Number n = Number 
//{
//	cout << n.m_Num << endl;
//	return cout;
//}
//
//int main()
//{
//	Number n;
//	cout << ++n;
//	return 0;

//class Person
//{
//public:
//	Person(int age)
//	{
//		this->m_age = new int(age);
//	}
//
//	Person& operator=(Person& p)
//	{
//		if (m_age != NULL)
//		{
//			delete m_age;
//			m_age == NULL;
//		}
//		m_age = new int(*p.m_age);
//		return *this;
//	}
//
//	~Person()
//	{
//		if (m_age != NULL)
//		{
//			cout << "调用结构函数" << endl;
//			delete m_age;
//			m_age = NULL;
//		}
//	}
//
//	int* m_age;
//};
//
//int main()
//{
//	Person p(18);
//	Person p2(20);
//	Person p3(100);
//	p = p2 = p3;
//	cout << *p.m_age << endl;
//
//	return 0;
//}

//class Person
//{
//public:
//	Person(string name,int age) :m_name(name), m_age(age)
//	{
//
//	}
//	string m_name;
//	int m_age;
//};
//
//int main()
//{
//	Person p1("张三", 6);
//	cout << p1.m_name << p1.m_age << endl;
//	return 0;
//}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//
//class Java
//{
//public:
//	void Head()
//	{
//		cout << "首页、公开课、登录、注册》》》（公共头部）" << endl;
//	}
//	void Foot()
//	{
//		cout << "帮助中心、交流中心、站内地图》》》（公共底部）" << endl;
//	}
//	void Left()
//	{
//		cout << "Java、Python、C++》》》（公共列表）" << endl;
//	}
//	void Self()
//	{
//		cout << "Java学科视频" << endl;
//	}
//};
//
//class Python
//{
//public:
//	void Head()
//	{
//		cout << "首页、公开课、登录、注册》》》（公共头部）" << endl;
//	}
//	void Foot()
//	{
//		cout << "帮助中心、交流中心、站内地图》》》（公共底部）" << endl;
//	}
//	void Left()
//	{
//		cout << "Java、Python、C++》》》（公共列表）" << endl;
//	}
//	void Self()
//	{
//		cout << "Python学科视频" << endl;
//	}
//};
//
//class CPP
//{
//public:
//	void Head()
//	{
//		cout << "首页、公开课、登录、注册》》》（公共头部）" << endl;
//	}
//	void Foot()
//	{
//		cout << "帮助中心、交流中心、站内地图》》》（公共底部）" << endl;
//	}
//	void Left()
//	{
//		cout << "Java、Python、C++》》》（公共列表）" << endl;
//	}
//	void Self()
//	{
//		cout << "CPP学科视频" << endl;
//	}
//};
//
//
//int main()
//{
//	Java ja;
//	ja.Head();
//	ja.Left();
//	ja.Self();
//	ja.Foot();
//	cout << "-----------------------" << endl;
//	Python py;
//	py.Head();
//	py.Left();
//	py.Self();
//	py.Foot();
//	cout << "-----------------------" << endl;
//	CPP cpp;
//	cpp.Head();
//	cpp.Left();
//	cpp.Self();
//	cpp.Foot();
//	cout << "-----------------------" << endl;
//	return 0;
//}

class BasePage
{
public:
	void Head()
	{
		cout << "首页、公开课、登录、注册》》》（公共头部）" << endl;
	}
	void Foot()
	{
		cout << "帮助中心、交流中心、站内地图》》》（公共底部）" << endl;
	}
	void Left()
	{
		cout << "Java、Python、C++》》》（公共列表）" << endl;
	}
};

class Java:public BasePage
{
public:
	void Self()
	{
		cout << "Java学科视频" << endl;
	}
};

class Python :public BasePage
{
public:
	void Self()
	{
		cout << "Python学科视频" << endl;
	}
};

class CPP :public BasePage
{
public:
	void Self()
	{
		cout << "C++学科视频" << endl;
	}
};

int main()
{
	Java ja;
	ja.Head();
	ja.Left();
	ja.Self();
	ja.Foot();
	cout << "-----------------------" << endl;
	Python py;
	py.Head();
	py.Left();
	py.Self();
	py.Foot();
	cout << "-----------------------" << endl;
	CPP cpp;
	cpp.Head();
	cpp.Left();
	cpp.Self();
	cpp.Foot();
	cout << "-----------------------" << endl;
	return 0;
}
int singleNumber(int* nums, int numsSize) {
	if (numsSize == 1)
	{
		int ret = nums[0];
		return ret;
	}
	int ret = nums[0];
	for (int i = 1; i < numsSize; i++)
		ret = ret ^ nums[i];
	return ret;
}