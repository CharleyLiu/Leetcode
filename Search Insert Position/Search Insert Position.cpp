class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int lo=0,hi=nums.size()-1,mid;
        while(lo<=hi)
        {
            mid=(lo+hi)/2;
            if(nums[mid]==target) return mid;
            if(nums[mid]<target)
            {
                lo=mid+1;
            }
            else hi=mid-1;
            
        }
        return hi+1;
    }
};
