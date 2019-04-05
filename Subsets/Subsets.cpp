class Solution {
public:
    void helper(vector<vector<int>>& ans, vector<int> &v,int index,vector<int>&nums){
        int len=nums.size();
        if(index==len){
            return;
        }
        for(int i=index;i<nums.size();++i){
            v.push_back(nums[i]);
            ans.push_back(v);
            helper(ans,v,i+1,nums);
            v.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> a={};
        helper(ans,a,0,nums);
        ans.push_back({});
        return ans;
        
    }
};
