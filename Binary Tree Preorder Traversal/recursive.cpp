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
    void dfs(TreeNode* node, vector<int>& ans)
    {
        ans.push_back(node->val);
        if(node->left) dfs(node->left,ans);
        if(node->right) dfs(node->right,ans);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        if(root==NULL) return {};
        vector<int> ans={};
        dfs(root,ans);
        return ans;
        
    }
};
