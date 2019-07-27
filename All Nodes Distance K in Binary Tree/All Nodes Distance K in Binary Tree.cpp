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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        unordered_map<TreeNode*, TreeNode*> parents;
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* tmp;
        while(true)
        {
            tmp=q.front();
            if(tmp==target) break;
            q.pop();
            if(tmp->left!=NULL)
            {
                parents[tmp->left]=tmp;
                q.push(tmp->left);
            }
            if(tmp->right!=NULL)
            {
                parents[tmp->right]=tmp;
                q.push(tmp->right);
            }
        }
        int lvlnum=0;
        int last=1;
        int count=0;
        q={};
        q.push(tmp);
        vector<int> ans={};
        unordered_set<TreeNode*> visited={tmp};
        while(!q.empty())
        {
            if(lvlnum==K)
            {
                for(int i=0;i<last;++i)
                {
                    ans.push_back(q.front()->val);
                    q.pop();
                }
                return ans;
            }
            else
            {
                for(int i=0;i<last;++i)
                {
                    tmp=q.front();
                    q.pop();
                    if(tmp->left!=NULL&&visited.find(tmp->left)==visited.end())
                    {
                        q.push(tmp->left);
                        visited.insert(tmp->left);
                        ++count;
                    }
                    if(tmp->right!=NULL&&visited.find(tmp->right)==visited.end())
                    {
                        q.push(tmp->right);
                        visited.insert(tmp->right);
                        ++count;
                    }
                    if(parents.find(tmp)!=parents.end()&&visited.find(parents[tmp])==visited.end())
                    {
                        q.push(parents[tmp]);
                        visited.insert(parents[tmp]);
                        ++count;
                    }
                }
                last=count;
                count=0;
                ++lvlnum;
            }
        }
        return ans;
         
    }
};
