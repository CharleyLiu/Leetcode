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
            swap(nums[index],nums[i]);
            helper(ans,nums,index+1);
            swap(nums[index],nums[i]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        helper(ans,nums,0);
        sort(ans.begin(),ans.end());
        ans.erase(unique(ans.begin(),ans.end()),ans.end());
        return ans;
    }
};
