class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int height=grid.size();
        int width=grid[0].size();
        int** dp=new int*[height];
        for(int i=0;i<height;++i) dp[i]=new int[width];
        dp[0][0]=grid[0][0];
        for(int i=1;i<width;++i) dp[0][i]=dp[0][i-1]+grid[0][i];
        for(int i=1;i<height;++i)
        {
            for(int j=0;j<width;++j)
            {
                if(j==0) dp[i][j]=dp[i-1][j]+grid[i][j];
                else dp[i][j]=min(dp[i-1][j],dp[i][j-1])+grid[i][j];
            }
        }
        int ans=dp[height-1][width-1];
        for(int i=0;i<height;++i) delete[] dp[i];
        delete[] dp;
        return ans;
    }
};
