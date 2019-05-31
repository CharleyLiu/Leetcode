class Solution {
public:
    void rev1(vector<vector<char>>& grid,int r, int c)
    {
        grid[r][c]='0';
        if(r-1>=0&&grid[r-1][c]=='1') rev1(grid,r-1,c);
        if(r+1<grid.size()&&grid[r+1][c]=='1') rev1(grid,r+1,c);
        if(c-1>=0&&grid[r][c-1]=='1') rev1(grid,r,c-1);
        if(c+1<grid[0].size()&&grid[r][c+1]=='1') rev1(grid,r,c+1);

    }
    int numIslands(vector<vector<char>>& grid) {
        int height=grid.size();
        if(height==0) return 0;
        int width=grid[0].size();
        if(width==0) return 0;
        int count=0;
        for(int i=0;i<height;++i)
        {
            for(int j=0;j<width;++j)
            {
                if(grid[i][j]=='1')
                {
                    ++count;
                    rev1(grid,i,j);
                }
            }
        }
        return count;
        
    }
};
