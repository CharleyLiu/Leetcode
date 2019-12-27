class Solution {
public:
    int findMin(vector<int>& nums) {
        int beg=0;
        int end=nums.size()-1;
        int ans=nums[0];
        while(beg<=end){
            int mid=(beg+end)/2;
            ans=min(ans,nums[mid]);
            ans=min(ans,nums[beg]);
            ans=min(ans,nums[end]);
            if(nums[mid]>nums[beg]){
                beg=mid+1;
            }
            else end=mid-1;
            //mid<beg&&mid>end
        }
        return ans;
    }
};
