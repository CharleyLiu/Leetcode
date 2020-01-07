class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int ans=0;
        if(grid.empty()||grid[0].empty()) return 0;
        int h=grid.size();
        int w=grid[0].size();
        while(true){
            bool turn=false;
            bool fresh=false;
            for(int i=0;i<h;++i){
                for(int j=0;j<w;++j){
                    if(grid[i][j]==0) continue;
                    else if(grid[i][j]==1){
                        if((i>0&&grid[i-1][j]==2)||(j>0&&grid[i][j-1]==2)||(i<h-1&&grid[i+1][j]>=2)||(j<w-1&&grid[i][j+1]>=2)){
                            turn=true;
                            grid[i][j]=3;
                        }
                        fresh=true;
                    }
                    else if(grid[i][j]==3) grid[i][j]=2;
                }
            }
            ++ans;
            if(!fresh) return ans-1;
            if(!turn) return -1;

        }
    }
};
