class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int height=obstacleGrid.size();
        int width=obstacleGrid[0].size();
        int** dp=new int*[height];
        for(int i=0;i<height;++i) dp[i]=new int[width];
        if(obstacleGrid[0][0]==1) dp[0][0]=0;
        else dp[0][0]=1;
        for(int i=1;i<width;++i)
        {
            if(obstacleGrid[0][i]==1) dp[0][i]=0;
            else dp[0][i]=dp[0][i-1];
        }
        for(int i=1;i<height;++i)
        {
            for(int j=0;j<width;++j)
            {
                if(obstacleGrid[i][j]==1) dp[i][j]=0;
                else
                {
                    if(j==0) dp[i][j]=dp[i-1][j];
                    else dp[i][j]=dp[i-1][j]+dp[i][j-1];
                }
            }
        }
        int ans=dp[height-1][width-1];
        for(int i=0;i<height;++i) delete[] dp[i];
        delete[] dp;
        return ans;
        
    }
};
