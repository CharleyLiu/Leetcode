class Solution {
public:
    int uniquePaths(int m, int n) {
        int** dp=new int*[m];
        for(int i=0;i<m;++i) dp[i]=new int[n];
        for(int i=0;i<n;++i) dp[0][i]=1;
        for(int i=1;i<m;++i)
        {
            for(int j=0;j<n;++j)
            {
                if(j==0) dp[i][j]=dp[i-1][j];
                else dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        int ans=dp[m-1][n-1];
        for(int i=0;i<m;++i) delete[] dp[i];
        delete[] dp;
        return ans;
    }
};
