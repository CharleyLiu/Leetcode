class Solution {
public:
    string convert(string s, int numRows) {
        int d=(numRows-1)*2;
        if(d==0) return s;
        string ans;
        int len=s.length();
        ans.resize(len);
        int j=0;
        int z=0;
        while(j<len)
        {
            ans[z++]=s[j];
            j=j+d;
        }
        for(int i=1;i<numRows-1;i++)
        {
            int j=i;
            while(j<len)
            {
                ans[z++]=s[j];
                j=j+d-2*i;
                if(j<len)
                {
                    ans[z++]=s[j];
                    j=j+2*i;
                }
            }
        }
        int i=numRows-1;
        while(i<len)
        {
            ans[z++]=s[i];
            i=i+d;
        }
        return ans;
    }
};
