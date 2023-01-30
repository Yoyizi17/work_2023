class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        multiset<char> s1;//�������ĵ�һ���Ź���
        multiset<char> s2;//
        multiset<char> s3;//

        set<char> s;//����ÿһ��

        int i = 0;
        while (i < 9)
        {

            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] == '.')//���ո�ֱ������
                    continue;

                if (s.find(board[i][j]) != s.end())//�ȼ����һ���Ƿ����ظ�����
                    return false;
                else
                    s.insert(board[i][j]);

                if (j < 3)
                {
                    if (s1.find(board[i][j]) != s1.end())//�ȼ����һ���Ƿ����ظ�����
                        return false;
                    else
                        s1.insert(board[i][j]);
                }
                else if (2 < j && j < 6)
                {
                    if (s2.find(board[i][j]) != s2.end())//�ȼ����һ���Ƿ����ظ�����
                        return false;
                    else
                        s2.insert(board[i][j]);
                }
                else
                {
                    if (s3.find(board[i][j]) != s3.end())//�ȼ����һ���Ƿ����ظ�����
                        return false;
                    else
                        s3.insert(board[i][j]);
                }

            }
            i++;
            s.clear();

            if (i % 3 == 0)//������еı����󣬶Ժ���������Ź�����м��
            {
                s1.clear();
                s2.clear();
                s3.clear();
            }

        }

        i = 0;
        while (i < 9)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[j][i] == '.')//���ո�ֱ������
                    continue;

                if (s.find(board[j][i]) != s.end())//�ȼ����һ���Ƿ����ظ�����
                    return false;
                else
                    s.insert(board[j][i]);

            }
            i++;
            s.clear();
        }


        return true;
    }
};