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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* a= new ListNode(l1->val+l2->val);
        ListNode *ans=a;
        int add=0;
        if (a->val>=10)
        {
            a->val=a->val-10;
            add=1;
        }
        {   
            ListNode* List1=l1;
            ListNode* List2=l2;
            while(List1->next!=NULL||List2->next!=NULL)
            {
                int number1, number2;
                if(List1->next==NULL)
                {
                    number1=0;
                    number2=List2->next->val;
                    List2=List2->next;
                }
                else
                {
                    number1=List1->next->val;
                    List1=List1->next;
                    if(List2->next==NULL)
                    {
                        number2=0;
                    }
                    else
                    {
                        number2=List2->next->val;
                        List2=List2->next;
                    }
                }
                a->next=new ListNode(number1+number2+add);
                add=0;
                a=a->next;
                if(a->val>=10)
                {
                    a->val-=10;
                    add=1;
                }   
            }           
        }
        if(add==1) a->next=new ListNode(1);
        return ans;   
    }
};
