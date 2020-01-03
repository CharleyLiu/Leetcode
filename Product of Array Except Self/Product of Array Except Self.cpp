class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        if(nums.empty()) return {};
        if(nums.size()==1) return {1};
        vector<int> ans={1};
        int len=nums.size();
        for(int i=0;i<len-1;++i){
            ans.push_back(ans.back()*nums[i]);
        }
        int mul=nums.back();
        for(int i=len-2;i>=0;--i){
            ans[i]*=mul;
            mul*=nums[i];
        }
        return ans;
        
    }
};
