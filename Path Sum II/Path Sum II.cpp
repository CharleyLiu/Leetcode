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
    void sumup(vector<vector<int>>& ans, vector<int>& path, TreeNode* root,int cursum){
        if(root->left==NULL&&root->right==NULL){
            if(cursum==root->val) {path.push_back(root->val);ans.push_back(path);path.pop_back();}
            else return;
        }
        path.push_back(root->val);
        if(root->left!=NULL){
            sumup(ans,path,root->left,cursum-root->val);
        }
        if(root->right!=NULL) sumup(ans,path,root->right,cursum-root->val);
        path.pop_back();
        
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> ans={};
        vector<int> path={};
        if(root==NULL) return ans;
        sumup(ans,path,root,sum);
        return ans;
        
    }
};
