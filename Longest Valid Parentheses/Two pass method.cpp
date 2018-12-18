class Solution {
public:
    int longestValidParentheses(string s) {
        int len=s.length();
        int ans=0;
        int l=0;
        int start=0;
        for(int i=0;i<len;++i)
        {
            if(s[i]=='(')
            {
                ++l;
            }
            else if(s[i]==')')
            {
                --l;
            }
            if(l==-1)
            {
                start=i+1;
                l=0;
            }
            else if(l==0)
            {
                int templ=i-start+1;
                if(templ>ans) ans=templ;
            }
        }
        l=0;
        start=len-1;
        for(int i=len-1;i>=0;--i)
        {
            if(s[i]==')')
            {
                ++l;
            }
            else if(s[i]=='(')
            {
                --l;
            }
            if(l==-1)
            {
                start=i-1;
                l=0;
            }
            else if(l==0)
            {
                int templ=start-i+1;
                if(templ>ans) ans=templ;
            }
        }
        return ans;
        
    }
};
