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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        if (root == nullptr)
            return ret;
        int num = 0;
        Order(ret, root, num);
        return ret;
    }
    void Order(vector<vector<int>>& ret, TreeNode* root, int num)
    {
        if (root == nullptr)
            return;

        if (ret.size() == num)
        {
            vector<int>temp;
            temp.push_back(root->val);
            ret.push_back(temp);
        }
        else
            ret[num].push_back(root->val);

        Order(ret, root->left, num + 1);
        Order(ret, root->right, num + 1);
    }
};