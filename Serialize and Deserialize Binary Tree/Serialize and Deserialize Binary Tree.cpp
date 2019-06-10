/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans="";
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* cur=NULL;
        while(!q.empty())
        {
            cur=q.front();
            q.pop();
            if(cur==NULL) ans+="n";
            else
            {
                ans+=to_string(cur->val);
                q.push(cur->left);
                q.push(cur->right);
            }
            ans+=",";
        }
        return ans;
        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int len=data.length();
        int beg=0;
        int end=data.find(',',0);
        TreeNode* cur=NULL;
        string str=data.substr(beg,end-beg);
        beg=end+1;
        end=data.find(',',beg);
        if(str=="n") return NULL;
        TreeNode* root=new TreeNode(atoi(str.c_str()));
        queue<TreeNode*> q;
        q.push(root);
        while(end!=string::npos)
        {
            cur=q.front();
            q.pop();
            str=data.substr(beg,end-beg);
            if(str=="n")
            {
                cur->left=NULL;
            }
            else
            {
                cur->left=new TreeNode(atoi(str.c_str()));
                q.push(cur->left);
            }
            beg=end+1;
            end=data.find(',',beg);
            str=data.substr(beg,end-beg);
            if(str=="n") cur->right=NULL;
            else
            {
                cur->right=new TreeNode(atoi(str.c_str()));
                q.push(cur->right);
            }
            beg=end+1;
            end=data.find(',',beg);
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
