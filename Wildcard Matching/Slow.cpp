class Solution {
public:
    bool isMatch(string s, string p) {
        if(s.length()==0)
        {
            if(p.length()==0) return true;
            else
            {
                bool flag=true;
                for(int i=0;i<p.length();++i)
                {
                    if(p[i]!='*')
                    {
                        flag=false;break;
                    }
                }
                return flag;
            }
        }
        else if(p.length()==0) return false;
        bool** dp=new bool*[s.length()+1];
        for(int i=0;i<s.length()+1;++i)
        {
            dp[i]=new bool[p.length()+1];
            for(int j=0;j<p.length()+1;++j)
                dp[i][j]=false;
        }
        dp[0][0]=true;
        int temp=-1;
        for (int j = 0; j < p.length(); ++j)
        {
            if (p[j] == '*') temp = j;
            else
            {
                break;
            }
        }
        for (int j = 0; j <= temp+1; ++j)
        {
            dp[0][j] = true;
        }

        for(int i=1;i<s.length()+1;++i)
        {
            for(int j=1;j<p.length()+1;++j)
            {
                if(s[i-1]==p[j-1]&&p[j-1]!='*'&&p[j-1]!='?')
                {
                    dp[i][j]=dp[i-1][j-1];
                }
                else if(p[j-1]=='?')
                {
                    dp[i][j]=dp[i-1][j-1];
                }
                else if(p[j-1]=='*')
                {
                    dp[i][j]=dp[i-1][j-1]||dp[i-1][j]||dp[i][j-1];
                }
            }
        }
        return dp[s.length()][p.length()];
        
        
        
    }
};
