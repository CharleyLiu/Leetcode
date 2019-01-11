class Solution {
public:
    
    void helper(vector<vector<string>>& ans, vector<string> p, int id, int n)
    {
        if(id==n)
        {
            ans.push_back(p);
            return;
        }
        for(int i=0;i<n;++i)
        {
            bool flag=true;
            for(int j=0;j<id;++j)
            {
                if(p[j][i]=='Q')
                {
                    flag=false;
                    break;
                }
                if(i-(id-j)>=0&&i-(id-j)<n&&p[j][i-(id-j)]=='Q')
                {
                    flag=false;
                    break;
                }
                if(i+(id-j)>=0&&i+(id-j)<n&&p[j][i+(id-j)]=='Q')
                {
                    flag=false;
                    break;
                }
            }
            if(flag)
            {
                string s="";
                for(int m=0;m<n;++m)
                {
                    if(m!=i) s+='.';
                    else s+='Q';
                }
                p.push_back(s);
                helper(ans,p,id+1,n);
                p.erase(p.end()-1,p.end());
            }
        }
        
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        helper(ans,vector<string>()={},0,n);
        return ans;
        
    }
};
