class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int sum=0;
        int ans=INT_MAX;
        int len=0;
        for(int index=0;index<nums.size();++index)
        {
            sum+=nums[index];
            ++len;
            while(sum-nums[index-len+1]>=s)
            {
                sum-=nums[index-len+1];
                --len;
            }
            if(sum>=s) ans=min(len,ans);
        }
        if(sum<s) return 0;
        return ans;
    }
};
