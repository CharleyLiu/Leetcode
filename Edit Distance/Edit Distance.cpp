class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1=word1.length();
        int len2=word2.length();
        if(len1==0) return len2;
        if(len2==0) return len1;
        int** dp=new int*[len1];
        for(int i=0;i<len1;++i)
        {
            dp[i]=new int[len2];
        }
        if(word1[0]==word2[0]) dp[0][0]=0;
        else dp[0][0]=1;
        for(int i=1;i<len2;++i)
        {
            int temp=1;
            if(word1[0]==word2[i]) temp=0;
            dp[0][i]=min(dp[0][i-1]+1,i+temp);
        }
        for(int i=1;i<len1;++i)
        {
            int temp=1;
            if(word1[i]==word2[0]) temp=0;
            dp[i][0]=min(dp[i-1][0]+1,i+temp);
        }
        for(int i=1;i<len1;++i)
        {
            for(int j=1;j<len2;++j)
            {
                int temp1=1;
                if(word1[i]==word2[j]) temp1=0;
                dp[i][j]=min(dp[i-1][j-1]+temp1,min(dp[i-1][j]+1,dp[i][j-1]+1));
            }
        }
        int ans=dp[len1-1][len2-1];
        for(int i=0;i<len1;++i) delete[] dp[i];
        delete[] dp;
        return ans;
    }
};
