class Solution {
public:
    void sortColors(vector<int>& nums) {
        int size = nums.size();
        int key = nums[0];

        QuickSort(0, size - 1, nums);
    }

    void QuickSort(int left, int right, vector<int>& nums)
    {
        if (left >= right)
            return;
        int begin = left;
        int end = right;
        int point = begin;
        int key = nums[begin];

        while (begin < end)
        {
            while (begin < end && nums[end] >= key)
            {
                end--;
            }
            if (nums[end] < key)
            {
                nums[point] = nums[end];
                point = end;
            }

            while (begin < end && nums[begin] <= key)
            {
                begin++;
            }
            if (nums[begin] > key)
            {
                nums[point] = nums[begin];
                point = begin;
            }
        }
        nums[begin] = key;

        QuickSort(left, point - 1, nums);
        QuickSort(point + 1, right, nums);
    }
};