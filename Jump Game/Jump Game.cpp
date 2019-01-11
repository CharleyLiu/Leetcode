class Solution {
public:
    bool canJump(vector<int>& nums) {
        int i=0;
        int index=0;
        int t=0;
        int len=nums.size()-1;
        while(1)
        {
            if(i+nums[i]>=len) return true;
            if(nums[i]==0) return false;
            for(int j=1;j<=nums[i];++j)
            {
                if(i+j+nums[i+j]>=t) {index=i+j;t=i+j+nums[i+j];}
            }
            i=index;
        }
        
    }
};
