class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int beg=0;
        int end=nums.size()-1;
        int mid;
        while(beg<=end){
            mid=beg+ (end-beg)/2;
            while(nums[mid]==nums[end]&&mid!=end) ++mid; 
            if(nums[mid]==target||nums[beg]==target||nums[end]==target) return true;
            else if(nums[mid]<target){
                if(target>nums[end]&&nums[end]>=nums[mid]){
                    end=mid-1;
                }
                else{
                    beg=mid+1;
                }
            }
            else{
                if(nums[mid]>nums[end]&&nums[end]>target) beg=mid+1;
                else end=mid-1;
            }
        }
        return false;
        
    }
};
