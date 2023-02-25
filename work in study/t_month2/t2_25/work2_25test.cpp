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
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode* prev = head;
        ListNode* tail = head;

        while (tail->next != nullptr)
        {
            while (tail->next != nullptr && tail->val == tail->next->val)
            {
                tail = tail->next;
            }

            if (tail->next == nullptr && prev->val == prev->next->val)
                return 0;
            else if (tail->next == nullptr)
            {
                prev->next = nullptr;
                return head;
            }

            tail = tail->next;

            if (prev->val == prev->next->val)
            {
                head = tail;
                prev = tail;
                continue;
            }

            prev->next = tail;
            if (tail != nullptr && tail->next != nullptr && tail->val != tail->next->val)
            {
                prev = tail;
                tail = tail->next;
            }
            else if (tail == nullptr || tail->next == nullptr)
                return head;
        }
        return head;
    }
};