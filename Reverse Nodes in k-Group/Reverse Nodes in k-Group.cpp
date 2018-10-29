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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* p=head;
        ListNode** a=new ListNode*[k];
        ListNode* front;
        bool flag=false;
        for(int i=0;i<k;i++)
        {
            if(p==NULL) {flag=true;break;}
            a[i]=p;
            p=p->next;
        }
        if(flag) return head;
        front=a[0];
        head=a[k-1];
        for(int i=k-1;i>0;i--)
        {
            a[i]->next=a[i-1];
        }
        int i=0;
        while(p!=NULL)
        {
            if(i==k)
            {
                front->next=a[k-1];
                front=a[0];
                for(int j=k-1;j>0;j--)
                    a[j]->next=a[j-1];
                i=0;
            }
            a[i]=p;
            p=p->next;
            i++;
        }
        if(i==k)
            {
                front->next=a[k-1];
                front=a[0];
                for(int j=k-1;j>0;j--)
                    a[j]->next=a[j-1];
                front->next=NULL;
                return head;
            }
        else if(i>0)
        {
            front->next=a[0];
            for(int j=1;j<i;j++)
            {
                a[j-1]->next=a[j];
            }
            a[i-1]->next=NULL;
            return head;            
        }
        front->next=NULL;
        return head;    
    }
};
