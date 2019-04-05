class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len=nums.size();
        int index=0;
        int i=0;
        while(i+2<len&&nums[i]!=nums[i+2]){
            ++i;
        }
        index=i;
        while(i<len)
        {
            if(i+2<len&&nums[i]==nums[i+2])
            {
                nums[index++]=nums[i++];
                nums[index]=nums[i++];
                while(i<len&&nums[i]==nums[index]) ++i;
                ++index;
            }
            else{
                nums[index++]=nums[i++];
            }
        }
        return index;
        
    }
};
