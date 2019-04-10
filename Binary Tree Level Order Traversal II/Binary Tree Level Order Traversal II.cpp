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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans={};
        queue<TreeNode*> q;
        if(root==NULL) return ans;
        int layercount=1;
        q.push(root);
        vector<int> layer={};
        while(!q.empty())
        {
            layer={};
            int nextcount=0;
            while(layercount>0)
            {
                TreeNode* tmp=q.front();
                q.pop();
                --layercount;
                layer.push_back(tmp->val);
                if(tmp->left!=NULL){
                    ++nextcount;
                    q.push(tmp->left);
                }
                if(tmp->right!=NULL){
                    ++nextcount;
                    q.push(tmp->right);
                }
            }
            ans.push_back(layer);
            layercount=nextcount;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
