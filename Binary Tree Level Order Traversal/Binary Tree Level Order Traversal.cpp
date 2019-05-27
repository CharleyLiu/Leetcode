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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q={};
        vector<vector<int>> ans={};
        if(root==NULL) return ans;
        q.push(root);
        int count=1;
        int nextcount=0;
        while(!q.empty())
        {
            vector<int> levelval={};
            for(int i=0;i<count;++i)
            {
                TreeNode* cur=q.front();
                q.pop();
                levelval.push_back(cur->val);
                if(cur->left!=NULL){
                    q.push(cur->left);
                    ++nextcount;
                }
                if(cur->right!=NULL){
                    q.push(cur->right);
                    ++nextcount;
                }
            }
            ans.push_back(levelval);
            count=nextcount;
            nextcount=0;
        }
        return ans;
        
    }
};
