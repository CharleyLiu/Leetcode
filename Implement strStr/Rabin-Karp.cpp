class Solution {
public:
    int strStr(string haystack, string needle) {
        int nlen=needle.length();
        if(nlen==0) return 0;
        int hlen=haystack.length();
        if(hlen<nlen) return -1;
        int M=26;
        int target=0;
        int hval=0;
        int mod=997;
        for(int i=0;i<nlen;i++)
        {
            target=target*M+needle[i]-'a';
            target=target%mod;
            hval=hval*M+haystack[i]-'a';
            hval=hval%mod;
        }
        for(int i=nlen;i<hlen;i++)
        {
            if(target==hval)
            {
                int f=true;
                for(int k=i-nlen;k<i;k++) 
                {
                    if(haystack[k]!=needle[k-i+nlen]) {f=false; break;}
                }
                if(f) return i-nlen;
            }
            int temp=1;
            for(int k=0;k<nlen-1;k++) temp=(temp*M)%mod;
            hval=hval-(haystack[i-nlen]-'a')*temp;
            hval=hval*M+haystack[i]-'a';
            hval=hval%mod;
            if(hval<0)hval+=mod;
        }
        if(target==hval)
            {
                int f=true;
                for(int k=hlen-nlen;k<hlen;k++) 
                {
                    if(haystack[k]!=needle[k-hlen+nlen]) {f=false; break;}
                }
                if(f) return hlen-nlen;
            }
        return -1;
        
        
    }
};
