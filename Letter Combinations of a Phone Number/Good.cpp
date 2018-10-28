class Solution {
public:
    vector<string> letterCombinations(string digits) {
        string s[8]={"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        int len=digits.length();
        vector<string> ans;
        if(len==0) return ans;
        ans.push_back("");
        for(int i=0;i<len;i++)
        {
            int size=ans.size();
            for(int j=1;j<s[digits[i]-'0'-2].length();j++)
            {
               for(int k=0;k<size;k++)
               {
                   ans.push_back(ans[k]);
               }
            }
            for(int j=0;j<s[digits[i]-'0'-2].length();j++)
            {
                for(int k=j*size;k<(j+1)*size;k++)
                {
                    ans[k]=ans[k]+s[digits[i]-'0'-2][j];
                }
            }
        }
        return ans;
        
    }
};
