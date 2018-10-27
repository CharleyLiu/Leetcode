class Solution {
public:
    bool isMatch(string s, string p) {
        int slen = s.size();
        int plen = p.size();
        bool** dp = new bool*[slen + 1];
        for (int i = 0; i < slen + 1; i++) dp[i] = new bool[plen + 1];
        //vector<vector<bool>> dp(slen + 1, vector<bool>(plen + 1, false));
        dp[0][0]=true;
        dp[0][1]=false;
        for(int i=1;i<=slen;i++) dp[i][0]=false;
        for(int j=2;j<plen+1;j++) dp[0][j]=p[j-1]=='*'&&dp[0][j-2];
        for (int i = 1; i <=slen; i++)
        {
            for (int j = 1; j<=plen ; j++)
            {
                if (p[j-1]!='*')
                {
                    dp[i][j] = dp[i-1][j-1]&&(s[i-1]==p[j-1]||p[j-1]=='.');
                    
                }
                else dp[i][j] = dp[i][j-2]||(s[i-1]==p[j-2]||p[j-2]=='.')&&dp[i-1][j];
            }
        }
        return dp[slen][plen];
    }
};
