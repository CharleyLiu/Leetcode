class Solution {
public:
    int kth(vector<int>& nums, int beg, int end, int k){
        int p=nums[end];
        int count=beg;
        for(int i=beg;i<=end;++i){
            if(nums[i]<p){
                swap(nums[count++],nums[i]);
            }
        }
        swap(nums[count],nums[end]);
        int top=end-count+1;
        if(top==k) return p;
        else if(top>k) return kth(nums,count+1,end,k);
        else return kth(nums,beg,count-1,k-top);
    }
    int findKthLargest(vector<int>& nums, int k) {
        return kth(nums,0,nums.size()-1,k);
        
    }
};
