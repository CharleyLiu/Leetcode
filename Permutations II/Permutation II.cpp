class Solution {
public:
    void helper(vector<vector<int>>& ans, vector<int> nums, int index)
    {
        int len=nums.size();
        if(index==len)
        {
            ans.push_back(nums);
            return;
        }
        for(int i=index;i<len;++i)
        {
            if(i!=index&&nums[i]==nums[index]) continue;
            swap(nums[index],nums[i]);
            helper(ans,nums,index+1);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        helper(ans,nums,0);
        return ans;
    }
};
