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
    int findDepth(TreeNode* root){
        if(root==NULL) return 0;
        int left=findDepth(root->left);
        if (left!=-1) ++left;
        else return -1;
        int right=findDepth(root->right);
        if(right!=-1) ++right;
        else return -1;
        if (abs(left-right)>1) return -1;
        else return max(left,right);
    }
    bool isBalanced(TreeNode* root) {
        int height=findDepth(root);
        if(height<0) return false;
        else return true;
        
    }
};
