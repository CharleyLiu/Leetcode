/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/
class Solution {
public:
    unordered_map<Node*,Node*> map;
    Node* copyRandomList(Node* head) {
        if(head==NULL) return NULL;
        if(map.find(head)==map.end())
        {
            map[head]=new Node;
            map[head]->val=head->val;
            map[head]->next=copyRandomList(head->next);
            map[head]->random=copyRandomList(head->random);
            return map[head];
        }
        else return map[head];
        
    }
};
