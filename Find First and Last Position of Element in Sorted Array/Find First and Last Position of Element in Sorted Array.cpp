class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int len=nums.size();
        vector<int> a;
        if(len==0){a.push_back(-1);a.push_back(-1);return a;}
        if(len==1)
        {
            if(nums[0]==target)
            {
                a.push_back(0);
                a.push_back(0);
                return a;
            }
            else
            {
                a.push_back(-1);a.push_back(-1);return a;
            }
        }
        int low=0, high=nums.size()-1,mid,lmid,hmid;

        lmid=-1;
        while(low!=high)
        {
            mid =(low+high)/2;
            if(nums[mid]<target)
            {
                
                low=mid+1;
            }
            else// if(nums[mid]>=target)
            {
                high= mid;
            }
        }
        if(nums[low]==target) lmid=low;
        hmid=-1;
        low=0;
        high=nums.size()-1;
        while(low!=high)
        {
            mid =(low+high)/2;
            if(nums[mid]<=target)
            {
                low=mid+1;
            }
            else// if(nums[mid]>target)
            {

                high= mid;
            }
        }
        if(nums[low]==target){hmid=low;}
        else if(low>0&&nums[low-1]==target) {hmid=low-1; } 
        a.push_back(lmid);
        a.push_back(hmid);
        return a;
    }
};
