class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        if(nums.empty()) return 0;
        vector<pair<int,int>> dp;
        int ansl=0;
        int count=1;
        dp.push_back({1,1});
        for(int i=1;i<nums.size();++i)
        {
            int maxl=0;
            int maxcount=1;
            for(int j=i-1;j>=0;--j){
                if(nums[j]<nums[i]){
                    if(maxl<dp[j].first){
                        maxl=dp[j].first;
                        maxcount=dp[j].second;
                    }
                    else if(maxl==dp[j].first){
                        maxcount+=dp[j].second;
                    }
                }

            }
            dp.push_back({maxl+1,maxcount});
        }
        int maxl=0;
        int maxc=0;
        for(int i=dp.size()-1;i>=0;--i){
            if(dp[i].first>maxl){
                maxl=dp[i].first;
                maxc=dp[i].second;
            }
            else if(dp[i].first==maxl){
                maxc+=dp[i].second;
            }
        }
        return maxc;
        
        
    }
};
