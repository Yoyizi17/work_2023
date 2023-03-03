#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int ret = 0;
        for (int i = 0; i + 2 < nums.size() ; i+=2)
        {
            int count = 0;
            while (i + 2 < nums.size() && nums[i] - nums[i + 1] == nums[i + 1] - nums[i + 2])
            {
                i++;
                count++;
            }

            ret += count * (count + 1) / 2;
        }

        return ret;
    }
};

int main()
{
    vector<int> nums{ 1,2,3,8,9,10 };
    Solution s;
    cout<<s.numberOfArithmeticSlices(nums);

    return 0;
}