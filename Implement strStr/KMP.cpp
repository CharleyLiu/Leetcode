class Solution {
public:
    int strStr(string haystack, string needle) {
        int nlen=needle.length();
        if(nlen==0) return 0;
        int hlen=haystack.length();
        if(hlen<nlen) return -1;
        int* next=new int[nlen];
        next[0]=-1;
        int k=-1;
        for(int i=1;i<nlen;i++)
        {
            while(k>-1&&needle[i]!=needle[k+1])
            {
                k=next[k];
            }
            if(needle[i]==needle[k+1])
            {
                k++;
            }
            next[i]=k;
        }
        int j=-1;
        for(int i=0;i<hlen;i++)
        {
            while(i<hlen&&haystack[i]==needle[j+1])
            {
                if(j+2==nlen) return i-j-1; 
                i++;
                j++;
            }
            while(j>-1&&i<hlen&&haystack[i]!=needle[j+1])
            {
                j=next[j];
            }
            if(haystack[i]==needle[j+1])
            {
                if(j+2==nlen) return i-j-1;
                else j++;
            }
        }
        return -1;
        
    }
};
