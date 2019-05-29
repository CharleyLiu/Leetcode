class Solution {
public:
    void part(vector<vector<string>> &ans, vector<string>& v, string& s,int pos)
    {
        if(pos==s.length())
        {
            ans.push_back(v);
            return;
        }
        for(int i=pos;i<s.length();++i)
        {
            bool flag=true;
            int len=(i-pos)/2;
            for(int j=0;j<=len;++j)
            {
                if(s[pos+j]!=s[i-j])
                {
                    flag=false;
                    break;
                }
            }
            if(flag)
            {
                v.push_back(s.substr(pos,i-pos+1));
                part(ans,v,s,i+1);
                v.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans={};
        vector<string> v={};
        part(ans,v,s,0);
        return ans;
        
    }
};
