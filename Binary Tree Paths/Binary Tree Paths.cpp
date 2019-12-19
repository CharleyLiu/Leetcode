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
    void dfs(TreeNode* node,vector<string>& ans,string& path)
    {
        if(node->left==NULL&&node->right==NULL)
        {
            ans.emplace_back(path);
            return;
        }
        if(node->left)
        {
            path+="->";
            path+=to_string(node->left->val);
            dfs(node->left,ans,path);
            int pos=path.rfind("->");
            path.erase(pos);
        }
        if(node->right)
        {
            path+="->";
            path+=to_string(node->right->val);
            dfs(node->right,ans,path);
            int pos=path.rfind("->");
            path.erase(pos);
        }
        return;
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans={};
        if(root==NULL) return ans;
        string path=to_string(root->val);
        dfs(root,ans,path);
        return ans;
        
        
    }
};
