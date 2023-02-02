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
        for(int i = left; i < right ; i++)//��Ҫ���Ƶ�һ��
        {
            top.push_back(m[i][left]);
        }
        //int low = m[1][2];
        vector<int> low;
        for(int i = left; i < right ; i++)//��Ҫ�������һ��
        {
            low.push_back(m[i][right-1]);
        }

        vector<int> temp;//�������һ��
        for(int i = 0 ; i < m.size() ; i++)
        {
            temp.push_back(m[m.size()-1][i]);
        }

        for(int i = right-1; i >= left; i--)//����һ�Ÿ�ֵ�����һ�У��Ӻ�ǰ��
        {
            m[i][right-1] = m[left][i];
        }
        for(int i = right-1; i >= left; i--)//�����ȸ��ƺõ�temp��ֵ����һ�У��Ӻ�ǰ��
        {
            m[i][left] = temp[i];
        }

        if(right-left==2)
            return;

        //m[0][1] = top;
        for(int i = 1 ; i < right-1 ; i++)//�����ƺõ�top���м�Ԫ�ظ�ֵ����һ�š�
        {
            m[left][right-1-i] = top[i];
        }
        //m[2][1] = low;
        for(int i = 1 ; i < right-1 ; i++)//�����ƺõ�low���м�Ԫ�ظ�ֵ�����һ�š�
        {
            m[right-1][right-1-i] = low[i];
        }
    }
};*/
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        // C++ ����� = ������ֵ��������õ�һ���µ�����
        auto matrix_new = matrix;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                matrix_new[j][n - i - 1] = matrix[i][j];
            }
        }
        // ����Ҳ��ֵ����
        matrix = matrix_new;
    }
};