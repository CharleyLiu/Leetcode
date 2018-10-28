class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        map<pair<int,int>,bool> test;
        for(int i=0;i<nums.size();i++)
        {
            bool flag=false;
            int t=-nums[i];
            map<int,int> a;
            for (int j =i+1;j<nums.size();j++)
            {
                 int com=t-nums[j];
                 map<int,int>::iterator it=a.find(com);
                 if(it!=a.end()&& it->second != j&&it->second!=i)
                 {
                     vector<int> temp;
                     temp.push_back(nums[i]);
                     temp.push_back(com);
                     temp.push_back(nums[j]);
                     ans.push_back(temp);
                     flag=true;

                 }
                a[nums[j]]=j;
                if(flag)while(j+1<nums.size()&&nums[j+1]==nums[j]) j++;

            }
            if(flag)while(i+1<nums.size()&&nums[i+1]==nums[i]) i++;
        }
        return ans;
        
    }
};
