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
    bool helper(TreeNode*s, TreeNode* t)
    {        
        if(t==NULL&&s==NULL) return true;
        if(s==NULL||t==NULL) return false;
        if(t->val==s->val&&helper(s->left,t->left)&&helper(s->right,t->right))
            return true;
        return false;
    }
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(t==NULL&&s==NULL) return true;
        if(s==NULL||t==NULL) return false;
        if(helper(s,t)) return true;
        return isSubtree(s->left,t)||isSubtree(s->right,t);
    }
};
