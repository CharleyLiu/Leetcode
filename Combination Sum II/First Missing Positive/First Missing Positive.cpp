class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int len=nums.size();
        bool* a =new bool[len];
        for(int i=0;i<len;++i) a[i]=true;
        for(int i=0;i<len;++i)
        {
            if(nums[i]>0&&nums[i]<=len)
            {
                a[nums[i]-1]=false;
            }
        }
        int ans=len+1;
        for(int i=0;i<len;++i)
        {
            if(a[i])
            {
                ans=i+1;
                break;
            }
        }
        delete[] a;
        return ans;
        
        
    }
};
