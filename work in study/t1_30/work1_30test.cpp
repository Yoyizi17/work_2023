class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        multiset<char> s1;//储存横向的第一个九宫格
        multiset<char> s2;//
        multiset<char> s3;//

        set<char> s;//储存每一行

        int i = 0;
        while (i < 9)
        {

            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] == '.')//“空格”直接跳过
                    continue;

                if (s.find(board[i][j]) != s.end())//先检查这一行是否有重复数字
                    return false;
                else
                    s.insert(board[i][j]);

                if (j < 3)
                {
                    if (s1.find(board[i][j]) != s1.end())//先检查这一行是否有重复数字
                        return false;
                    else
                        s1.insert(board[i][j]);
                }
                else if (2 < j && j < 6)
                {
                    if (s2.find(board[i][j]) != s2.end())//先检查这一行是否有重复数字
                        return false;
                    else
                        s2.insert(board[i][j]);
                }
                else
                {
                    if (s3.find(board[i][j]) != s3.end())//先检查这一行是否有重复数字
                        return false;
                    else
                        s3.insert(board[i][j]);
                }

            }
            i++;
            s.clear();

            if (i % 3 == 0)//完成三行的遍历后，对横向的三个九宫格进行检测
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
                if (board[j][i] == '.')//“空格”直接跳过
                    continue;

                if (s.find(board[j][i]) != s.end())//先检查这一行是否有重复数字
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