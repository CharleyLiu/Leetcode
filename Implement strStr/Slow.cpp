class Solution {
public:
    int strStr(string haystack, string needle) {
        int nlen=needle.length();
        if(nlen==0) return 0;
        int hlen=haystack.length();
        if(hlen==0) return -1;
        char c=needle[0];
        for(int i=0;i<hlen;i++)
        {
            if(haystack[i]!=c) continue;
            else
            {
                bool flag=true;
                for(int j=1;j<nlen;j++)
                {
                    if(i+j==hlen||haystack[i+j]!=needle[j]) {flag=false;break;}
                }
                if(flag)return i;
            }
        }
        return -1;
        
    }
};
