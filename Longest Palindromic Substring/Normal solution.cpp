class Solution {
public:
    string longestPalindrome(string s) {
        string re;
        int len=s.length();
        re.reserve(len);
        int ans=1;
        int beg=0;
        for(int i=0;i<len;i++) re[i]=s[len-i-1];
        for(int i=0;i<len;i++)
        {
            for(int j=0;j<len;j++)
            {
                if(s[i]==re[j])
                {
                    int z=j;
                    int ii=i;
                    int tlen=0;
                    while(re[z]==s[ii])
                    {
                        if(z==len-1||ii==len-1) {tlen++;ii++;z++;break;}
                        z++;
                        ii++;
                        tlen++;
                    }
                    if((tlen>=ans)&&(len-z==ii-tlen)){ans=tlen;beg=i;}
                }
            }
            if(len-i-1<=ans) break;
        }
        return s.substr(beg,ans);
        
        
    }
};
