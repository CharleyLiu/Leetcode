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
    bool checktree(TreeNode* node, int lower, int upper)
    {
        if(node==NULL) return true;
        if(node->val<=lower||node->val>=upper) return false;
        bool flag=checktree(node->left,lower,node->val);
        if(!flag) return false;
        return checktree(node->right,node->val,upper);
    }
    bool isValidBST(TreeNode* root) {
        if(root==NULL) return true;
        if(root->left==NULL&&root->right==NULL) return true;
        return checktree(root,INT_MIN,INT_MAX);
    }
};
