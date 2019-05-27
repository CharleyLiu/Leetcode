class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int height=triangle.size();
        int* sum=new int[height];
        for(int i=0;i<height;++i)
        {
            sum[i]=triangle[height-1][i];
        }
        for(int i=height-2;i>=0;--i)
        {
            for(int j=0;j<=i;++j)
            {
                sum[j]=triangle[i][j]+min(sum[j],sum[j+1]);
            }
        }
        return sum[0];
    }
};
