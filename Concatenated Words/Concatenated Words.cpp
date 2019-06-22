class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        sort(words.begin(),words.end(),[](const string& lhs, const string& rhs){return lhs.size()<rhs.size();});
        vector<string> ans;
        int sz=words.size();
        int slen;
        unordered_set<string> wset;
        wset.insert(words[0]);
        bool dp[5000]={false};
        // for(int i=0;i<1000;++i) dp[i]=false;
        dp[0]=true;
        for(int i=1;i<sz;++i)
        {
            slen=words[i].size();
            // bool* dp=new bool[slen+1];
            // for(int j=1;j<=slen;++j) dp[j]=false;
            // dp[0]=true;
            for(int j=1;j<=slen;++j)
            {
                for(int k=j-1;k>=0;--k)
                {
                    if(dp[k]&&wset.find(words[i].substr(k,j-k))!=wset.end())
                    {
                        dp[j]=true;
                        break;
                    }
                }
            }
            if(dp[slen]) ans.push_back(words[i]);
            wset.insert(words[i]);
            for(int m=1;m<=slen;++m) dp[m]=false;
            // delete []dp;
        }
        return ans;
    }
};
