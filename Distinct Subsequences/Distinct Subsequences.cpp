class Solution {
public:

    int numDistinct(string s, string t) {
        int slen=s.length();
        int tlen=t.length();
        double** dp=new double*[tlen+1];
        for(int i=0;i<=tlen;++i)
        {
            dp[i]=new double[slen+1];
            dp[i][0]=0;
        }
        for(int i=0;i<=slen;++i) dp[0][i]=1;
        for(int j=1;j<=slen;++j)
        {
            for(int i=1;i<=tlen;++i)
            {
                int temp=0;
                if(s[j-1]==t[i-1])
                {
                    temp=dp[i-1][j-1];
                }
                dp[i][j]=dp[i][j-1]+temp;
            }
        }
        return dp[tlen][slen];
    }
};
