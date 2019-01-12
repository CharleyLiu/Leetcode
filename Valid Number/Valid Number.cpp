class Solution {
public:
    bool isNumber(string s) {
        int i=0;
        int len=s.length();
        if(len==0) return false;

        bool dotflag=false;
        bool eflag=false;
        bool endblank=false;
        bool number=false;
        bool neednumber=false;
        bool eneednumber=false;
        while(s[i]==' ') ++i;
        if(i==len) return false;
        if(i==len-1)
        {
            if(s[i]=='+'||s[i]=='-'||s[i]=='.') return false;
        }
        if(s[i]=='-'||s[i]=='+')
        {
            if(i==len-1||((s[i+1]<'0'||s[i+1]>'9')&&s[i+1]!='.')) return false;
            ++i;
        }        
        for(i;i<len;++i)
        {
            if(s[i]==' ')
            {
                if(s[i-1]=='e') return false;
                else
                {
                    endblank=true;
                    continue;
                }
            }
            else if(s[i]>='0'&&s[i]<='9'&&!endblank)
            {
                number=true;
                if(neednumber) neednumber=false;
                if(eneednumber) eneednumber=false;
                continue;
            }
            else if(s[i]=='.'&&!endblank)
            {
                if(!number) neednumber=true;
                if(eflag) return false;
                if(dotflag) return false;
                dotflag=true;
                continue;
            }
            else if(s[i]=='e'&&!endblank)
            {
                if(eflag) return false;
                if(!number) return false;
                if(i==len-1) return false;
                if(s[i+1]=='+'||s[i+1]=='-') ++i;
                eneednumber=true;
                eflag=true;
                continue;
            }
            return false;
            
        }
        if(neednumber||eneednumber) return false; 
        return true;
    }
};
