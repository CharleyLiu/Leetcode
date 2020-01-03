class Solution {
public:
    bool search(vector<int>& nums,vector<int>& bucket, int index,int& target){
        if(index==nums.size()) return true;
        for(int& n:bucket){
            if(n+nums[index]<=target){
                n+=nums[index];
                bool f=search(nums,bucket,index+1,target);
                if(f) return true;
                n-=nums[index];
            }
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum=0;
        for(auto& n:nums) sum+=n;
        if(sum%k!=0) return false;
        int target=sum/k;
        sort(nums.begin(),nums.end(),std::greater<int>());
        vector<int> bucket(k,0);
        return search(nums,bucket,0,target);
        
    }
};
