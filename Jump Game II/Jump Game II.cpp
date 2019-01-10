class Solution {
public:
    int jump(vector<int>& nums) {
        int i=0;
        int len=nums.size()-1;
        int count=0;
        while(i<len)
        {
            int index=0;
            int maxlen=0;
            if (i + nums[i] >= len) return count + 1;
            for(int j=1;j<=nums[i];++j)
            {
                int step=i+j+nums[i+j];
                if(step>=len)
                {
                    index=i+j;
                    break;
                }
                else
                {
                    if(step>=maxlen)
                    {
                        maxlen=step;
                        index=i+j;
                    }
                }
            }
            i=index;
            ++count;
        }
        return count;
    }
};
