class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size()==0) return 0;
        unordered_set<int> map;
        int maxlen=1;
        for(int i:nums)
        {
            map.insert(i);
        }
        for(int i:nums)
        {
            if(map.find(i)==map.end()) continue;
            int j=1;
            while(map.find(i-j)!=map.end())
            {
                map.erase(i-j);
                ++j;
            }
            int k=1;
            while(map.find(i+k)!=map.end())
            {
                map.erase(i+k);
                ++k;
            }
            maxlen=max(maxlen,j+k-1);
        }
        return maxlen;
        
    }
};
