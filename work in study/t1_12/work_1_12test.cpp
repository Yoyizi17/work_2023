#include<iostream>
using namespace std;

//class Base
//{
//public:
//	Base()
//	{
//		m_A = 100;
//	}
//
//	void Func()
//	{
//		cout << "Base类别下的func函数调用" << endl;
//	}
//
//	int m_A;
//};
//
//class Son :public Base
//{
//public:
//	Son()
//	{
//		m_A = 200;
//	}
//
//	void Func()
//	{
//		cout << "Son类别下的func函数调用" << endl;
//	}
//
//	int m_A;
//};
//
//int main()
//{
//	Son s;
//	s.Func();
////	s.Base::Func();	
////	return 0;
////}
//
//class Base
//{
//public:
//	static int m_A;
//};
//int Base::m_A = 100;
//
//class Son:public Base
//{
//public:
//	static int m_A;
//};
//int Son::m_A = 200;
//
//
//int main()
//{
//	Son s;
//	cout << "通过对象访问静态变量" << endl;
//	cout << "Son 下的静态变量" << s.m_A << endl;
//	cout << "Base 下的静态变量" << s.Base::m_A << endl;
//
//	cout << "通过类名访问静态变量" << endl;
//	cout << "Son 下的静态变量" << Son::m_A << endl;
//	cout << "Base 下的静态变量" << Son::Base::m_A << endl;
//	return 0;
//}

//class Animal
//{
//public:
//     int m_Age;
//};
//
//class Sheep:virtual public Animal{};
//class Tuo :virtual public Animal{};
//class SheepTuo:public Sheep,public Tuo{};
//
//int main()
//{
//	SheepTuo st;
//	st.Sheep::m_Age = 19;
//	st.Tuo::m_Age = 89;
//	cout << "" << st.Sheep::m_Age << endl;
//	cout << "" << st.Tuo::m_Age << endl;
//	cout << "" << st.m_Age << endl;
//	return 0;

//class Animal
//{
//public:
//	virtual void Speak()
//	{
//		cout << "动物在说话" << endl;
//	}
//};
//
//class Cat :public Animal
//{
//public:
//	void Speak()
//	{
//		cout << "小猫在说话" << endl;
//	}
//};
//
//class Dog :public Animal
//{
//public:
//	void Speak()
//	{
//		cout << "小狗在说话" << endl;
//	}
//};
//
//void DoSpeak(Animal& animal)
//{
//	animal.Speak();
//}
//
//int main()
//{
//	Cat c;
//	DoSpeak(c);
//	Dog d;
//	DoSpeak(d);
//	return 0;
//}

class AbstractCalculation
{
public:
	int m_Num1;
	int m_Num2;
	
	virtual int Getresualt()
	{
		return 0;
	}
};

class AddcalCulation:public AbstractCalculation
{
public:
	int Getresualt()
	{
		return m_Num1 + m_Num2;
	}
};

class SubcalCulation :public AbstractCalculation
{
public:
	int Getresualt()
	{
		return m_Num1 - m_Num2;
	}
};

class MulcalCulation :public AbstractCalculation
{
public:
	int Getresualt()
	{
		return m_Num1 * m_Num2;
	}
};

//class CulcalCulation :public AbstractCalculation
//{
//public:
//	int Getresualt()
//	{
//		return m_Num1 * m_Num2;
//	}
//};

int main()
{
	AbstractCalculation* a = new AddcalCulation;
	a->m_Num1 = 10;
	a->m_Num2 = 100;
	cout << a->m_Num1 << "+" << a->m_Num2 << "=" << a->Getresualt() << endl;
	delete a;
	a = new SubcalCulation;
	a->m_Num1 = 10;
	a->m_Num2 = 100;
	cout << a->m_Num1 << "- " << a->m_Num2 << "=" << a->Getresualt() << endl;
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
bool hasCycle(struct ListNode* head) {
	if (head == NULL || head->next == NULL)
		return false;
	LNode* slow = head;
	LNode* fast = head->next;
	while (slow != fast && fast->next != NULL && fast->next->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	if (fast->next == NULL || fast->next->next == NULL)
		return false;
	if (slow == fast)
		return true;

	return false;
}