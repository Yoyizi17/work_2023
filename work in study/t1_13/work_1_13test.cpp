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
//		cout << "Son::func��������" << endl;
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
//		cout << "��ʼ��ˮ" << endl;
//	}
//
//	virtual void Brew()
//	{
//		cout << "���뿧��" << endl;
//	}
//
//	virtual void PourInCup()
//	{
//		cout << "�ѿ��ȵ���������" << endl;
//	}
//
//	virtual void PutSomething()
//	{
//		cout << "������Ǻ�ţ��" << endl;
//	}
//	virtual void M_L()
//	{
//		cout << "���������������̫�����ˣ�" << endl;
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
//		cout << "��ʼ���ˮ" << endl;
//	}
//
//	virtual void Brew()
//	{
//		cout << "�����Ҷ" << endl;
//	}
//
//	virtual void PourInCup()
//	{
//		cout << "�Ѳ�ˮ����������" << endl;
//	}
//
//	virtual void PutSomething()
//	{
//		cout << "��������֭��" << endl;
//	}
//
//	virtual void M_L()
//	{
//		cout << "��...���ֶ����������ϲ���������¡�" << endl;
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
//		cout << "Animal�Ĺ��캯������" << endl;
//	}
//	virtual void Speak() = 0;
//	virtual ~Animal()
//	{
//		cout << "Animal��������������" << endl;
//	}
//};
//
//class Cat :public Animal
//{
//public:
//	Cat(string name)
//	{
//		cout << "Cat�Ĺ��캯������" << endl;
//		m_name = new string(name);
//	}
//	void Speak()
//	{
//		cout << "Сè" << *m_name << "��˵��" << endl;
//	}
//	~Cat()
//	{
//		cout << "Cat��������������" << endl;
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


//�Ƚ���CPU���Կ����ڴ��������������ࡣ������̬ʵ�ֲ�ͬƷ�Ƶ�ʹ�á�
//�ٴ���һ�������࣬��װһ��cpu���Կ����ڴ����Ĺ��ܡ�


//����CPU�ĳ����࣬ʵ�ּ��㹦��
//class CPU
//{
//public:
//	virtual void Calulation() = 0;//ʵ�ּ��㹦��
//};
//
//class Videocard
//{
//public:
//	virtual void Display() = 0;//ʵ����ʾ����
//};
//
//class Bar
//{
//public:
//	virtual void Memory() = 0;//ʵ�ִ��湦��
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
//		cout << "compuer������������" << endl;
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
//		cout << "InterCPU��ʼ�����ˣ����ܳ����ã�" << endl;
//	}
//};
//
//class InterVideocard :public Videocard
//{
//public:
//	void Display()
//	{
//		cout << "InterVideoCard��ʼ�����ˣ����泬��������" << endl;
//	}
//};
//
//class InterBar :public Bar
//{
//public:
//	void Memory()
//	{
//		cout << "InterBar��ʼ�����ˣ��ڴ泬����" << endl;
//	}
//};
///////////////////////////////
//class LenovoCPU :public CPU
//{
//public:
//	void Calulation()
//	{
//		cout << "LenovoCPU��ʼ������!������cpu�������ˣ�" << endl;
//	}
//};
//
//class LenovoVideocard :public Videocard
//{
//public:
//	void Display()
//	{
//		cout << "LnenovoVideoCard��ʼ�����ˣ��������Կ�����ʾ�ˣ�" << endl;
//	}
//};
//
//class LenovoBar :public Bar
//{
//public:
//	void Memory()
//	{
//		cout << "LenovoBar��ʼ�����ˣ������������ڴ������ˣ�" << endl;
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
//	ofs << "�ҵ�������" << endl;
//	ofs << "�ٺ�����" << endl;
//	ofs.close();
//	ofs.open("text.txt", ios::ate|ios::out);
//	ofs << "����" << endl;
//	ofs << "�ٺ�" << endl;
//	ofs.close();
//	return 0;
//}


int main()
{
	ifstream ifs;
	ifs.open("text.txt", ios::in);
	if (!ifs.is_open())
	{
		cout << "���ļ�ʧ��" << endl;
		return 0;
	}
	//��ȡ�ļ����ݵĵ�һ�ַ�ʽ����>>��
	//char bur[100];
	//while (ifs >> bur)
	//{
	//	cout << bur << endl;
	//}



	//��ȡ�ļ��ĵڶ��ַ�ʽ��������.getline(�ռ�ָ�룬�ռ��С)��
	/*char bur[100];
	while (ifs.getline(bur, sizeof(bur)))
	{
		cout << bur << endl;
	}*/

	//��ȡ�ļ����ݵĵ����ַ�ʽ����ȫ�ֺ���getline(�ļ�������������,�ַ�����)��
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