class Solution {
public:
    void helper(vector<vector<int>>& ans, vector<int>& v,int start,int k,int n){
        if(v.size()==k){
            ans.push_back(v);
            return;
        }
        for(int i=start;i<=n;++i){
            //swap(n[0],n[i]);
            v.push_back(i);
            helper(ans,v,i+1,k,n);
            v.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> v;
        helper(ans,v,1,k,n);
            return ans;
    }
};
