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
    int minDepth(TreeNode* root) {
        if (root==NULL) return 0;
        queue<TreeNode*> q={};
        q.push(root);
        int level=1;
        int count=1;
        int nextcount=0;
        while(!q.empty()){
            for(int i=0;i<count;++i){
                TreeNode* cur=q.front();
                q.pop();
                if(cur->left==NULL&&cur->right==NULL) return level;
                if(cur->left!=NULL) {q.push(cur->left);++nextcount;}
                if(cur->right!=NULL) {q.push(cur->right);++nextcount;}
            }
            count=nextcount;
            nextcount=0;
            ++level;
        }
        return level;
    }
};
