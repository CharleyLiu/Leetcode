class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if(grid.empty()||grid[0].empty()) return 0;
        int h=grid.size();
        int w=grid[0].size();
        int maxa=0;
        vector<bool> unseen(h*w,true);
        for(int i=0;i<h;++i)
        {
            for(int j=0;j<w;++j)
            {
                int index=i*w+j;
                if(unseen[index]&&grid[i][j]==1){
                    unseen[index]=false;
                    stack<pair<int,int>> stk={};
                    stk.push({i,j});
                    int area=0;
                    while(!stk.empty()){
                        int r=stk.top().first;
                        int c=stk.top().second;
                        stk.pop();
                        ++area;
                        if(r>0&&grid[r-1][c]==1&&unseen[r*w-w+c]){unseen[r*w-w+c]=false;stk.push({r-1,c});} 
                        if(r<h-1&&grid[r+1][c]==1&&unseen[r*w+w+c]){unseen[r*w+w+c]=false;stk.push({r+1,c});}                         
                        if(c>0&&grid[r][c-1]==1&&unseen[r*w+c-1]){unseen[r*w+c-1]=false;stk.push({r,c-1});}                         
                        if(c<w-1&&grid[r][c+1]==1&&unseen[r*w+1+c]){unseen[r*w+1+c]=false;stk.push({r,c+1});} 
                    }
                    maxa=max(maxa,area);
                }
                
            }
        }
        return maxa;
        
    }
};
