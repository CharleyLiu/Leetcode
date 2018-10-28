class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int reans=nums[0]+nums[1]+nums[2];
        int ans=abs(reans-target);
        int len=nums.size();
        for(int i=0;i<len;i++)
        {
            int t =target-nums[i];
            int beg=i+1;
            int end=len-1;
            int sum;
            int diff;
            while(beg<end)
            {
                sum=nums[beg]+nums[end];
                diff=abs(t-sum);
                if(ans>diff)
                {
                    ans=diff;
                    reans=sum+nums[i];
                }
                if(sum>=t) end--;
                if(sum<t) beg++;
            }
            while(i+1<len&&nums[i+1]==nums[i]) i++;
        }
        return reans;
        
    }
};
