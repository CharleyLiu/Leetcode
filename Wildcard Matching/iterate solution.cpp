class Solution {
public:
    bool isMatch(string s, string p) {
        int j=0;
        int lasts=-1;
        int lastp=-1;
       for(int i=0;i<s.length();++i)
       {
           if(j==p.length())
           {
               if(p[j-1]=='*') return true;
               if(lastp==-1) return false;
               ++lasts;
               i=lasts;
               j=lastp+1;
           }
           if(s[i]==p[j])
           {
               ++j;
           }
           else if(p[j]=='?')
           {
               ++j;
           }
           else if(p[j]=='*')
           {
               lastp=j;
               lasts=i;
               ++j;
               --i;
           }
           else
           {
               if(lastp==-1) return false;
               i=lasts;
               ++lasts;
               j=lastp+1;
           }
       }
        while(j<p.length()&&p[j]=='*') ++j;
        if(j==p.length()) return true;
        else return false;
    }
};
