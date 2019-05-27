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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(m==n) return head;
        int count=1;
        ListNode* prev=NULL;
        ListNode* cur=head;
        ListNode* next=NULL;
        while(count<m){
            prev=cur;
            cur=cur->next;
            ++count;
        }
        ListNode* tail=cur;
        ListNode* beg=prev;
        ++count;
        prev=cur;
        cur=cur->next;
        while(count<n){
            next=cur->next;
            cur->next=prev;
            prev=cur;
            cur=next;
            ++count;
        }
        next=cur->next;
        cur->next=prev;
        if(beg!=NULL) beg->next=cur;
        else head=cur;
        tail->next=next;
        return head;
    }
};
