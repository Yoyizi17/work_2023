#include<iostream>
using namespace std;

template<class T>
int add(T& a, T& b)
{
	return a + b;
}

int main()
{
	string s;
	string s2 = "pdc";
	s += s2[1];
	cout << s;
	return 0;
}

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1)
            return s;
        int add = (numRows - 1) * 2;//用来计算出从“0”位置需要+多少才能到达下一个需要被记录的元素。
        int len = s.size();
        string ret;//用来记录最终的字符串（结果）


        int bet = add;
        for (int i = 0; i < numRows; i++)
        {
            int num = 0;//用来设置步长

            while (i + num < len)
            {

                ret += s[i + num];
                if (i + num + bet < len && bet != add && bet != 0)
                    ret += s[i + num + bet];

                num += add;
            }
            bet -= 2;
        }

        return ret;
    }
};