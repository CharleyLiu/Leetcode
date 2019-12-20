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
    int dfs(TreeNode* node, TreeNode* p, TreeNode* q,TreeNode*& ans)
    {
        if(node==NULL) return 0;
        if(ans!=NULL) return 0;
        int left=0;
        int right=0;
        int mid=0;
        left=dfs(node->left,p,q,ans);
        right=dfs(node->right,p,q,ans);
        mid=node==p ||node==q;
        if(left+right+mid>=2) ans=node;
        return min(1,left+right+mid);
        
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans=NULL;
        dfs(root,p,q,ans);
        return ans;
        
    }
};
