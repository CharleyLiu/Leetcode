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
        ListNode* head=new ListNode(l1->val);
        if(l1->val<l2->val)
        {
            head->next=mergeTwoLists(l1->next,l2);
        }
        else{
            head->val=l2->val;
            head->next=mergeTwoLists(l1,l2->next);
        }
        return head;
    }
};
