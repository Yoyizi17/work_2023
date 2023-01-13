#include<iostream>
#include<string>
#include<fstream>
#include<string.h>
using namespace std;

//class Base
//{
//public:
//	virtual void func() = 0;
//};
//
//class Son :public Base
//{
//public:
//	void func()
//	{
//		cout << "Son::func函数调用" << endl;
//	}
//};
//
//void Func(Base& base)
//{
//	base.func();
//}
//
//int main()
//{
//	Base* a = new Son;
//	a->func();
//	Func(*a);
//	return 0;
//}

//class AbstractDrinking
//{
//public:
//	virtual void Boil() = 0;
//
//	virtual void Brew() = 0;
//
//	virtual void PourInCup() = 0;
//
//	virtual void PutSomething() = 0;
//
//	virtual void Makeing() = 0;
//
//	virtual void M_L() = 0;
//};
//
//class Coffe :public AbstractDrinking
//{
//public:
//	virtual void Boil()
//	{
//		cout << "开始煮水" << endl;
//	}
//
//	virtual void Brew()
//	{
//		cout << "冲入咖啡" << endl;
//	}
//
//	virtual void PourInCup()
//	{
//		cout << "把咖啡倒进杯子里" << endl;
//	}
//
//	virtual void PutSomething()
//	{
//		cout << "加入白糖和牛奶" << endl;
//	}
//	virtual void M_L()
//	{
//		cout << "好甜！泠绪，你加了太多糖了！" << endl;
//	}
//	virtual void Makeing()
//	{
//		Boil();
//		Brew();
//		PourInCup();
//		PutSomething();
//		M_L();
//	}
//};
//
//class Tea :public AbstractDrinking
//{
//public:
//	virtual void Boil()
//	{
//		cout << "开始煮白水" << endl;
//	}
//
//	virtual void Brew()
//	{
//		cout << "冲入茶叶" << endl;
//	}
//
//	virtual void PourInCup()
//	{
//		cout << "把茶水倒进杯子里" << endl;
//	}
//
//	virtual void PutSomething()
//	{
//		cout << "加入柠檬汁儿" << endl;
//	}
//
//	virtual void M_L()
//	{
//		cout << "唔...这种东西真的有人喜欢喝吗？麻衣。" << endl;
//	}
//
//	virtual void Makeing()
//	{
//		Boil();
//		Brew();
//		PourInCup();
//		PutSomething();
//		M_L();
//	}
//};
//
//
//void MakeDringk(AbstractDrinking* abc)
//{
//	abc->Makeing();
//}
//
//int main()
//{
//	Coffe c;
//	MakeDringk(&c);
//	cout << "----------------------------------------------------------------" << endl;
//	Tea t;
//	MakeDringk(&t);
//	return 0;
//}

//class Animal
//{
//public:
//	Animal()
//	{
//		cout << "Animal的构造函数调用" << endl;
//	}
//	virtual void Speak() = 0;
//	virtual ~Animal()
//	{
//		cout << "Animal的析构函数调用" << endl;
//	}
//};
//
//class Cat :public Animal
//{
//public:
//	Cat(string name)
//	{
//		cout << "Cat的构造函数调用" << endl;
//		m_name = new string(name);
//	}
//	void Speak()
//	{
//		cout << "小猫" << *m_name << "在说话" << endl;
//	}
//	~Cat()
//	{
//		cout << "Cat的析构函数调用" << endl;
//	}
//public:
//	string* m_name;
//};
//
//int main()
//{
//	Animal* c = new Cat("Tom");
//	c->Speak();
//	delete c;
//	c = NULL;
//	return 0;
//}


//先建立CPU，显卡，内存条的三个抽象类。用来多态实现不同品牌的使用。
//再创建一个电脑类，封装一下cpu，显卡，内存条的功能。


//创建CPU的抽象类，实现计算功能
//class CPU
//{
//public:
//	virtual void Calulation() = 0;//实现计算功能
//};
//
//class Videocard
//{
//public:
//	virtual void Display() = 0;//实现显示功能
//};
//
//class Bar
//{
//public:
//	virtual void Memory() = 0;//实现储存功能
//};
//
//class Computer
//{
//private:
//	CPU* m_cpu;
//	Videocard* m_vcard;
//	Bar* m_bar;
//public:
//	Computer(CPU* cpu, Videocard* vcard, Bar* bar)
//	{
//		m_cpu = cpu;
//		m_vcard = vcard;
//		m_bar = bar;
//	}
//	void Work()
//	{
//		CPU* c = m_cpu;
//		Videocard* v = m_vcard;
//		Bar* b = m_bar;
//		c->Calulation();
//		v->Display();
//		b->Memory();
//	}
//
//	~Computer()
//	{
//		cout << "compuer析构函数调用" << endl;
//		delete m_cpu;
//		m_cpu = NULL;
//		delete m_vcard;
//		m_vcard = NULL;
//		delete m_bar;
//		m_bar = NULL;
//	}
//};
//
//class InterCPU :public CPU
//{
//public:
//	void Calulation()
//	{
//		cout << "InterCPU开始计算了！性能超级好！" << endl;
//	}
//};
//
//class InterVideocard :public Videocard
//{
//public:
//	void Display()
//	{
//		cout << "InterVideoCard开始工作了！画面超级流畅！" << endl;
//	}
//};
//
//class InterBar :public Bar
//{
//public:
//	void Memory()
//	{
//		cout << "InterBar开始储存了！内存超级大！" << endl;
//	}
//};
///////////////////////////////
//class LenovoCPU :public CPU
//{
//public:
//	void Calulation()
//	{
//		cout << "LenovoCPU开始计算了!在联想cpu上运行了！" << endl;
//	}
//};
//
//class LenovoVideocard :public Videocard
//{
//public:
//	void Display()
//	{
//		cout << "LnenovoVideoCard开始工作了！在联想显卡上显示了！" << endl;
//	}
//};
//
//class LenovoBar :public Bar
//{
//public:
//	void Memory()
//	{
//		cout << "LenovoBar开始储存了！储存在联想内存条上了！" << endl;
//	}
//};
//
//int main()
//{
//	Computer computer(new LenovoCPU, new LenovoVideocard, new LenovoBar);
//	computer.Work();
//	return 0;
//}

//int main()
//{
//	ofstream ofs;
//	ofs.open("text.txt", ios::out);
//	ofs << "我的王子人" << endl;
//	ofs << "百合万岁" << endl;
//	ofs.close();
//	ofs.open("text.txt", ios::ate|ios::out);
//	ofs << "我人" << endl;
//	ofs << "百合" << endl;
//	ofs.close();
//	return 0;
//}


int main()
{
	ifstream ifs;
	ifs.open("text.txt", ios::in);
	if (!ifs.is_open())
	{
		cout << "打开文件失败" << endl;
		return 0;
	}
	//读取文件数据的第一种方式：“>>”
	//char bur[100];
	//while (ifs >> bur)
	//{
	//	cout << bur << endl;
	//}



	//读取文件的第二种方式：“对象.getline(空间指针，空间大小)”
	/*char bur[100];
	while (ifs.getline(bur, sizeof(bur)))
	{
		cout << bur << endl;
	}*/

	//读取文件数据的第三种方式：“全局函数getline(文件输入流对象名,字符串名)”
	/*string bur;
	while (getline(ifs, bur))
	{
		cout << bur << endl;
	}*/
    /**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
    typedef struct ListNode LNode;
    struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB) {
        LNode* a = headA;
        LNode* b = headB;
        for (int i = 1; i < 20; i++)
        {

            a = headA;
            b = headB;
            for (int j = 0; j < i && a && b && a != b; j++)
            {

                a = a->next;
                b = headB;
                for (int h = 0; h < i && b && a != b; h++)
                {
                    b = b->next;
                }
            }
            if (a == b)
                return a;


            a = headA;
            b = headB;
            for (int j = 0; j < i && a && b && a != b; j++)
            {

                b = b->next;
                a = headA;
                for (int h = 0; h < i && a && a != b; h++)
                {
                    a = a->next;
                }
            }
            if (a == b)
                return a;
        }
        return NULL;
    }

	ifs.close();
	return 0;
}