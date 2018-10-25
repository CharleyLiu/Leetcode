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
		for (i = 1; i < s.length(); i++)
		{
			beg = (a[s[i]] >= beg) ? a[s[i]]+1: beg;
			int number = i - beg+1;
			if (len < number) len = number;
			a[s[i]] = i;
		}
        return len;
    }
};
