class Solution {
public:
    void sortColors(vector<int>& nums) {
        int len=nums.size();
        int r=0;
        int white=0;
        int blue=0;
        for(int i=0;i<len;++i)
        {
            if(nums[i]==0)
            {
                nums[blue++]=2;
                nums[white++]=1;
                nums[r++]=0;
            }
            else if(nums[i]==1)
            {
                nums[blue++]=2;
                nums[white++]=1;
            }
            else
            {
                nums[blue++]=2;
            }
        }
        
    }
};
