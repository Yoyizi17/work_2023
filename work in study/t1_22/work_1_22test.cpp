#include<iostream>
#include<algorithm>
#include<vector>
#include<deque>
#include<array>
#include<string>
using namespace std;

//void M_Print(int i)
//{
//	cout << i << "   ";
//}
//
//int main()
//{
//	//vector<int> v2 = { 1,2,3,4,5,6,7,8,9 };
//
//	///*cout << v2.capacity() << endl;
//	//cout << v2.size() << endl;
//	//v2.resize(15);
//	//for_each(v2.begin(), v2.end(), M_Print);
//	//cout << v2.capacity() << endl;*/
//
//	//vector<int>::iterator it = v2.begin();
//	////it[2] = 4;
//	////cout << v2.begin()[2] << endl;*/
//
//
//	//v2.insert(v2.begin(),33);
//
//	//
//
//	//vector<int> demo{ 1,2 };
//	////第一种格式用法
//	//demo.insert(demo.begin(), 3);//{1,3,2}
//	//for_each(demo.begin(), demo.end(), M_Print);
//
//	//vector<int> v;
//	//for (int i=0;i<100000;i++)
//	//{
//	//	v.push_back(i);
//	//}
// //   
//	//cout << v.capacity() << endl;
//	//cout << v.size();
//
//
//	return 0;
//}

//void Print(const deque<int> d)
//{
//	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
//	{
//		/**it = 9;*/
//		cout << *it << "   ";
//	}
//}
//
//int main()
//{
//	deque<int> d1;
//	for (int i = 0; i < 10; i++)
//	{
//		d1.push_back(i);
//	}
//
//	Print(d1);
//	cout << endl;
//
//	deque<int> d2=d1;
//
//	Print(d2);
//	return 0;
//}

//class Person
//{
//public:
//	Person(string name,int age)
//	{
//		m_name = name;
//		m_age = age;
//	}
//	string m_name;
//	int m_age;
//};
//
//void InitPlayer(vector<Person>& v)
//{
//	string nameseed = "ABCDE";
//	for (int i = 0; i < 5; i++)
//	{
//		string name = "Player";
//		name += nameseed[i];
//		int sc = 0;
//
//		Person p(name, sc);
//		v.push_back(p);
//	}
//}
//
//void Setscore(vector<Person>& v)
//{
//	srand((unsigned int)time(NULL));
//	
//	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
//	{
//		deque<int> d;
//		for (int i = 0; i < 10; i++)
//		{
//			d.push_back(rand() % 41 + 60);
//		}
//		sort(d.begin(), d.end());
//		int all = 0;
//		for (int i = 1; i < 9; i++)
//		{
//			all += d[i];
//		}
//
//		(*it).m_age = all / 8;
//	}
//	
//}
//
//int main()
//{
//	vector<Person> vPlayer;
//	InitPlayer(vPlayer);
//	Setscore(vPlayer);
//
//	for (vector<Person>::iterator it = vPlayer.begin(); it != vPlayer.end(); it++)
//	{
//		cout << (*it).m_name<<"   "<<(*it).m_age << endl;
//	}
//
//	int best = 0;
//	for (vector<Person>::iterator it = vPlayer.begin(); it != vPlayer.end(); it++)
//	{
//		if (best < (*it).m_age)
//			best = (*it).m_age;
//	}
//
//	cout << "最高分是：" << best << endl;
//
//	return 0;
//}

class Solution {
public:
    string longestPalindrome(string s)
    {
        if (s.size() < 2)
            return s;
        int len = s.size();

        string ret;
        ret= s[0];
        int retlen = 1;

        for (int zh = 0; zh<len && len - zh>retlen; zh++)
        {
            int i = zh - 1;
            int j = zh + 1;
            int ijsize = 3;
            for (; i > 0 && j < len; i--, j++)
            {
                if (s[i] == s[i + 1] && j - i == 2)
                {
                    ret = s.substr(i, 2);
                    retlen = 2;
                }
                else if (s[j] == s[j - 1] && j - i == 2)
                {
                    ret = s.substr(j-2, 2);
                    retlen = 2;
                }
                if (s[i] == s[j])
                {
                    ret = s.substr(i, ijsize);
                    retlen = ret.size();
                    ijsize += 2;
                }
                else
                    break;
            }
        }


        return ret;
    }
};
int main()
{
    string w = "aaa";
    Solution s;
    string ret = s.longestPalindrome(w);
    cout << ret;
}

class Solution {
public:
    pair<int, int> expandAroundCenter(const string& s, int left, int right) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            --left;
            ++right;
        }
        return { left + 1, right - 1 };
    }

    string longestPalindrome(string s) {
        int start = 0, end = 0;
        for (int i = 0; i < s.size(); ++i) {
            auto [left1, right1] = expandAroundCenter(s, i, i);
            auto [left2, right2] = expandAroundCenter(s, i, i + 1);
            if (right1 - left1 > end - start) {
                start = left1;
                end = right1;
            }
            if (right2 - left2 > end - start) {
                start = left2;
                end = right2;
            }
        }
        return s.substr(start, end - start + 1);
    }
};
