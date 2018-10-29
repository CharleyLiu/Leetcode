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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        for(int i=0;i<lists.size();i++)
        {
            if(lists[i]==NULL) {lists.erase(lists.begin()+i);i--;}
        }
        int len=lists.size();
        if(len==0) return NULL;
        int small=0;
        for(int i=1;i<len;i++)
        {
            if(lists[i]->val<lists[small]->val) small=i;
        }
        ListNode* head=lists[small];
        lists[small]=lists[small]->next;
        if(lists[small]==NULL) lists.erase(lists.begin()+small);
        ListNode* ans=head;
        while(lists.size()!=0)
        {
            small=0;
            for(int i=0;i<lists.size();i++)
            {
                if(lists[i]->val<lists[small]->val) small=i;
            }
            head->next=lists[small];
            head=head->next;
            lists[small]=lists[small]->next;
            if(lists[small]==NULL) lists.erase(lists.begin()+small);
        }
        return ans;
        
    }
};
