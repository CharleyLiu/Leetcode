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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL) return NULL;
        ListNode* it=head;
        ListNode* last=NULL;
        while(it->next!=NULL){
            while(it->next!=NULL&&it->next->val!=it->val) it=it->next;
            if(it->next!=NULL&&it->next->val==it->val) last=it;
            else continue;
            while(it->next!=NULL&&it->next->val==it->val) it=it->next;
            last->next=it->next;
        }
        return head;
    }
};
