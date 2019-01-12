class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans;
        vector<int> line;
        line.assign(n,0);
        ans.assign(n,line);
        int limit=0;
        int row=0;
        int col=0;
        int i=1;
        int sq=n*n+1;
        while(1)
        {
            if(i==sq) break;
            for(;col<n-limit;++col)
            {
                ans[row][col]=i;
                ++i;
            }
            --col;
            ++row;
            if(i==sq) break;
            for(;row<n-limit;++row)
            {
                ans[row][col]=i;
                ++i;
            }
            --row;
            --col;
            if(i==sq) break;
            for(;col>=limit;--col)
            {
                ans[row][col]=i;
                ++i;
            }
            ++col;
            --row;
            if(i==sq) break;
            for(;row>limit;--row)
            {
                ans[row][col]=i;
                ++i;
            }
            ++col;
            ++row;
            ++limit;
        }
        return ans;
        
    }
};
