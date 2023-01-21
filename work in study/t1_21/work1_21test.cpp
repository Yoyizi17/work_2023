#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

//void My_Print(int val)
//{
//	cout << val << endl;
//}
//
//int main()
//{
//	vector<int> v = { 10,20,30,40,50 };
//	//v.push_back(10);
//	//v.push_back(20);
//	//v.push_back(30);
//	//v.push_back(40);
//	//v.push_back(50);
//	//vector<int>::iterator itBegin = v.begin();
//	//vector<int>::iterator itEnd = v.end();
//	//while (itBegin != itEnd)
//	//{
//	//	cout << *itBegin << endl;
//	//	itBegin++;
//	//}
//
//	for_each(v.begin(), v.end(), My_Print);
//	return 0;
//}


//
//class Person
//{
//public:
//	string m_name;
//	int m_age;
//
//	Person(string name, int age)
//	{
//		m_name = name;
//		m_age = age;
//	}
//};
//
//void Print_Person(Person*& p)
//{
//	cout << "姓名是：" << p->m_name << "     年龄：" << p->m_age << endl;
//}
//
//int main()
//{
//	Person p1("张三", 20);
//	Person p2("李四", 30);
//	Person p3("王五", 40);
//	Person p4("赵六", 50);
//
//	vector<Person*> v = { &p1,&p2,&p3,&p4 };
//
//	for_each(v.begin(), v.end(), Print_Person);
//	for (vector<Person*>::iterator it = v.begin(); it != v.end(); it++)
//	{
//		cout << "姓名：" << (*it)->m_name << "    年龄：" << (*it)->m_age << endl;
////	}
////	return 0;
////}
//
//class Person
//{
//public:
//	string m_name;
//	int m_age;
//
//	Person(string name, int age)
//	{
//		m_name = name;
//		m_age = age;
//	}
//};
//
//void M_Print(int val)
//{
//	cout << val << "   ";
//}
//
//
//void M_Print_varr(vector<int> v)
//{
//	for_each(v.begin(), v.end(), M_Print); cout << "\n";
//}
//
//
//int main()
//{
//	vector<int> v1 = { 1, 2, 3, 4, 5, };
//	vector<int> v2 = { 1, 2, 3, 0, 5, };
//	vector<int> v3 = { 1, 2, 3, 9, 5, };
//	vector<int> v4 = { 1, 2, 3, 7, 5, };
//	vector<int> v5 = { 1, 2, 3, 5, 5, };
//
//	vector < vector<int >> varr = {v1, v2, v3, v4, v5};
//
//	for_each(varr.begin(), varr.end(), M_Print_varr);
//
//	return 0;
//}

int main()
{
	string str = "abcdef";
	str.find("de");
	return 0;
}