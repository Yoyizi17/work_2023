#include<iostream>
#include<string.h>
using namespace std;

//class Person
//{
//public:
//	/*Person(int a, int b, int c)
//	{
//		m_Y = a;
//		m_X = b;
//		m_H = c;
//	}*/
//
//	Person(int a,int b) :m_Y(a), m_X(b), m_H(90)
//	{
//
//	}
//
//	int m_Y;
//	int m_X;
//	int m_H;
//
//};
//
//int main()
//{
//	Person p(30,40);
//
//	
//	cout << "" << p.m_Y << endl;
//	cout << "" << p.m_X << endl;
//	cout << "" << p.m_H << endl;
//
//	return 0;
//}

//class Phone
//{
//public:
//
//	Phone(string name):p_name(name)
//	{
//
//	}
//
//	string p_name;
//
//};
//
//class Person
//{
//public:
//	Person(const string name, string p_name) :m_name(name), phone(p_name)
//	{
//
//	}
//	string m_name; 
//	Phone phone;
//};



//int main()
//{
//	Person p("张三", "苹果");
//	cout << "姓名是：" << p.m_name << "手机品牌是：" << p.phone.p_name << endl;
//	return 0;
//}

//class Person
//{
//public:
//
//	static int m_a;
//
//};
//
//int Person::m_a = 100;
//
//int main()
//{
//	Person p;
//	cout << "" << p.m_a << endl;
//	Person p2;
//	p2.m_a = 200;
//	cout << "" << p.m_a << endl;
//
//	cout << "" << Person::m_a << endl;
//	return 0;
//}
//
//class Person
//{
//public:
//
//	static void func()
//	{
//		cout << "" << m_A << endl;
//		
//		cout << "调用静态成员变量func" << endl;
//	}
//	static int m_A;
//	int m_B;
//};
//
//int Person::m_A = 100;
//
//int main()
//{
//	Person p;
//	p.func();
//
//	Person::func();
//	return 0;
//}


class Person
{
public:
	int m_age;

	Person(int a)
	{
		m_age = a;
	}

	Person& ageadd(Person &p)
	{
		m_age += p.m_age;
		return *this;
	}

};

int main()
{
	Person p1(10);
	Person p2(10);

	p2.ageadd(p1).ageadd(p1).ageadd(p1).ageadd(p1);

	cout << "p2的年纪是：" << p2.m_age << endl;
	return 0;
}
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getRow(int rowIndex, int* returnSize) {
    if (rowIndex == 0)
    {
        int* a = (int*)malloc(sizeof(int));
        a[0] = 1;
        *returnSize = 1;
        return a;
    }
    int* a = (int*)calloc((rowIndex + 1), sizeof(int));


    a[0] = 1;

    for (int i = 0; i < rowIndex; i++)
    {
        int prev = 0;//这两个值用来暂时保存 （ 更改前的位置上的值  以及  前一个值 ） 的位置。
        int tail = 1;
        int left = a[prev];//这两个值用来暂时保存 （ 更改前的位置上的值  以及  前一个值 ）。
        int right = a[tail];
        for (; prev < rowIndex;)
        {
            a[tail] = left + right;

            left = right;
            prev++;
            if (tail < rowIndex)
            {
                tail++;
                right = a[tail];
            }

        }
    }
    *returnSize = rowIndex + 1;
    return a;
}