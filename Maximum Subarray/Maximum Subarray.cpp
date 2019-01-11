class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int last=nums[0];
        int max=nums[0];
        for(int i=1;i<nums.size();++i)
        {
            if(last<=0) last=nums[i];
            else last=last+nums[i];
            if(last>max)max=last;
        }
        return max;
        
    }
};
