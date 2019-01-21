class Solution {
public:
    string minWindow(string s, string t) {
        int map[128]={0};
        bool flag[128]={false};
        int len1=s.length();
        int len2=t.length();
        int count=len2;
        for(int i=0;i<len2;++i)
        {
            ++map[t[i]];
            flag[t[i]]=true;
        }
        int begin=-1;
        int i=0,j=0;
        int ans=INT_MAX;
        while(i<=len1&&j<len1)
        {
            if(count>0)
            {
                if(i<len1&&flag[s[i]])
                {
                    if(map[s[i]]>0) --count;
                    --map[s[i]];
                }
                ++i;
            }
            else
            {
                if(ans>i-j)
                {
                    ans=i-j;
                    begin=j;
                }
                if(flag[s[j]])
                {
                    if(map[s[j]]==0) ++count;
                    ++map[s[j]];
                }
                ++j;
            }
        }
        if(ans==INT_MAX) return "";
        return s.substr(begin,ans);
    }
};
