class Solution {
public:
    string addBinary(string a, string b) {
        if(a.length()>b.length()) swap(a,b);
        string ans="";
        int alen=a.length();
        int blen=b.length();
        int diff=blen-alen;
        int i;
        bool ac=false;
        for(i=alen-1;i>=0;--i)
        {
            char c;
            if(ac)
            {
                c=a[i]+b[diff+i]-'0'+1;
                ac=false;
            }
            else c=a[i]+b[diff+i]-'0';

            if(c>='2')
            {
                c=c-2;
                ac=true;
            }
            ans=c+ans;
        }
        for(int j=diff-1;j>=0;--j)
        {
            if(ac)
            {
                if(b[j]=='1') ans='0'+ans;
                else
                {
                    ans='1'+ans;
                    ac=false;
                }
            }
            else
            {
                ans=b[j]+ans;
            }
        }
        if(ac) ans='1'+ans;
        return ans;
    }
};
