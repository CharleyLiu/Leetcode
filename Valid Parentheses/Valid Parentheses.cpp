class Solution {
public:
    bool isValid(string s) {
        int len=s.length();
        char* a=new char[len];
        int i=0;
        for(int j=0;j<len;j++)
        {
            char c=s[j];
            if(c=='(' ||c=='{'||c=='[') a[i++]=c;
            else
            {
                if(i==0) return false;
                if(c==')')
                {
                    if(a[i-1]!='(') return false;
                    else i--;
                }
                else if(c=='}')
                {
                    if(a[i-1]!='{') return false;
                    else i--;
                }
                else if(c==']')
                {
                    if(a[i-1]!='[') return false;
                    else i--;
                }
            }
        }
        if(i!=0) return false;
        return true;
    }
};
