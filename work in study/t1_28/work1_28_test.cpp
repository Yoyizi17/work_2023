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
        int add = (numRows - 1) * 2;//����������ӡ�0��λ����Ҫ+���ٲ��ܵ�����һ����Ҫ����¼��Ԫ�ء�
        int len = s.size();
        string ret;//������¼���յ��ַ����������


        int bet = add;
        for (int i = 0; i < numRows; i++)
        {
            int num = 0;//�������ò���

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