class Solution {
public:
    int strStr(string haystack, string needle) {
        int nlen=needle.length();
        if(nlen==0) return 0;
        int hlen=haystack.length();
        if(hlen<nlen) return -1;
        int* goodsuff=new int[nlen];
        int* gs=new int[nlen];
        unordered_map<char,int> badend;
        unordered_map<char,int>::iterator it;
        for(int i=0;i<nlen-1;i++)
        {
            badend[needle[i]]=nlen-1-i;
        }
        goodsuff[nlen-1]=nlen;
        int b,e;
        e=nlen-1;
        b=nlen-1;
        for(int i=nlen-2;i>=0;i--)
        {
            if(i>b&&goodsuff[nlen-1-e+i]<i-b)
                goodsuff[i]=goodsuff[nlen-1-e+i];
            else
            {
                if(i<b) b=i;
                e=i;
                while(b>=0&&needle[b]==needle[nlen-1-(i-b)]) b--;
                goodsuff[i]=e-b;
            }
        }
        for(int i=0;i<nlen;i++) gs[i]=nlen;
        int j=0;
        for(int i=nlen-1;i>=0;i--)
        {
            if(goodsuff[i]==i+1)
            {
                while(j<nlen-1-i)
                {
                    if(gs[j]==nlen) gs[j]=nlen-1-i;
                    j++;
                }
            }
        }
        for(int i=0;i<nlen-1;i++)
            gs[nlen-1-goodsuff[i]]=nlen-1-i;
        int i=0;
        int t1;
        int t2;

        while(i<=hlen-nlen)
        {
            for(j=nlen-1;j>=0;j--)
            {
                if(haystack[i+j]==needle[j])
                {
                    if(j==0) return i;
                }
                else
                {
                    it=badend.find(haystack[i+j]);
                    if(it==badend.end())
                    {
                        t1=nlen;
                    }
                    else t1=it->second;
                    t1=t1-nlen+1+j;
                    t2=gs[j];
                    break;
                }
            }
            i+=(t1>t2)?t1:t2;
        }
        return -1;
    }
    
};
