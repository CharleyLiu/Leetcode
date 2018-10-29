class Solution {
public:
    void rec(vector<string>& ans, string s,int left,int right, int max)
    {
        if(left==max&&left==right)
        {
            ans.push_back(s);
            return;
        }
        if(left<max)
        {
            rec(ans,s+"(",left+1,right,max);
        }
        if(right<left)
        {
            rec(ans,s+")",left,right+1,max);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        rec(ans,"",0,0,n);
        return ans;     
    }
};
