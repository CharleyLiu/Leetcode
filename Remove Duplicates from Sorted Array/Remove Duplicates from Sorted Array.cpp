class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len=nums.size();
        if(len==0) return 0;
        if(len==1) return 1;
        int j=0;
        int p=nums[0];
        for(int i=1;i<len;i++)
        {
            if(nums[i]==p) continue;
            else
            {
                j++;
                p=nums[j]=nums[i];
            }
        }
        return j+1;
        
    }
};
