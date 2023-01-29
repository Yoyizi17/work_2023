#include<iostream>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
typedef ListNode LNode;
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;
        LNode* l1 = head;
        LNode* l2 = l1->next;
        LNode* prev = l1;
        head = l2;

        while (l1)
        {
            prev->next = l2;
            l1->next = l2->next;
            l2->next = l1;
            prev = l1;
            l1 = l1->next;

            if (l1)
            {
                l2 = l1->next;
            }
            if (l2 == NULL)
                return head;

        }

        return head;
    }
};