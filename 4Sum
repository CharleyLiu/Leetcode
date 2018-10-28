class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        int len=nums.size();
        int beg;
        int end;
        int t;
        int sum;
        for(int i=0;i<len;i++)
        {
            for(int j=i+1;j<len;j++)
            {
                beg=j+1;
                end=len-1;
                t=target-nums[i]-nums[j];
                while(beg<end)
                {
                    sum=nums[beg]+nums[end];
                    if(sum>t) end--;
                    else if(sum<t) beg++;
                    else
                    {
                        vector<int> temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[j]);
                        temp.push_back(nums[beg]);
                        temp.push_back(nums[end]);
                        ans.push_back(temp);
                        beg++;
                        end--;
                        while(beg<end&&nums[beg]==temp[2])beg++;
                        while(beg<end&&nums[end]==temp[3])end--;
                    }
                }
                while(j+1<len&&nums[j+1]==nums[j])j++;
            }
            while(i+1<len&&nums[i+1]==nums[i])i++;
        }
        return ans;
    }
};
