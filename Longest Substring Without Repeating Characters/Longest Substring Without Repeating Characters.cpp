class Solution {
public://ascii for a is 97.
    int lengthOfLongestSubstring(string s) {
        if(s.length()==0) return 0;
        int len=1;
        int beg=0;
        int a[128];
        for (int i=0;i<128;i++) a[i]=-1;
        int i;
        a[s[0]]=0;
        for(i=1;i<s.length();i++)
        {
            if(a[s[i]]!=-1)
            {
                int number=i-beg;
                len=(number>=len)?number:len;
                for(int j =beg;j<a[s[i]];j++)
                {
                    a[s[j]]=-1;
                }
                beg=a[s[i]]+1;
                a[s[i]]=-1;
            }
            a[s[i]]=i;
        }
        int number=i-beg;
        len=(number>=len)?number:len;
        return len;
    }
};
