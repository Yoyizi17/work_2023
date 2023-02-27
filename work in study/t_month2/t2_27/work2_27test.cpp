/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ret;

        Sork(root, ret, 0);
        int i = 0;
        for (vector<int> x : ret)
        {
            reverse(x.begin(), x.end());
        }
        return ret;
    }

    void Sork(TreeNode* root, vector<vector<int>>& ret, int n)
    {
        if (root == nullptr)
            return;

        if (ret.size() == n)
        {
            ret.push_back(vector<int>{root->val});
        }
        else
        {
            if (n % 2 == 1)
                ret[n].insert(ret[n].begin(), root->val);
            else
                ret[n].push_back(root->val);
        }


        Sork(root->left, ret, n + 1);
        Sork(root->right, ret, n + 1);

    }
};