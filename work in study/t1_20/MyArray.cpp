#include"MyArray.hpp"

class Person
{
public:
	string m_name;
	int m_age;

	Person() {};
	Person(string name, int age)
	{
		m_name = name;
		m_age = age;
	}
};

int main()
{
	/*MyArray<int> m(10);*/
	//for (int i = 0; i < 5; i++)
	//{
	//	m.PushBack(i);
	//}
	//for (int i = 0; i < 5; i++)
	//{
	//	cout << m[i] << endl;
	//}
	//m.PokeBack();
	//int size = m.GetArrSize();
	//for (int i = 0; i < size; i++)
	//{
	//	cout << m[i] << endl;
	//}
	
	MyArray<Person> m(10);
	Person p1("张三", 20);
	Person p2("李四", 90);
	Person p3("王五", 80);
	Person p4("赵六", 220);

	m.PushBack(p1);
	m.PushBack(p2);
	m.PushBack(p3);
	m.PushBack(p4);
	int size = m.GetArrSize();
	for (int i = 0; i < size; i++)
	{
		cout << m[i].m_name << "         " << m[i].m_age << endl;
	}

	return 0;
}int cmpfunc(const void* a, const void* b)
{
	return (*(int*)a - *(int*)b);
}
bool containsDuplicate(int* nums, int numsSize) {
	qsort(nums, numsSize, 4, cmpfunc);
	for (int i = 0; i < numsSize - 1; i++)
	{
		if (nums[i] == nums[i + 1])
			return true;
	}
	return false;
}