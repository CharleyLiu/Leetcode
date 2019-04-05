class Solution {
public:
    void helper(vector<vector<int>>& ans, vector<int>& v,int start,int index,int n){
        if(index==v.size()){
            ans.push_back(v);
            return;
        }
        for(int i=start;i<=n;++i){
            v[index]=i;
            helper(ans,v,i+1,index+1,n);
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> a(k);
        helper(ans,a,1,0,n);
            return ans;
    }
};
