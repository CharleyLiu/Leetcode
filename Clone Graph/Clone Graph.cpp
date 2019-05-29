/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
private:
    unordered_map<Node*,Node*> mapper;
public:
    Node* cloneGraph(Node*& node) {
        if(node==NULL) return NULL;
        if(mapper.find(node)==mapper.end())
        {
            Node* newcur=new Node(node->val,{});
            mapper[node]=newcur;
            for(Node* i:node->neighbors)
            {
                Node* tmp=cloneGraph(i);
                newcur->neighbors.push_back(tmp);
            }
        }
        return mapper[node];
    }
};
