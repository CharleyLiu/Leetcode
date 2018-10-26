class Solution {
public:
    string longestPalindrome(string s) {
        string t;
        int len = s.length();
        t.resize(len * 2 + 1);
        for (int i = 0; i < len; i++)
        {
            t[2*i]='#';
            t[2*i+1]=s[i];
        }
        t[2*len]='#';
        vector<int> p;
        p.resize(len * 2 + 1);
        p[0]=1;
        p[1]=2;
        int r = 2;
        int center = 1;
        for (int i = 2; i < 2*len+1; i++)
        {
            if (center + r - 1 > i)
            {
                if (p[2 * center - i] + i < center + r) p[i]=p[2 * center - i];
                else {
                    int tt = center + r - 1;
                    int tlen = tt - i + 1;
                    while (i - tlen >= 0 && i + tlen < 2*len+1&&t[i - tlen] == t[i + tlen])
                    {
                        tlen++;
                    }
                    if (tlen >= r)
                    {
                        r = tlen;
                        center = i;
                    }
                    p[i]=tlen;

                }
            }
            else
            {
                int j = 1;
                int tlen = 1;
                while (i + j < 2*len+1&&i - j >= 0 && t[i + j] == t[i - j])
                {
                    tlen++;
                    j++;
                }
                if (tlen >= r)
                {
                    r = tlen;
                    center = i;
                }
                p[i]=tlen;
            }	
        }
        center = (center - 1) / 2;
        return s.substr(center - r / 2 + 1,r-1);
    }
};
