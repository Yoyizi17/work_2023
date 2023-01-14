#include<iostream>
#include<fstream>
#include<string>
using namespace std;

//int main()
//{
//	//ofstream ofs;
//	//ofs.open("text.txt", ios::out);
//	//ofs << "花吻在上" << endl;
//	//ofs.close();
//
//	//ifstream ifs;
//	//ifs.open("text.txt", ios::in);
//	//if (!ifs.is_open())
//	//{
//	//	cout << "打开文件失败" << endl;
//	//	return 0;
//	//}
//	//string bur;
//	//while (getline(ifs, bur))
//	//{
//	//	cout << bur << endl;
//	//}
//
//
//
//	return 0;
//}

/*class Person
{
public:
	Person(char* name, int age)
	{
		m_name = *name;
	}
	char m_name[10];
	int m_age;
}*/;
//
//int main()
//{
//	//Person p = { "张三",29 };
//	//创建流对象
//	//ofstream ofs("Person.txt", ios::out | ios::binary);
//	//以二进制写的方式打开文件
//	//写入数据
//	//ofs.write((const char*)&p, sizeof(Person));
//	//关闭文件
//	//ofs.close();
//
//	//ifstream ifs;
//	//ifs.open("Person.txt", ios::in | ios::binary);
//	//if (!ifs.is_open())
//	//{
//	//	cout << "打开失败" << endl;
//	//	return 0;
//	//}
//	//Person p1;
//	//ifs.read((char*)&p1, sizeof(Person));
//	//cout << p1.m_name << p1.m_age << endl;
//	//ifs.close();
//	//char name[19] = "zhangsan";
//	//Person p(name, 19);
//	//cout << p.m_name << endl;
//
//	char arr[88];
//	cin >> arr;
//	cout << arr << endl;
//
//	return 0;
//}
struct Memory
{
    int data;
    struct Memory* next;
    int count;
};
typedef struct Memory Mcount;

int majorityElement(int* nums, int numsSize) {
    Mcount* plist = (Mcount*)malloc(sizeof(Mcount));
    plist->data = 0;
    plist->count = 0;
    plist->next = NULL;
    Mcount* tail;
    for (int i = 0; i < numsSize; i++)
    {
        tail = plist;

        while (tail->next != NULL && tail->data != nums[i])
        {
            tail = tail->next;
        }
        if (tail->data == nums[i])
        {
            tail->count++;
            if (tail->count > numsSize / 2)
            {
                return tail->data;
            }
            continue;
        }
        else
        {
            if (plist->next == NULL && plist->count == 0)
            {
                plist->data = nums[i];
                plist->count++;
            }
            else
            {
                Mcount* newnode = (Mcount*)malloc(sizeof(Mcount));
                newnode->data = nums[i];
                newnode->count = 0;
                newnode->next = NULL;

                tail->next = newnode;
            }

        }
    }
    tail = plist;
    int max = 0;
    int last;
    for (int j = 0; tail; j++)
    {
        if (max < tail->count)
        {
            max = j;
            last = tail->data;

        }
        tail = tail->next;
    }


    return last;
}