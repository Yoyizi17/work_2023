#include<stdio.h>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


 /**
  * Note: The returned array must be malloced, assume caller calls free().
  */


struct LNode
{
    int data;
    struct LNode* next;
};

void LNodeInit(struct LNode* plist)
{
    plist = (struct LNode*)malloc(sizeof(struct LNode));
    plist->data = 1;
    plist->next = NULL;
}

void LNodePushBack(struct LNode* plist, int x)
{
    if (plist->next == NULL)
    {
        plist->data = x;
        return;
    }

    struct LNode* newnode = (struct LNode*)malloc(sizeof(struct LNode));
    newnode->data = x;
    newnode->next = NULL;

    struct LNode* tail = plist;
    while (tail->next != NULL)
    {
        tail = tail->next;
    }

    tail->next = newnode;

}

void Inorder(struct TreeNode* root, int* returnSize, int* a)
{
    if (root == NULL)
        return;



    Inorder(root->left, returnSize, a);

    a[(*returnSize)++] = root->val;

    Inorder(root->right, returnSize, a);


}


int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int* a = (int*)malloc(sizeof(int) * 555);
    *returnSize = 0;

    Inorder(root, returnSize, a);

    return a;
}

//void inorder(struct TreeNode* root, int* res, int* resSize) {
//    if (!root) {
//        return;
//    }
//    inorder(root->left, res, resSize);
//    res[(*resSize)++] = root->val;
//    inorder(root->right, res, resSize);
//}
////
//int* inordeTraversal(struct TreeNode* root, int* returnSize) {
///    int* res = malloc(sizeof(int) * 501);
//    *returnSize = 0;
//    inorder(root, res, returnSize);
//    return res;
//}//
//
//vo//id inordr(struct TreeNode* root, int* res, int* resSize) {
  //  if (!root) {
    //    return;
  //  }//
  //  inorder(root->left, res, resSize);
 //   res[(*resSize)++] = root->val;
 //   inorder(root->right, res, resSize);
//}

//int* inorderTravrsal(struct TreeNode* root, int* returnSize)// {
//    int* res = malloc(sizeof(int) * 501);
//    *returnSize = 0;
 //   inorder(root, res, returnSize);
 //   return res;
//}
