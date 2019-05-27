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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans={};
        if(root==NULL) return ans;
        queue<TreeNode*> q={};
        q.push(root);
        int count=1;
        int nextcount=0;
        bool leftToRight=true;
        TreeNode* cur=NULL;
        while(!q.empty()){
            vector<int> level={};
            for(int i=0;i<count;++i){
                cur=q.front();
                q.pop();
                if(leftToRight) level.push_back(cur->val);
                else level.insert(level.begin(),cur->val);
                if(cur->left!=NULL){
                    q.push(cur->left);
                    ++nextcount;
                }
                if(cur->right!=NULL){
                    q.push(cur->right);
                    ++nextcount;
                }
            }
            leftToRight=!leftToRight;
            ans.push_back(level);
            count=nextcount;
            nextcount=0;
        }
        return ans;
        
    }
};
