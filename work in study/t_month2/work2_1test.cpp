class Solution {
public:
    /*string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") {
            return "0";
        }
        string ans = "0";
        int m = num1.size(), n = num2.size();
        for (int i = n - 1; i >= 0; i--) {
            string curr;
            int add = 0;
            for (int j = n - 1; j > i; j--) {
                curr.push_back(0);
            }
            int y = num2.at(i) - '0';
            for (int j = m - 1; j >= 0; j--) {
                int x = num1.at(j) - '0';
                int product = x * y + add;
                curr.push_back(product % 10);
                add = product / 10;
            }
            while (add != 0) {
                curr.push_back(add % 10);
                add /= 10;
            }
            reverse(curr.begin(), curr.end());

            ans = addStrings(ans, curr);
        }
        return ans;
    }*/
    string multiply(string num1, string num2) {
        string zero = "0";
        if (num1 == zero || num2 == zero)//如果其中一个字符串代表数字零，就返回零
            return zero;

        int len1 = num1.size();//获取两个字符串的长度
        int len2 = num2.size();

        //num1作为乘数，num2作为被乘数
        string ret = "0";
        for (int i = len1 - 1; i >= 0; i--)
        {
            string addnum;//作为加数，一次循环后与ret相加，并将结果赋给ret
            for (int j = i; j < len1 - 1; j++)//为add “乘10”
            {
                addnum += '0';
            }
            int ad;//记录“进位”
            int f1 = (int)num1[i] - '0';
            for (int j = len2 - 1; j >= 0; j--)
            {
                int f2 = (int)num2[j] - '0';//将被乘数的第1~len2-1位转化成整形

                int temp = f1 * f2 + ad;
                addnum += temp % 10 + 48;//将得数的最后一位转换成字符付给addnum
                ad = temp / 10;
            }
            while (ad > 0)
            {
                addnum += ad % 10 + 48;
                ad /= 10;
            }
            reverse(addnum.begin(), addnum.end());

            ret = addStrings(ret, addnum);
            addnum.clear();
            ad = 0;
        }

        return ret;
    }
    string addStrings(string& num1, string& num2)
    {
        int i = num1.size() - 1, j = num2.size() - 1, add = 0;
        string ans;
        while (i >= 0 || j >= 0 || add != 0)
        {
            int x = i >= 0 ? num1.at(i) - '0' : 0;
            int y = j >= 0 ? num2.at(j) - '0' : 0;
            int result = x + y + add;
            ans.push_back(result % 10);
            add = result / 10;
            i--;
            j--;
        }
        reverse(ans.begin(), ans.end());
        for (auto& c : ans) {
            c += '0';
        }
        return ans;
    }
};
class Solution {
public:
    string addStrings(string num1, string num2) {
        int i = num1.size() - 1;
        int j = num2.size() - 1;

        string ret;
        int ad = 0;
        while (i >= 0 || j >= 0)
        {
            int x = i >= 0 ? num1[i] - '0' : 0;
            int y = j >= 0 ? num2[j] - '0' : 0;

            int resault = x + y + ad;
            ret += resault % 10 + '0';
            ad = resault / 10;

            i--;
            j--;
        }
        while (ad > 0)
        {
            ret += ad % 10 + '0';
            ad /= 10;
        }

        reverse(ret.begin(), ret.end());

        return ret;
    }
};