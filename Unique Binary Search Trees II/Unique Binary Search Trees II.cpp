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
    vector<TreeNode*> generateTree(int start,int end)
    {
        vector<TreeNode*> result={};
        if(end<start) return {NULL};
        if(end==start){
            TreeNode* t=new TreeNode(start);
            result.push_back(t);
            return result;
        }
        for(int i=start;i<=end;++i)
        {
            vector<TreeNode*> lefttree=generateTree(start,i-1);
            vector<TreeNode*> righttree=generateTree(i+1,end);
            for(auto& ltmp:lefttree)
            {
                for(auto& rtmp:righttree)
                {
                    TreeNode* midnode=new TreeNode(i);
                    midnode->left=ltmp;
                    midnode->right=rtmp;
                    result.push_back(midnode);
                }
            }
        }
        return result;
    }

public:
    vector<TreeNode*> generateTrees(int n) {
        if(n==0) return {};
        return generateTree(1,n);
    }
};
