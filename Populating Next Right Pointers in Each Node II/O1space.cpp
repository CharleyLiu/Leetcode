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
        Node* cur=root;
        Node* beg=NULL;
        Node* end=NULL;
        while(cur)
        {
            if(cur->left){
                if(beg) beg=beg->next=cur->left;
                else{
                    end=beg=cur->left;
                }
            }
            if(cur->right){
                if(beg) beg=beg->next=cur->right;
                else{
                    end=beg=cur->right;
                }
            }
            cur=cur->next;
            if(cur==NULL)
            {
                cur=end;
                end=beg=NULL;
            }
        }
        return root;
    }
};
