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
    TreeNode* findprev(TreeNode* root)
    {
        while(root->right!=NULL) root=root->right;
        return root;
        
    }
    void flatten(TreeNode* root) {
        TreeNode* it=root;
        TreeNode* prev=NULL;
        while(it!=NULL)
        {
            if(it->left==NULL) {it=it->right;continue;}
            if(it->right!=NULL)
            {
                prev=findprev(it->left);
                prev->right=it->right;
                
            }
            it->right=it->left;
            it->left=NULL;
            it=it->right;

        }

        
    }
};
