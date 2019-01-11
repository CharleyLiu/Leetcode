class Solution {
public:
    int lengthOfLastWord(string s) {
        int index=-1;
        int len=s.length();
        int i;
        for(i=len-1;i>=0;--i)
        {
            if(s[i]!=' ') {index=i;break;}
        }
        for(i=index;i>=0;--i)
        {
            if(s[i]==' ') break;
        }
        
        return index-i;
        
    }
};
