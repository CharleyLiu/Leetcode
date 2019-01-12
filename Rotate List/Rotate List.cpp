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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL) return head;
        ListNode* it=head;
        int len=1;
        while(it->next!=NULL)
        {
            it=it->next;
            ++len;
        }
        it->next=head;
        len=len-k%len;
        for(int i=0;i<len;++i)
        {
            it=it->next;
        }
        ListNode* ans=it->next;
        it->next=NULL;
        return ans;
    }
};
