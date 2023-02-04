#include<iostream>

#include<vector>
#include<string>
#include<set>

#include<algorithm>
using namespace std;



class Num
{
public:
    int m_num;
    int point;
    Num(int i, int j)
    {
        m_num = i;
        point = j;
    }
};

bool Is_true(Num& p1, Num p2)
{
    if (p1.m_num < p2.m_num)
        return true;
    else
        return false;
}

bool Ist(vector<int>::iterator a, vector<int>::iterator b)
{
    while()
}


class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<Num> num;//first用来储存字符数组中每一串字符的整型值之和,second为下标

        int i = 0;
        for (auto it = strs.begin(); it != strs.end(); it++)
        {
            string temp = *it;//创建一个临时的string变量储存字符串，方便遍历
            int tnum = 0;;//储存每个字符串的整型值之和
            for (auto itt = temp.begin(); itt != temp.end(); itt++)
            {
                tnum += (int)*itt;
            }
            num.push_back(Num(tnum,i));
            i++;
        }
        sort(num.begin(),num.end(),Is_true);
        vector<vector<string>> ret;
        for (auto it = num.begin(); it != num.end(); it++)
        {
            vector<string> temp;
            temp.push_back(strs[it->point]);
            while (it + 1 != num.end() && it->m_num == (it + 1)->m_num)
            {
                it++;
                temp.push_back(strs[it->point]);
            }
            ret.push_back(temp);
            temp.clear();
        }
        return ret;
    }
};

int main()
{
    vector<string> strs{ "eat", "tea", "tan", "ate", "nat", "bat" };
    Solution s;
    s.groupAnagrams(strs);
    return 0;
}