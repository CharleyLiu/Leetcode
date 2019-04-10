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
    TreeNode* generateTree(vector<int>& nums,int start,int end)
    {
        if(end<start) return NULL;
        int mid=(start+end)/2;
        TreeNode* root=new TreeNode(nums[mid]);
        root->left=generateTree(nums,start,mid-1);
        root->right=generateTree(nums,mid+1,end);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return generateTree(nums,0,nums.size()-1);
        
    }
};
