class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> a;
        map<int, int> hashmap;
        for (int i=0;i<nums.size();i++)
        {
            int number=target-nums[i];
            map<int,int>::iterator it=hashmap.find(number);
            if(it!=hashmap.end()&&it->second!=i)
            {
                a.push_back(hashmap[number]);
                a.push_back(i);
                return a;
            }
            hashmap[nums[i]]=i;
        }

    }
};
