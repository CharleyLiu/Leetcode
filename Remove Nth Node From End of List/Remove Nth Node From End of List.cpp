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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode** a=new ListNode*[n+1];
        a[n]=NULL;
        int i=0;
        ListNode* p=head;
        while(p!=NULL)
        {
            a[i%(n+1)]=p;
            i++;
            p=p->next;
        }
        if(a[(i+1)%(n+1)]==head) return head->next;
        if(n==1) a[i%(n+1)]->next=NULL;
        else a[i%(n+1)]->next=a[(i+2)%(n+1)];
        return head;
    }
};
