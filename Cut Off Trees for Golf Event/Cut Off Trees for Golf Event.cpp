class Solution {
public:
    class comp{
        public:
        bool operator()(const vector<int>& lhs, const vector<int>& rhs) const
        {
            return lhs[0]>rhs[0];
        }
    };
    class myHash{
        public:
        size_t operator()(const pair<int,int>& pr) const
        {
            return static_cast<size_t>(pr.first*7+pr.second);
        }
    };
    int findPath(vector<vector<int>>& forest, int& ori_r,int& ori_c,int& r,int& c)
    {
        int height=forest.size();
        int width=forest[0].size();
        vector<vector<int>> visited(height,vector<int>(width,0));
        queue<pair<int,int>> q;
        visited[ori_r][ori_c]=1;
        q.push(make_pair(ori_r,ori_c));
        int lastcount=1;
        int ans=0;
        int count=0;
        while(!q.empty())
        {
            for(int i=0;i<lastcount;++i)
            {
                int cr=q.front().first;
                int cc=q.front().second;
                q.pop();
                if(cr==r&&cc==c)
                {
                    return ans;
                }
                if(cr-1>=0&&forest[cr-1][cc]>0&&visited[cr-1][cc]==0)
                {
                    q.push(make_pair(cr-1,cc));
                    visited[cr-1][cc]=1;
                    ++count;
                }
                if(cr+1<height&&forest[cr+1][cc]>0&&visited[cr+1][cc]==0)
                {
                    q.push(make_pair(cr+1,cc));
                    visited[cr+1][cc]=1;
                    ++count;
                }
                if(cc-1>=0&&forest[cr][cc-1]>0&&visited[cr][cc-1]==0)
                {
                    q.push(make_pair(cr,cc-1));
                    visited[cr][cc-1]=1;
                    ++count;
                }
                if(cc+1<width&&forest[cr][cc+1]>0&&visited[cr][cc+1]==0)
                {
                    q.push(make_pair(cr,cc+1));
                    visited[cr][cc+1]=1;
                    ++count;
                }
            }
            lastcount=count;
            count=0;
            ++ans;
        }
        return -1;
    }
    int cutOffTree(vector<vector<int>>& forest) {
        priority_queue<vector<int>, vector<vector<int>>,comp> pq;
        int height=forest.size();
        int width=forest[0].size();
        for(int i=0;i<height;++i)
        {
            for(int j=0;j<width;++j)
            {
                if(forest[i][j]>1)
                {
                    pq.push({forest[i][j],i,j});
                }
            }
        }
        int ori_r=0;
        int ori_c=0;
        int ans=0;
        while(!pq.empty())
        {
            int r=pq.top()[1];
            int c=pq.top()[2];
            pq.pop();
            int step=findPath(forest, ori_r,ori_c,r,c);
            if(step==-1) return -1;
            ans+=step;
            ori_r=r;
            ori_c=c;
        }
        return ans;
    }
};
