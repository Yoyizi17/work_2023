#include<stdio.h>
#include<stdlib.h>

typedef struct TreeNode TNode;
typedef struct LNode
{
    int data;
    struct LNode* next;
}LNode;

void LNodeInit(LNode* plist)
{
    plist->data = 0;
    plist->next = NULL;
}

void LNodePushBack(LNode* plist, int x)
{
    if (plist == NULL)
    {
        LNode* newnode = (LNode*)malloc(sizeof(LNode));

        newnode->data = x;
        newnode->next = NULL;
        plist = newnode;
    }

    LNode* tail = plist;
    while (tail->next)
    {
        tail = tail->next;
    }
    LNode* newnode = (LNode*)malloc(sizeof(LNode));
    newnode->data = x;
    newnode->next = NULL;
    tail->next = newnode;
}

void Lastorder_Push(TNode* root, LNode* plist, int c)
{
    if (root == NULL)
    {
        LNodePushBack(plist, c);
        return;
    }


    Lastorder_Push(root->left, plist, c - 1);

    LNodePushBack(plist, root->val);

    Lastorder_Push(root->right, plist, c - 1);


}

void Firstorder_Push(TNode* root, LNode** plist, int c)
{
    if (root == NULL)
    {
        LNodePushBack(plist, c);
        return;
    }
    Lastorder_Push(root->right, plist, c - 1);
    LNodePushBack(plist, root->val);

    Lastorder_Push(root->left, plist, c - 1);


}

bool Check(LNode* plist1, LNode* plist2)
{
    if ((plist1 == NULL && plist2 != NULL) ||
        (plist1 != NULL && plist2 == NULL))
        return false;

    while (plist1 && plist2)
    {
        if (plist1->data != plist2->data)
            return false;

        plist1 = plist1->next;
        plist2 = plist2->next;
    }

    if ((plist1 == NULL && plist2 != NULL) ||
        (plist1 != NULL && plist2 == NULL))
        return false;

    if (plist1 == NULL && plist2 == NULL)
        return true;

    return false;
}

/////////
bool isSymmetric(struct TreeNode* root) {
    LNode st1;
    int c = -1;
    LNodeInit(&st1);
    Lastorder_Push(root->left, &st1, c);

    LNode st2;
    LNodeInit(&st2);
    Firstorder_Push(root->right, &st2, c);

    return Check(&st1, &st2);

}

int main()
{
    TNode root;
    isSymmetric(root);
    return 0;
}
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
typedef struct TreeNode TNode;

TNode* CreatTree(int* nums, int left, int right)
{
    if (left > right)
        return NULL;

    int mid = (left + right) / 2;
    TNode* root = (TNode*)malloc(sizeof(TNode));

    root->val = nums[mid];
    root->left = CreatTree(nums, left, mid - 1);
    root->right = CreatTree(nums, mid + 1, right);

    return root;

}

struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
    return CreatTree(nums, 0, numsSize - 1);
}