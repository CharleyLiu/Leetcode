class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans={{}};
        for(int i=0;i<nums.size();)
        {
            int count=0;
            while(i+count<nums.size()&&nums[i]==nums[i+count]) ++count;
            int sz=ans.size();
            for(int j=0;j<sz;++j)
            {
                vector<int> temp=ans[j];
                for(int k=0;k<count;++k)
                {
                    temp.push_back(nums[i]);
                    ans.push_back(temp);
                }
            }
            i=i+count;
        }
        return ans;
        
    }
};
