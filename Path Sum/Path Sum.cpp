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
    bool hasPathSum(TreeNode* root, int sum) {
        if(root==NULL) return false;
        if(root->left==NULL&&root->right==NULL&&sum==root->val) return true;
        bool left=false;
        bool right=false;
        if(root->left!=NULL) left=hasPathSum(root->left,sum-root->val);
        if (left) return left;
        if(root->right!=NULL) return hasPathSum(root->right,sum-root->val);
        else return left;
    }
};
