class Solution {
public:
    int search(vector<int>& nums, int target) {
        int beg=0;
        int end=nums.size()-1;
        int mid;
        while(beg<=end){
            mid=(beg+end)/2;
            if(target==nums[mid]) return mid;
            if(target==nums[beg]) return beg;
            if(target==nums[end]) return end;
            if(nums[mid]>nums[beg]){
                if(target>nums[beg]&&target<nums[mid]){
                    end=mid-1;
                }
                else beg=mid+1;
            }
            else if(nums[mid]<nums[end]){
                if(target>nums[mid]&&target<nums[end]) beg=mid+1;
                else end=mid-1;
            }
            else return -1;
        }
        return -1;
    }
};
