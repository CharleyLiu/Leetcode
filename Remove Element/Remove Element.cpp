class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int len=nums.size();
        if(len==0)return 0;
        int j=0;
        for(int i=0;i<len;i++)
        {
            if(nums[i]!=val)
            {
                nums[j]=nums[i];
                j++;
            }
        }
        return j;
        
    }
};
