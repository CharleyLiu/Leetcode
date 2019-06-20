class Solution {

public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict;
        for(string& word:wordDict)
        {
            dict.insert(word);
        }
        int slen=s.length();
        bool* dp=new bool[slen+1];
        for(int i=0;i<=slen;++i) dp[i]=false;
        dp[0]=true;
        for(int i=1;i<=slen;++i)
        {
            for(int j=i-1;j>=0;--j)
            {
                if(dp[j]&&dict.find(s.substr(j,i-j))!=dict.end())
                {
                    dp[i]=true;
                    break;      
                }
            }
        }
        return dp[slen];
        
        
    }
};
