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
    vector<int> postorderTraversal(TreeNode* root) {
        if(!root) return {};
        stack<TreeNode*> stk;
        TreeNode* cur=root;
        vector<int> ans;
        TreeNode* last=NULL;
        while(cur||!stk.empty())
        {
            if(cur){
                stk.push(cur);
                cur=cur->left;
            }
            else{
                TreeNode* node=stk.top();
                if(node->right&&last!=node->right){
                    cur=node->right;
            }
            else{
                    ans.push_back(node->val);
                    last=node;
                    stk.pop();
                }
            
            }
        }
        return ans;
    }
};
