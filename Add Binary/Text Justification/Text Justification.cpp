class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int len=words.size();
        int i=0;
        vector<string> ans;
        while(i<len)
        {
            int count=words[i].length();
            int ini=i;
            while(i<len-1&&count+words[i+1].length()+i-ini+1<=maxWidth)
            {
                ++i;
                count=count+words[i].length();
            }
            if(i==len-1&&count+i-ini<=maxWidth)
            {
                i=ini;
                string s=words[i];
                ++i;
                while(i!=len)
                {
                    s=s+" "+words[i];
                    ++i;
                }
                while(s.length()<maxWidth) s=s+" ";
                ans.push_back(s);
            }
            else
            {
                int numspace=i-ini;
                if(numspace==0)
                {
                    string s=words[i];
                    for(int j=maxWidth-s.length();j>0;--j)
                    {
                        s=s+" ";
                    }
                    ans.push_back(s);
                    ++i;
                }
                else
                {
                    i=ini;
                    string s=words[i];
                    int spacecount=maxWidth-count;
                    int eachspace=spacecount/numspace;
                    int extra=spacecount-eachspace*numspace;
                    for(int j=0;j<extra;++j)
                    {
                        for(int k=0;k<=eachspace;++k) s=s+" ";
                        s=s+words[i+j+1];
                    }
                    i=i+extra+1;
                    while(s.length()<maxWidth)
                    {
                        for(int k=0;k<eachspace;++k)s=s+" ";
                        s=s+words[i];
                        ++i;
                    }
                    ans.push_back(s);
                }
            }
        }
        return ans;
    }
};
