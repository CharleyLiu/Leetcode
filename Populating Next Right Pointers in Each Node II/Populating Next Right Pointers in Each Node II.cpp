/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/
class Solution {
public:
    Node* connect(Node* root) {
         queue<Node*> q={};
        if(root==NULL) return root;
        q.push(root);
        int count=1;
        int nextcount=0;
        Node* tmp=NULL;
        while(!q.empty())
        {
            for(int i=0;i<count;++i)
            {
                tmp=q.front();
                q.pop();
                if(i!=count-1) tmp->next=q.front();
                if(tmp->left!=NULL){
                    q.push(tmp->left);
                    ++nextcount;
                }
                if(tmp->right!=NULL){
                    q.push(tmp->right);
                    ++nextcount;
                }
            }
            count=nextcount;
            nextcount=0;
        }
        return root;
    }
};
