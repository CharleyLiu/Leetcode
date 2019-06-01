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
private:
    unordered_map<Node*,Node*> mapper;
public:
    Node* copyRandomList(Node* it) {
        if(it==NULL) return NULL;
        mapper[it]=new Node;
        mapper[it]->val=it->val;
        if(mapper.find(it->random)==mapper.end()) mapper[it]->random=copyRandomList(it->random);
        else mapper[it]->random=mapper[it->random];
        if(mapper.find(it->next)==mapper.end()) mapper[it]->next=copyRandomList(it->next);
        else mapper[it]->next=mapper[it->next];
        return mapper[it];
    }
};
