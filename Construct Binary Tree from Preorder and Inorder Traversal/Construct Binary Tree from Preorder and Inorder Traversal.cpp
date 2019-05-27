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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder,int prebeg,int preend,int inbeg,int inend){
        int rootval=preorder[prebeg];
        TreeNode* root=new TreeNode(rootval);
        int incur=inbeg;
        while(inorder[incur]!=rootval) ++incur;
        int leftsize=incur-inbeg;
        int rightsize=inend-incur;
        if (leftsize==0){
            root->left=NULL;
        }
        else root->left=buildTree(preorder,inorder,prebeg+1,prebeg+leftsize,inbeg,incur-1);
        if (rightsize==0) root->right=NULL;
        else root->right=buildTree(preorder,inorder,prebeg+leftsize+1,preend,incur+1,inend);
        return root;
    }  
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size()==0) return NULL;
       return buildTree(preorder,inorder,0,preorder.size()-1,0,inorder.size()-1);
    }
};
