class Solution {
public:
    int shortestDistance(vector<vector<int>>& maze, vector<int> start, vector<int>& destination) {
        queue<pair<int,int>> q;
        int height=maze.size();
        int width=maze[0].size();
        vector<vector<int>> dis(height,vector<int>(width,INT_MAX));
        dis[start[0]][start[1]]=0;
        q.push(make_pair(start[0],start[1]));
        int r,c;
        int d=1;
        int tmp;
        while(!q.empty())
        {
            r=q.front().first;
            c=q.front().second;
            q.pop();
            while(r-d>=0&&maze[r-d][c]==0) ++d;
            if(d!=1)
            {
                tmp=dis[r][c]+d-1;
                if(dis[r-d+1][c]>tmp)
                {
                    dis[r-d+1][c]=tmp;
                    q.push(make_pair(r-d+1,c));
                }
                d=1;
            }
            while(r+d<height&&maze[r+d][c]==0)++d;
            if(d!=1)
            {
                tmp=dis[r][c]+d-1;
                if(dis[r+d-1][c]>tmp)
                {
                    dis[r+d-1][c]=tmp;
                    q.push(make_pair(r+d-1,c));
                }
                d=1;
            }
            while(c-d>=0&&maze[r][c-d]==0)++d;
            if(d!=1)
            {
                tmp=dis[r][c]+d-1;
                if(dis[r][c-d+1]>tmp)
                {
                    dis[r][c-d+1]=tmp;
                    q.push(make_pair(r,c-d+1));
                }
                d=1;
            }
            while(c+d<width&&maze[r][c+d]==0)++d;
            if(d!=1)
            {
                tmp=dis[r][c]+d-1;
                if(dis[r][c+d-1]>tmp)
                {
                    dis[r][c+d-1]=tmp;
                    q.push(make_pair(r,c+d-1));
                }
                d=1;
            }
        }
        if(dis[destination[0]][destination[1]]==INT_MAX) return -1;
        else return dis[destination[0]][destination[1]];
        
    }
};
