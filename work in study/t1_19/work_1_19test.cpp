#include<iostream>
using namespace std;

////class Person
////{
////public:
////	string m_name;
////	int m_age;
////
////	Person(const char name[10], int age)
////	{
////		m_name = name;
////		m_age = age;
////	}
//
//	/*bool operator==(Person& p)
//	{
//		if (this->m_name == p.m_name && this->m_age == p.m_age)
//			return true;
//		else
//			return false;
//	}*/
//
//
////
////template<typename T>
////bool Is_Same(T& a, T& b )
////{
////	if (a == b)
////		return 1;
////	else
////		return 0;
////}
////
////template<> bool Is_Same(Person& a, Person& b)
////{
////	if (a.m_age = b.m_age && a.m_name == b.m_name)
////		return true;
////	else
////		return false;
////}
////
////int main()
////{
////	Person p1("张三", 10);a
////	Person p2("张三", 10);
////
////	cout << Is_Same(p1, p2) << endl;
////	return 0;
////}
//
//class Person1
//{
//public:
//	void Show1()
//	{
//		cout << "Person Show1" << endl;
//	}
//};
//
//class Person2
//{
//public:
//	void Show2()
//	{
//		cout << "Person Shoe2"<<endl;
//	}
//};
//
//template<typename T>
//class Person3
//{
//public:
//	T c;
//	void func1()
//	{
//		c.Show1();
//	}
//	void func2()
//	{
//		c.Show2();
//	}
//};
//
//int main()
//{
//	Person3<Person2>p;
//	//p.func1();
//	p.func2();
//	return 0;
//}

//template<typename T>
//class Base
//{
//public:
//	T base;
//};
//
//template<typename T2,typename T1>
//class Son :public Base<T2>
//{
//public:
//	Son()
//	{
//		cout <<""<<typeid(T2).name()<< endl;
//	}
//	T1 son;
//};
//
//int main()
//{
//	Son<int,char> s;
//	return 0;
//}

template<class T1,class T2>
class Person
{
public:
	T1 m_name;
	T2 m_age;
	Person(T1 a, T2 b);

	void ShowPer();
};

template<class T1,class T2>
Person<T1, T2>::Person(T1 a, T2 b)
{
	this->m_name = a;
	this->m_age = b;
}

template<class T1,class T2>
void Person<T1,T2>::ShowPer()
{
	cout << "姓名是：" << this->m_name << "年龄：" << this->m_age << endl;
}

int main()
{
	Person<string, int>p("张三", 10);
	p.ShowPer();
	return 0;
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef struct ListNode LNode;
struct ListNode* reverseList(struct ListNode* head) {
	LNode* prev = NULL;
	LNode* tail = head;
	while (tail)
	{
		LNode* temp = tail;
		tail = tail->next;
		temp->next = prev;
		prev = temp;
	}
	return prev;
}