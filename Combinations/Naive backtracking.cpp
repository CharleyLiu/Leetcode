class Solution {
public:
    void helper(vector<vector<int>>& ans, vector<int> v, vector<int> n,int k){
        int len=n.size();
        if(v.size()==k){
            ans.push_back(v);
            return;
        }
        for(int i=0;i<len;++i){
            //swap(n[0],n[i]);
            v.push_back(n[i]);
            helper(ans,v,vector<int>(n.begin()+i+1,n.end()),k);
            v.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> arr={};
        for(int i=0;i<n;++i) arr.push_back(i+1);
        helper(ans,{},arr,k);
            return ans;
    }
};
