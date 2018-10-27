class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int i;
        if (strs.size()==0) return "";
        int len=strs[0].length();
        for(int j=1;j<strs.size();j++) len=(len<strs[j].length())?len:strs[j].length();
        for(i=0;i<len;i++)
        {
            char c=strs[0][i];
            for(int j=1;j<strs.size();j++)
            {
                if (strs[j][i]!=c) return strs[0].substr(0,i);
            }
        }
        return strs[0].substr(0,len);
    }
};
