class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> mp;
        int len=strs.size();
        for(int i=0;i<len;++i)
        {
            int slen=strs[i].length();
            map<char, int> count;
            for(int k=0;k<26;++k) count['a'+k]=0;
            for(int j=0;j<slen;++j)
            {
                ++count[strs[i][j]];
            }
            string s="";
            for(int k=0;k<26;++k)
            {
                s=s+to_string(count['a'+k])+'#';
            }
            mp[s].push_back(strs[i]);
        }
        map<string,vector<string>>::iterator it=mp.begin();
        vector<vector<string>> ans;
        while(it!=mp.end())
        {
            ans.push_back(it->second);
            ++it;
        }
        return ans;
        
    }
};
