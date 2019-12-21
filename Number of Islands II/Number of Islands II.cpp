class Solution {
public:
    int find(vector<int>& parent,int x){
        if(parent[x]!=x) parent[x]=find(parent,parent[x]);
        return parent[x];
    }

    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
        vector<int> parent(m*n,-1);
        vector<int> rank(m*n,0);
        vector<int> ans={};
        int count=0;
        int height=m;
        int width=n;
        for(vector<int>& pos:positions)
        {
            int index=pos[0]*n+pos[1];
            if(parent[index]>=0){ans.push_back(count);continue;}
            parent[index]=index;
            ++count;
            vector<int> tmp={};
            if(pos[0]>0&&parent[n*(pos[0]-1)+pos[1]]>=0) tmp.push_back(n*(pos[0]-1)+pos[1]);
            if(pos[0]<height-1&&parent[n*(pos[0]+1)+pos[1]]>=0) tmp.push_back(n*(pos[0]+1)+pos[1]);
            if(pos[1]>0&&parent[n*(pos[0])+pos[1]-1]>=0) tmp.push_back(n*(pos[0])+pos[1]-1);
            if(pos[1]<width-1&&parent[n*(pos[0])+pos[1]+1]>=0) tmp.push_back(n*pos[0]+pos[1]+1);

            for(int& x:tmp)
            {
                int rootx=find(parent,x);
                int rooti=find(parent,index);
                if(rootx!=rooti){
                    if(rank[rootx]>rank[rooti]) parent[rooti]=rootx;
                    else if(rank[rootx]<rank[rooti]) parent[rootx]=rooti;
                    else{
                        parent[rooti]=rootx;
                        ++rank[rootx];
                    }
                    --count;
                }
            }
            ans.push_back(count);
        }
        return ans;
    }
};
