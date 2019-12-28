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
    ListNode* reverseList(ListNode* head) {
        stack<ListNode*> stk;
        ListNode* cur=head;
        while(cur){
            stk.push(cur);
            cur=cur->next;
        }
        ListNode* h=NULL;
        if(!stk.empty()){
            cur=stk.top();
            h=cur;
            stk.pop();
            while(!stk.empty()){
                cur->next=stk.top();
                cur=cur->next;
                stk.pop();
            }
            cur->next=NULL;
        }
        return h;
    }
};
