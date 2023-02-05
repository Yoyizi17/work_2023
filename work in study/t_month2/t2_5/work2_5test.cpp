class J
{
public:
    int sum;
    int leftp;
    int rightp;
    J(int a, int b, int c)
    {
        sum = a;
        leftp = b;
        rightp = c;
    }
};

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_sum = nums[0];

        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i - 1] < 0)
                continue;
            else
            {
                nums[i] += nums[i - 1];
            }
        }

        return Max(nums);
    }
    int Max(vector<int>& nums)
    {
        int max_sum = nums[0];
        for (auto it = nums.begin(); it != nums.end(); it++)
        {
            max_sum = max_sum > *it ? max_sum : *it;
        }
        return max_sum;
    }
    /*    int max_sum = nums[0];

        int befor_sum = nums[0];
        for(int i = 1; i < nums.size(); i++)
        {
            int cur_sum = Maxadd(nums[i],befor_sum);
            befor_sum = cur_sum;

            max_sum = max_sum > cur_sum ? max_sum : cur_sum;
        }

        return max_sum;
    }
    int Maxadd(int cur,int befor_sum)
    {
        if(befor_sum < 0)
            return cur;
        else
            return cur + befor_sum;
    }*/
    /*    J jd(nums[0],0,0);

        for(int i = 0; i < nums.size(); i++)
        {
            int temp_sum = nums[i];
            if(temp_sum > jd.sum)
                jd.sum = temp_sum;
            for(int j = i + 1; j < nums.size(); j++)
            {
                temp_sum += nums[j];
                    if(temp_sum > jd.sum)
                    {
                        jd.sum = temp_sum;
                        jd.leftp = i;
                        jd.rightp = j;
                    }
            }
        }
        return jd.sum;
    }*/
};