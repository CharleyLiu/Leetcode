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
    int subMaxPath(TreeNode* root,int& ans)
    {
        if(root==NULL) return 0;
        int l=max(subMaxPath(root->left,ans),0);
        int r=max(subMaxPath(root->right,ans),0);
        ans=max(l+r+root->val,ans);
        return max(l,r)+root->val;
    }
    int maxPathSum(TreeNode* root) {
        int ans=INT_MIN;
        subMaxPath(root,ans);
        return ans;
    }
};
