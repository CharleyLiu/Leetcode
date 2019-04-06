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
        if(head->next==NULL) return head;
        ListNode* it=head;
        ListNode* ans=NULL;
        ListNode* last=NULL;
        int tmp;
        while(it->next!=NULL)
        {
            if(it->next->val!=it->val){
                ans=it;
                break;
            }
            tmp=it->val;
            it=it->next;
            while(it->next!=NULL&&it->val==tmp) it=it->next;
            if(it->next==NULL&&it->val!=tmp) ans=it;
        }
        while(it->next!=NULL)
        {
            last=it;
            while(it->next!=NULL){
                it=it->next;
                tmp=it->val;
                bool flag=true;
                while(it->next!=NULL&&it->next->val==tmp){
                    it=it->next;
                    flag=false;
                } 
                if(flag) {
                    if(it!=last->next) last->next=it;
                    break;
                }
                else{
                    if(it->next==NULL){
                        last->next=NULL;
                        break;
                    }
                }
                
            }

        }
        return ans;
    }
};
