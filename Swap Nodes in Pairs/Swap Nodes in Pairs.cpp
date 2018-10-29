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
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL) return NULL;
        if(head->next==NULL) return head;
        ListNode* a[2];
        int i=0;
        ListNode* p=head->next->next;
        ListNode* front=head;
        head=head->next;
        head->next=front;     
        while(p!=NULL)
        {
            if(i==2)
            {
                front->next=a[1];
                a[1]->next=a[0];
                front=a[0];
                i=0;
            }
            a[i]=p;
            p=p->next;
            i++;
        }
        if(i==2)
            {
                front->next=a[1];
                a[1]->next=a[0];
                front=a[0];
            }
        if(i==1)
        {
            front->next=a[0];
            front=a[0];
        }
        front->next=NULL;
        return head;
    }
};
