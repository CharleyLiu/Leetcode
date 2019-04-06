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
    ListNode* partition(ListNode* head, int x) {
        if(head==NULL) return head;
        ListNode* a=new ListNode(INT_MIN);
        a->next=head;
        ListNode* lesslast=a;
        ListNode* morelast=NULL;
        ListNode* morehead=NULL;
        while(lesslast->next!=NULL&&lesslast->next->val<x) lesslast=lesslast->next;
        if (lesslast->next==NULL) return head;
        morelast=lesslast->next;
        morehead=morelast;
        while(morelast->next!=NULL&&morelast->next->val>=x)morelast=morelast->next;
        if(morelast->next==NULL) return head;
        while(morelast->next!=NULL&&lesslast->next!=NULL){
            lesslast->next=morelast->next;
            while(lesslast->next!=NULL&&lesslast->next->val<x) lesslast=lesslast->next;
            morelast->next=lesslast->next;
            if(lesslast->next==NULL) break;
            while(morelast->next!=NULL&&morelast->next->val>=x)morelast=morelast->next;
        }
        lesslast->next=morehead;
        return a->next;
            
        }
};
