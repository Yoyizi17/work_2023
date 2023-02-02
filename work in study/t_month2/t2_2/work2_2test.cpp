/*class Solution {
public:
    void rotate(vector<vector<int>>& m) {
        int left = 0;
        int right = m.size();
        dg_rot(m,left,right);
    }
    void dg_rot(vector<vector<int>>& m,int left,int right)
    {


        if(right-left < 2)
            return;

        dg_rot(m,left+1,right-1);

        //int top = m[1][0];
        vector<int> top;
        for(int i = left; i < right ; i++)//需要复制第一列
        {
            top.push_back(m[i][left]);
        }
        //int low = m[1][2];
        vector<int> low;
        for(int i = left; i < right ; i++)//需要复制最后一列
        {
            low.push_back(m[i][right-1]);
        }

        vector<int> temp;//复制最后一排
        for(int i = 0 ; i < m.size() ; i++)
        {
            temp.push_back(m[m.size()-1][i]);
        }

        for(int i = right-1; i >= left; i--)//将第一排赋值给最后一列（从后到前）
        {
            m[i][right-1] = m[left][i];
        }
        for(int i = right-1; i >= left; i--)//将事先复制好的temp赋值给第一列（从后到前）
        {
            m[i][left] = temp[i];
        }

        if(right-left==2)
            return;

        //m[0][1] = top;
        for(int i = 1 ; i < right-1 ; i++)//将复制好的top的中间元素赋值给第一排。
        {
            m[left][right-1-i] = top[i];
        }
        //m[2][1] = low;
        for(int i = 1 ; i < right-1 ; i++)//将复制好的low的中间元素赋值给最后一排。
        {
            m[right-1][right-1-i] = low[i];
        }
    }
};*/
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        // C++ 这里的 = 拷贝是值拷贝，会得到一个新的数组
        auto matrix_new = matrix;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                matrix_new[j][n - i - 1] = matrix[i][j];
            }
        }
        // 这里也是值拷贝
        matrix = matrix_new;
    }
};