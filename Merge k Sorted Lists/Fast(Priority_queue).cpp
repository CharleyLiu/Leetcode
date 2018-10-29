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
struct comp
{
public:
	bool operator ()(pair<int, ListNode*>& a, pair<int, ListNode*>& b) const
	{
		if (a.first > b.first) return true;
		return false;
	}
};
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>, comp> b;
        pair<int,ListNode*> temp;
        for(int i=0;i<lists.size();i++)
        {
            if(lists[i]!=NULL)
            {
                temp.first=lists[i]->val;
                temp.second=lists[i];
                b.push(temp);
            }
        }
        if(b.empty()) return NULL;
        ListNode* head=new ListNode(0);
        ListNode* p=head;
        while(!b.empty())
        {
            p->next=b.top().second;
            p=p->next;
            b.pop();
            if(p->next!=NULL)
            {
                temp.second=p->next;
                temp.first=p->next->val;
                b.push(temp);
            }
        }
        return head->next;
        
    }
};
