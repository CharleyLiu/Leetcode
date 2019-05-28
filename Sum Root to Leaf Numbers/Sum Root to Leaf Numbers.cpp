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
    double sumup(TreeNode* root, double& sum)
    {
        if(root==NULL) return 0;
        double c=sumup(root->left,sum)+sumup(root->right,sum);
        if(c==0) c=1;
        sum+=c*root->val;
        return 10*c;
        
    }
    int sumNumbers(TreeNode* root) {
        double sum=0;
        if (root==NULL) return 0;
        sumup(root,sum);
        return sum;
        
    }
};
