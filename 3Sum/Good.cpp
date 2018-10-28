class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        int len=nums.size();
        int sum;
        for(int i=0;i<len;i++)
        {
            int t=-nums[i];
            int beg=i+1;
            int end=len-1;
            while(beg<end)
            {
                sum=nums[beg]+nums[end];
                if(sum>t){end--;continue;}
                if(sum<t){beg++;continue;}
                if(sum==t)
                {
                    vector<int> temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[beg]);
                    temp.push_back(nums[end]);
                    ans.push_back(temp);
                    beg++;
                    end--;
                    while(beg<end&&nums[beg]==temp[1]) beg++;
                    while(beg<end&&nums[end]==temp[2]) end--;
                }
            }
            while(i+1<len&&nums[i+1]==nums[i]) i++;
        }
        return ans; 
    }
};
