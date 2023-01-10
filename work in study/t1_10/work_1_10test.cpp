#include<iostream>
#include<string.h>
using namespace std;

//class Person
//{
//public:
//
//	void ShowPersonName()
//	{
//		cout << "Personname" << endl;
//	}
//
//	void ShowPersonAge()
//	{
//		cout << "age：" << m_age << endl;
//	}
//
//	int m_age;
//};
//
//int main()
//{
//	Person* p = NULL;
//	p->ShowPersonName();
//	p->ShowPersonAge();
//	return 0;
//}
//
//class Person
//{
//public:
//	void ShowPerson() const
//	{
//		//this->m_age = 100;
//		this->m_b = 100;
//	}
//
//	int m_age;
//	mutable int m_b;
//
//};
//
//
//int main()
//{
//
//	return 0;
//}
//
//class Building
//{
//	friend void GoodGay(Building& building);
//
//public:
//	Building()
//	{
//		this->m_livingroom = "颐和园";
//		this->m_bedroom = "后花园";
//	}
//
//
//
//public:
//	string m_livingroom;
//private:
//	string m_bedroom;
//};
//
//void GoodGay(Building& building)
//{
//	cout << "Goodgay函数正在访问：" << building.m_livingroom << endl;
//
//	cout << "Goodgay函数正在访问：" << building.m_bedroom << endl;
//}
//
//int main()
//{
//	Building building;
//	GoodGay(building);
//	return 0;
//}
//
//class Building
//{
//	friend class GoodLesbian;
//public:
//	Building();
//	
//
//public:
//	string m_livingroom;
//private:
//	string m_bedroom;
//};
///// 
//class GoodLesbian
//{
//	
//public:
//	GoodLesbian();
//	
//
//	void visit();
//public:
//	Building* building;
//};
//
///////////////////////////////////////////////////////////////////////////////////////
//
//Building::Building()
//{
//	this->m_livingroom = "颐和园";
//	this->m_bedroom = "秘密花园";
//}
//
//GoodLesbian::GoodLesbian()
//{
//	this->building = new Building;
//}
//
//void GoodLesbian::visit()
//{
//	cout << "好姬友正在访问：" << building->m_livingroom << endl;
//
//	cout << "好姬友正在访问：" << building->m_bedroom << endl;
//}
//
//int main()
//{
//	GoodLesbian lz;
//	lz.visit();
//	return 0;
//}
// 
 


//class GoodLesbian;
//
//class Building///////////////////////
//{
//	friend void GoodLesbian::visit();
//public:
//	Building();
//public:
//	string m_livingroom;
//private:
//	string m_bedroom;
//};
//
//class GoodLesbian/////////////////////////////////
//{
//public:
//	GoodLesbian();
//	void visit();
//public:
//	Building* building = NULL;
//};
//
//
//
//Building::Building()
//{
//	this->m_livingroom = "颐和园";
//	this->m_bedroom = "秘密花园";
//}
//
//GoodLesbian::GoodLesbian()
//{
//	this->building = new Building;
//}
//
//void GoodLesbian::visit()
//{
//	cout << "好姬友函数正在访问：" << building->m_livingroom << endl;
//
//	cout << "好姬友正在访问：" << building->m_bedroom << endl;
//}
//
//int main()
//{
//	GoodLesbian lz;
//	lz.visit();
//	return 0;
//}


//
//class Building;
//
//class GoodLesbian/////////////////////////////////
//{
//public:
//	GoodLesbian();
//	void visit();
//public:
//	Building* building = NULL;
//};
//
//class Building///////////////////////
//{
//	friend void GoodLesbian::visit();
//public:
//	Building();
//public:
//	string m_livingroom;
//private:
//	string m_bedroom;
//};
//
//Building::Building()
//{
//	this->m_livingroom = "颐和园";
//	this->m_bedroom = "秘密花园";
//}
//
//GoodLesbian::GoodLesbian()
//{
//	this->building = new Building;
//}
//
//void GoodLesbian::visit()
//{
//	cout << "好姬友函数正在访问：" << building->m_livingroom << endl;
//
//	cout << "好姬友正在访问：" << building->m_bedroom << endl;
//}
//
//int main()
//{
//	GoodLesbian lz;
//	lz.visit();
//	return 0;
//}

class Person
{
public:
	Person()
	{

	}
	Person(int a, int b) : m_a(a), m_b(b)
	{

	}



public:
	int m_a;
	int m_b;
};

Person operator+(Person& p1, Person& p2)
{
	Person tmp;
	tmp.m_a = p1.m_a + p2.m_a;
	tmp.m_b = p1.m_a + p2.m_b;
	return tmp;
}

int main()
{
	Person p1(10, 10);
	Person p2(20, 20);
	Person p3 = p1 + p2;
	cout << p3.m_a << endl;
	cout << p3.m_b << endl;
	return 0;
}
int maxProfit(int* prices, int pricesSize) {
	int max = 0;
	int min = prices[0];
	for (int i = 0; i < pricesSize; i++)
	{
		if (prices[i] < min)
			min = prices[i];
		else if (prices[i] - min > max)
			max = prices[i] - min;
	}

	return max;
}