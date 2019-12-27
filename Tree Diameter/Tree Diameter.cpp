class Solution {
public:
    int dfs(unordered_map<int,vector<int>>& tree,unordered_set<int>&seen,int& ans,int node){
        int depth=-1;
        for(int& next:tree[node]){
            if(seen.find(next)!=seen.end()) continue;
            else{
                seen.insert(next);
                int tmpdep=dfs(tree,seen,ans,next);
                ans=max(ans,tmpdep+depth+2);
                depth=max(depth,tmpdep);
            }
        }
        return depth+1;
    }
    int treeDiameter(vector<vector<int>>& edges) {
        unordered_map<int,vector<int>> tree;
        for(vector<int>& e:edges){
            tree[e[0]].push_back(e[1]);
            tree[e[1]].push_back(e[0]);
        }
        unordered_set<int> seen;
        seen.insert(0);
        int ans=0;
        dfs(tree,seen,ans,0);
        return ans;
        
    }
};
