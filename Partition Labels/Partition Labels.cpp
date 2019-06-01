class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> mapper(26,0);
        vector<int> ans;
        int len=S.length();
        if(len==0) return {0}; 
        for(int i=0;i<len;++i)
        {
            mapper[S[i]-'a']=i;
        }
        int count=0;
        int minsz=mapper[S[0]-'a'];
        for(int i=0;i<len;++i)
        {
            if(i==minsz)
            {
                ans.push_back(count+1);
                count=0;
                if(i==len-1)
                {
                    minsz=-1;
                    break;
                }
                minsz=mapper[S[i+1]-'a'];
                continue;
            }
            else
            {
                minsz=max(minsz,mapper[S[i]-'a']);
                ++count;
            }
        }
        if(minsz!=-1) ans.push_back(count+1);
        return ans;
        
    }
};
