class Solution {
public:
    void nextPermutation(vector<int>& nums) {//13542 14235
        int len=nums.size();
        int i=len-1;
        int t=0;
        for(i=len-1;i>0;--i)
        {
            if(nums[i-1]<nums[i])
                break;
        }
        if(i!=0)t=i-1;
        for(int j=len-1;j>=t;--j)
        {
            if(nums[j]>nums[t])
            {
                int temp=nums[t];
                nums[t]=nums[j];
                nums[j]=temp;
                break;
            }
        }
        reverse(nums.begin()+i,nums.end());
    }
};
