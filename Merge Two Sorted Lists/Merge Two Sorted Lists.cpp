/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==NULL) return l2;
        if(l2==NULL) return l1;
        ListNode* head;
        if (l1->val < l2->val)
        {
            head = l1;
            l1 = l1->next;
        }
        else
        {
            head = l2;
            l2 = l2->next;
        }
        ListNode* p = head;
        while (l1 != NULL && l2 != NULL)
        {
            if (l1->val < l2->val)
            {
                head->next = l1;
                head = l1;
                l1 = l1->next;
            }
            else
            {
                head->next = l2;
                head = l2;
                l2 = l2->next;
            }
        }
        if (l1 != NULL)
        {
            head->next = l1;
        }
        if (l2 != NULL)
        {
            head->next = l2;
        }
        return p;
    }
};
