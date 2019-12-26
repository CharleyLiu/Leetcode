class Solution {
public:
    string longestPalindrome(string s) {
        if(s.empty()) return "";
        int len=s.size();
        int index=0;
        int sz=1;
        for(int i=0;i<len;++i)
        {
            int j=1;
            while(i-j>=0&&i+j<len){
                if(s[i-j]!=s[i+j]) break;
                ++j;
            }
            int tmpsz=2*(j-1)+1;
            if(tmpsz>sz){
                sz=tmpsz;
                index=i-j+1;
            }
            int right=i+1;
            int left=i;
            while(left>=0&&right<len){
                if(s[left]!=s[right]) break;
                --left;++right;
            }
            tmpsz=right-left-1;
            if(tmpsz>sz){
                sz=tmpsz;
                index=left+1;
            }
        }
        return s.substr(index,sz);
    }
};
