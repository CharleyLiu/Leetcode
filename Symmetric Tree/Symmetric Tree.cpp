/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool checkTwoTree(TreeNode* p, TreeNode* q)
    {
        if(p==NULL&&q==NULL) return true;
        if(p==NULL) return false;
        if(q==NULL) return false;
        if(p->val!=q->val) return false;
        return checkTwoTree(p->left,q->right) &&checkTwoTree(p->right,q->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(root==NULL) return true;
        return checkTwoTree(root->left,root->right);
        
    }
};
