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
    TreeNode* constructTree(vector<int>& inorder,vector<int>& postorder,int inbeg,int inend,int postbeg,int postend){
        int rootval=postorder[postend];
        TreeNode* root=new TreeNode(rootval);
        int incur=inbeg;
        while(inorder[incur]!=rootval) ++incur;
        int leftsize=incur-inbeg;
        int rightsize=inend-incur;
        if(leftsize!=0)
            root->left=constructTree(inorder,postorder,inbeg,incur-1,postbeg,postbeg+leftsize-1);
        if(rightsize!=0)
            root->right=constructTree(inorder,postorder,incur+1,inend,postbeg+leftsize,postend-1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size()==0) return NULL;
        return constructTree(inorder, postorder,0,inorder.size()-1,0,postorder.size()-1);
    }
};
