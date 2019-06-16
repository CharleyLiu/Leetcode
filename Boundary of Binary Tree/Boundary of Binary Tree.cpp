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
private:
    void search(TreeNode* node,vector<int>& left, vector<int>& leaves,vector<int>& right,int flag)
    {
        if(node->left==NULL && node->right==NULL)
        {
            if(flag==1)
            {
                right.push_back(node->val);
                return;
            }
            leaves.push_back(node->val);
            return;
        }
        else
        {
            if(flag==-1)
            {
                left.push_back(node->val);
                if(node->left!=NULL)
                {
                    search(node->left,left,leaves,right,-1);
                    if(node->right!=NULL) search(node->right,left,leaves,right,0);
                }
                else
                {
                    search(node->right,left,leaves,right,-1);
                }

            }
            else if(flag==1)
            {

                if(node->right!=NULL)
                {
                    if(node->left!=NULL) search(node->left,left,leaves,right,0);
                    search(node->right,left,leaves,right,1);
                }
                else search(node->left,left,leaves,right,1);
                right.push_back(node->val);
            }
            else
            {
                if(node->left!=NULL) search(node->left,left,leaves,right,0);
                if(node->right!=NULL) search(node->right,left,leaves,right,0);
            }

        }
        
    }
public:
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        if(root==NULL) return {};
        vector<int> left={root->val};
        vector<int> right={};
        vector<int> leaves={};
        if(root->left!=NULL) search(root->left,left,leaves,right,-1);
        if(root->right!=NULL) search(root->right,left,leaves,right,1);
        left.insert(left.end(),leaves.begin(),leaves.end());
        left.insert(left.end(),right.begin(),right.end());
        return left;
        
    }
};
