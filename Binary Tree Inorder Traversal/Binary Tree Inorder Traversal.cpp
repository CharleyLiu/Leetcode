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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans={};
        if(root==NULL) return ans;
        unordered_set<TreeNode*> visited;
        stack<TreeNode*> stk;
        TreeNode* tmp=NULL;
        stk.push(root);
        visited.insert(root);
        while(!stk.empty())
        {
            tmp=stk.top();
            if(tmp->left!=NULL&&visited.find(tmp->left)==visited.end()){
                stk.push(tmp->left);
                visited.insert(tmp->left);
                continue;
            }
            ans.push_back(tmp->val);
            stk.pop();
            if(tmp->right!=NULL&&visited.find(tmp->right)==visited.end()) 
            {
                stk.push(tmp->right);
                visited.insert(tmp->right);
            }

        }
        return ans;
        
    }
};
