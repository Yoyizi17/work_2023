#include<iostream>
using namespace std;
#include<queue>
#include<list>
#include<string>
#include<set>
#include<map>

//class Person
//{
//public:
//	Person(string name, int age)
//	{
//		m_name = name;
//		m_age = age;
//	}
//
//	string m_name;
//	int m_age;
//};
//
//int main()
//{
//	queue<Person> q ;
//
//	Person p1("ts", 100);
//	Person p2("swk", 1200);
//	Person p3("zbj", 12020);
//	Person p4("ss", 1040);
//
//	q.push(p1);
//	q.push(p2);
//	q.push(p3);
//	q.push(p4);
//
//	while (!q.empty())
//	{
//		cout << q.front().m_name <<"   "<<q.front().m_age<< endl;
////		q.pop();
////
////	}
////
////	cout << q.size();
////
////	return 0;
////}
//
//
//
//int main()
//{
//	list<int> l;
//	l.push_back(10);
//	l.push_back(20);
//	l.push_back(30);
//	l.push_back(40);
//
//	l.push_front(-10);
//	l.push_front(-20);
//	l.push_front(-30);
//	l.push_front(-40);
//
//	//l.pop_back();
//	//l.pop_front();
//
//	list<int>::iterator it = l.begin();
//	l.erase(++it);
//
//	for (list<int>::iterator it = l.begin(); it != l.end(); it++)
//	{
//		cout << (*it) << endl;
//	}
//	return 0;
//}

//int main()
//{
//	string s = "12345";
//	cout << s.at(1);
//	return 0;
////}
//
//class Person
//{
//public:
//	string m_name;
//	int m_age;
//	int m_height;
//	Person(string name, int age, int height)
//	{
//		m_name = name;
//		m_age = age;
//		m_height = height;
//	}
//};
//
//void Print(vector<Person>& a)
//{
//	for (vector<Person>::iterator it = a.begin(); it != a.end(); it++)
//	{
//		cout << "姓名是：" << (*it).m_name << "\t年龄：" << (*it).m_age << "\t身高：" << (*it).m_height << endl;
//	}
//}
//
//bool compare(Person& p1, Person& p2)
//{
//	Person p1("张三", 20, 155);
//	Person p2("李四", 10, 165);
//	Person p3("王五", 30, 175);
//	Person p4("赵六", 30, 190);
//	a.push_back(p1);
//	a.push_back(p2);
//	a.push_back(p3);
//	a.push_back(p4);
//}
//
//int main()
//{
//	vector<Person> a;
//	Person p1("张三", 20, 155);
//	Person p2("李四", 10, 165);
//	Person p3("王五", 30, 175);
//	Person p4("赵六", 30, 190);
//	a.push_back(p1);
//	a.push_back(p2);
//	a.push_back(p3);
//	a.push_back(p4);
//
//	Print(a);
//	cout << "-----------------------------------\n排序后："<<endl;
//	sort(a.begin(),a.end(), compare);
//
//	Print(a);
//
//	return 0;
//}
//#include<set>
//int main()
//{
//	set<int> s;
//	pair < set<int>::iterator, bool > ret = s.insert(10);
//	if (ret.second)
//	{
//		cout << "zhengque";
//	}
//	else
//	{
////		cout << "失败";
////	}
////	return 0;
////}
//
//class Person
//{
//public:
//	string m_name;
//	int m_age;
//	int m_height;
//	Person(string name, int age, int height)
//	{
//		m_name = name;
//		m_age = age;
//		m_height = height;
//	}
//};
//
//class MyCompare
//{
//public:
//	bool operator()(const Person& a,const Person& b)const
//	{
//		if (a.m_age == b.m_age)
//			return a.m_height > b.m_height;
//		return a.m_age > b.m_age;
//	}
//};
//
//void Print(set<Person,MyCompare>& s)
//{
//	for (set<Person,MyCompare>::iterator it = s.begin(); it != s.end(); it++)
//	{
//		cout << "姓名是：" << (*it).m_name << "年龄：" << (*it).m_age << "身高：" << (*it).m_height << endl;
//	}
//}
//
//int main()
//{
//	set<Person, MyCompare>s;
//	Person p1("张三", 20, 155);
//	Person p2("李四", 10, 165);
//	Person p3("王五", 30, 175);
//	Person p4("赵六", 30, 190);
//	s.insert(p1);
//	s.insert(p2);
//	s.insert(p3);
//	s.insert(p4);
//	Print(s);
//	return 0;
//}
//
//void Print(map<int, int>& m)
//{
//	for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
//	{
//		cout << "key：" << it->first << "\tvalue：" << it->second << endl;
//	}
//}
//
//int main()
//{
//	/*map<int, int> m;
//	m.insert(pair<int, int>(1, 10));
//	m.insert(pair<int, int>(2, 20));
//	m.insert(pair<int, int>(3, 30));
//	m.insert(pair<int, int>(4, 40));
//
//	Print(m);*/
//	/*vector<int> v = { 1,2,2,3,4,5, 3 };
//	set<int> s = { 1,2,2,3,4,5, 3 };
//	if (s.find(66) == s.end())
//		cout << "没有";*/
//	int i = 0; int j = 4; int h = 9;
//	vector<vector<int>> v;
//	v.push_back({ i,j,h });
//	int ff = 10;
//	unsigned int gg = ff;
//	return 0;
//}

class Solution {
public:
    int Findstr(string& s, int left, int right)
    {
        while (left >= 0 && right < s.size() && s.at(left) == s.at(right))
        {
            left--;
            right++;
        }

        return right - left - 1;
    }
    string longestPalindrome(string s) {
        if (s.size() < 2)
            return s;
        int left = 0;
        int right = 0;
        int len = s.size();
        for (int i = 0; i < len; i++)
        {
            int len1 = Findstr(s, i, i);
            int len2 = Findstr(s, i, i + 1);
            int len3 = len1 > len2 ? len1 : len2;
            if (len3 > right - left + 1)
            {
                left = i - (len3 - 1) / 2;
                right = i + len3 / 2;
            }
        }
        return s.substr(left, right - left + 1);
    }
};

int main()
{
    vector<int> vv=
}
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ret;
        int len = nums.size();

        for (int First = 0; First < len; First++)
        {
            if (First > 0 && nums[First] == nums[First - 1])
                continue;
            int tag = -nums[First];
            int Third = len - 1;
            for (int Second = First + 1; Second < len; Second++)
            {
                if (Second > First + 1 && nums[Second] == nums[Second - 1])
                    continue;

                while (Second<Third && nums[Second] + nums[Third]>tag)
                    Third--;

                if (Second == Third)
                    break;

                if (nums[Second] + nums[Third] == tag)
                    ret.push_back({ nums[First],nums[Second],nums[Third] });
            }
        }
        return ret;
    }
};
