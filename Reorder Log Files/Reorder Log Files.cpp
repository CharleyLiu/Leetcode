class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        int len=logs.size();
        if(len==0) return {};
        vector<string> ans;
        vector<string> numans;
        ans.reserve(len);
        for(int i=0;i<len;++i)
        {
            int t=logs[i].find(' ');
            if(isdigit(logs[i][t+1]))
            {
                numans.push_back(logs[i]);

            }
            else ans.push_back(logs[i]);
        }
        sort(ans.begin(),ans.end(),[](string& a,string& b)
             {
                 int abeg=a.find(' ')+1;
                 int bbeg=b.find(' ')+1;
                 int result=a.compare(abeg,string::npos,b,bbeg,string::npos);
                 if(result==0)
                 {
                     int subresult=a.compare(0,abeg-1,b,0,bbeg-1);
                     return subresult<0;
                 }
                 else return result<0;
             });
        ans.insert(ans.end(),numans.begin(),numans.end());
        return ans;
        
    }
};
