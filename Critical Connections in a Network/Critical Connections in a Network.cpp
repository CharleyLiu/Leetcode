class Solution {
public:
    void dfs(vector<vector<int>>& ans,vector<vector<int>>& graph,vector<int>& newindex,vector<int>& low,vector<int>& parent,int& time,int node1)
    {
        newindex[node1]=time++;
        low[node1]=newindex[node1];
        for(int& node2:graph[node1])
        {
            if(newindex[node2]==-1)
            {
                parent[node2]=node1;
                dfs(ans,graph,newindex,low,parent,time,node2);
                low[node1]=min(low[node1],low[node2]);
                if(low[node2]>newindex[node1])
                {
                    if(node1<node2) ans.push_back({node1,node2});
                    else ans.push_back({node2,node1});
                }
                
            }
            else if(parent[node1]!=node2){
                low[node1]=min(low[node1],newindex[node2]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> ans;
        vector<vector<int>> graph(n,vector<int>());
        vector<int> newindex(n,-1);
        vector<int> low(n,-1);
        vector<int> parent(n,-1);
        int time=0;
        for(auto& edge:connections)
        {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        dfs(ans,graph,newindex,low,parent,time,0);
        return ans;
        
    }
};
