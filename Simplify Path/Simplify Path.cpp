class Solution {
public:
    string simplifyPath(string path) {
        int len=path.length();
        int i=1;
        int depth=0;
        string ans="/";
        while(i<len)
        {
            int ini=i;
            while(i<len&&path[i]!='/') ++i;
            if(i==ini) {++i;continue;}
            else 
            {
                if(i-ini==1&&path[ini]=='.')
                {
                    ++i;
                }
                else if(i-ini==2&&path[ini]=='.'&&path[ini+1]=='.')
                {
                    if(depth!=0)
                    {
                        --depth;
                        int k;
                        for(k=ans.length()-2;k>=0;--k)
                        {
                            if(ans[k]=='/') break;
                        }
                        ans.erase(ans.begin()+k+1,ans.end());
                    }
                    ++i;
                }
                else
                {
                    for(int j=ini;j<i;++j)
                    {
                        ans=ans+path[j];
                    }
                    ans=ans+'/';
                    ++i;
                    ++depth;
                }
            }
        }
        if(ans.length()!=1&& *(ans.end()-1)=='/')ans.erase(ans.end()-1,ans.end());
        if( ans.length()>=2&&*(ans.end()-1)=='.'&&*(ans.end()-2)=='/') ans.erase(ans.end()-1,ans.end());
        return ans;
    }
};
