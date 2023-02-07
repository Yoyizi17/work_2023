bool Swap(vector<int>& p1, vector<int>& p2)
{
    if (p1 < p2)
        return true;
    else
        return false;
}

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ret;
        sort(intervals.begin(), intervals.end(), Swap);
        for (auto x : intervals)
        {
            if (ret.size() != 0 && x[0] >= ret[ret.size() - 1][0] && x[1] <= ret[ret.size() - 1][1])
                continue;
            if (ret.size() != 0 && x[0] <= ret[ret.size() - 1][1] && x[1] >= ret[ret.size() - 1][1])
            {
                Add(ret, x);
                continue;
            }
            else if (ret.size() != 0 && x[0] <= ret[ret.size() - 1][0] && x[1] >= ret[ret.size() - 1][1])
            {
                Add(ret, x);
                continue;
            }
            else if (ret.size() != 0 && x[1] <= ret[ret.size() - 1][0] && x[0] >= ret[ret.size() - 1][0])
            {
                Add(ret, x);
                continue;
            }
            ret.push_back(vector<int>{x[0], x[1]});
        }
        return ret;
    }
    void Add(vector<vector<int>>& ret, vector<int>& x)
    {
        if (ret[ret.size() - 1][0] > x[0])
            ret[ret.size() - 1][0] = x[0];
        if (ret[ret.size() - 1][1] < x[1])
            ret[ret.size() - 1][1] = x[1];
        //ret[ret.size()-1][0] = ret[ret.size()-1][0] < x[0] ? ret[ret.size()-1][0] : x[0];
        //ret[ret.size()-1][1] = ret[ret.size()-1][1] < x[0] ? ret[ret.size()-1][1] : x[1];
    }

};