class Solution {
public:
    string multiply(string nums1, string nums2) {

    }

    /* {
    if (nums1 == "0" || nums2 == "0") {
        return "0";
    }


    int len1 = nums1.size();//求出长度，用于确定整型数字的最大位
    unsigned long long num1 = 0;//储存num1代表的整型值

    int f2 = nums2.size() - 1;//f2是指向nums2最后一个字符的指针
    int conf2 = f2;

    for(int i = 0; i < len1 ; i++)//求出num1的整形值
    {
        unsigned long long temp1 = (unsigned long long)nums1[i]-48;

        num1 += temp1*pow(10,len1-i-1);
    }


    //先把一次过程做好
    unsigned long long every = (unsigned long long)nums2[f2] - '0';
    unsigned long long temp = num1 * every *pow(10,conf2-f2);
    string ret;
    while(temp>0)
    {
        ret += '0' + temp%10;
        temp/=10;
    }
    reverse(ret.begin(),ret.end());
    f2--;

    string strtemp;
    while(f2>=0)
    {
        unsigned long long every = nums2[f2] - '0';
        temp = (unsigned long long)num1 * every *pow(10,conf2-f2);
        while(temp>0)
        {
            strtemp += '0' + temp%10;
            temp/=10;
        }
        reverse(strtemp.begin(),strtemp.end());
        ret = addStrings(ret,strtemp);
        strtemp.clear();

        f2--;
    }

    return ret;

}

string addStrings(string num1, string num2) {
    int i = num1.length() - 1, j = num2.length() - 1, add = 0;
    string ans = "";
    while (i >= 0 || j >= 0 || add != 0) {
        int x = i >= 0 ? num1[i] - '0' : 0;
        int y = j >= 0 ? num2[j] - '0' : 0;
        int result = x + y + add;
        ans.push_back('0' + result % 10);
        add = result / 10;
        i -= 1;
        j -= 1;
    }
    // 计算完以后的答案需要翻转过来
    reverse(ans.begin(), ans.end());
    return ans;
}
    /*
    for(int i = 0; i < len2 ; i++)
    {
        unsigned long long temp2 = (unsigned long long)nums2[i]-48;

        num2 += temp2*pow(10,len2-i-1);
    }
    num1/=2;
    num2/=2;
    string ret;
    unsigned long long num = num1*num2;
    if(num==0)
    {
        string cao ="0";
        return cao;
    }

    while(num>0)
    {
        ret += '0' + num%10;
        num/=10;
    }
    for(int i = pow(10,8); i >= 1; i/=10 )
    {
        if( i < num )
        {
            int temp = num/i;

            ret += '0'+ temp;

            num %= i;

        }
    }

    reverse(ret.begin(),ret.end());

    return ret;*/

};