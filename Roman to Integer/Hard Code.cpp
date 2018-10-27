class Solution {
public:
    int romanToInt(string s) {
        int ans=0;
        int len=s.length();
        for(int i=0;i<len;i++)
        {
            char c=s[i];
            if(i+1<len)
            {
                if(c=='C'&&(s[i+1]=='D'||s[i+1]=='M')) {ans-=100;continue;}
                if(c=='X'&&(s[i+1]=='L'||s[i+1]=='C')){ans-=10;continue;}
                if(c=='I'&&(s[i+1]=='V'||s[i+1]=='X')){ans-=1;continue;}
            }
            if(c=='I') ans+=1;
            else if(c=='V')ans+=5;
            else if(c=='X')ans+=10;
            else if(c=='L')ans+=50;
            else if(c=='C')ans+=100;
            else if(c=='D')ans+=500;
            else if(c=='M')ans+=1000;
        }
        return ans;
        
    }
};
