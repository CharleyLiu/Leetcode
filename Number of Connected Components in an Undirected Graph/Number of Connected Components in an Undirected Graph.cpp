class Solution {
    vector<int> rank;
    vector<int> root;
    void init(int n){
        rank=vector<int>(n,0);
        for(int i=0;i<n;++i) root.push_back(i);
    }
public:
    int find(int node){
        if(node!=root[node]) root[node]=find(root[node]);
        return root[node];
    }
    void unionnode(int x,int y)
    {
        int rootx=find(x);
        int rooty=find(y);
        if(rootx!=rooty)
        {
            if(rank[rootx]>rank[rooty]) root[rooty]=rootx;
            else if(rank[rootx]<rank[rooty]) root[rootx]=rooty;
            else{
                root[rootx]=rooty;
                ++rank[rooty];
            }
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        init(n);
        for(vector<int>& edge:edges){
            unionnode(edge[0],edge[1]);
        }
        unordered_set<int> count;
        for(int i=0;i<n;++i){
            count.insert(find(i));
        }
        return count.size();
    }
};
