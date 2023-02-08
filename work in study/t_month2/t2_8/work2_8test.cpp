class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ret;
        for (int i = 0; i < n; i++)
        {
            ret.push_back(vector<int>(n));
        }

        Getcircle(0, n, 1, ret, n * n + 1);

        return ret;
    }

    void Getcircle(int left, int right, int val, vector<vector<int>>& ret, int done)
    {
        if (right - left < 0)
            return;

        for (int i = left; i < right; i++)
        {
            if (ret[left][i] == 0)
                ret[left][i] = val++;
        }
        if (val == done)
            return;
        for (int i = left + 1; i < right; i++)
        {
            if (ret[i][right - 1] == 0)
                ret[i][right - 1] = val++;
        }
        if (val == done)
            return;
        for (int i = right - 2; i >= 0; i--)
        {
            if (ret[right - 1][i])
                ret[right - 1][i] = val++;
        }
        if (val == done)
            return;
        for (int i = right - 2; i > 0; i--)
        {
            if (ret[i][left] == 0)
                ret[i][left] = val++;
        }
        if (val == done)
            return;
        Getcircle(left + 1, right - 1, val, ret, done);
    }

};