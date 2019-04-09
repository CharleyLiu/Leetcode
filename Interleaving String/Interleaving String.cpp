class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int len1=s1.length();
        int len2=s2.length();
        if(len1+len2!=s3.length()) return false;
        bool** dp=new bool*[len1+1];
        for(int i=0;i<=len1;++i) dp[i]=new bool[len2+1];
        dp[0][0]=true;
        for(int i=1;i<=len1;++i){
            if(dp[i-1][0]&&s1[i-1]==s3[i-1]) dp[i][0]=true;
            else dp[i][0]=false;
        }
        for(int j=1;j<=len2;++j){
            if(dp[0][j-1]&&s2[j-1]==s3[j-1]) dp[0][j]=true;
            else dp[0][j]=false;
        }
        for(int i=1;i<=len1;++i)
        {
            for(int j=1;j<=len2;++j)
            {
                dp[i][j]=(s3[i+j-1]==s1[i-1]&&dp[i-1][j])||(s3[i+j-1]==s2[j-1]&&dp[i][j-1]);
            }
        }
        return dp[len1][len2];
    }
};
