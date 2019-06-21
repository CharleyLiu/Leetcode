class Solution {
public:
    string alienOrder(vector<string>& words) {
        int sz=words.size();
        unordered_map<char,unordered_set<char>> mapper;
        vector<int> indeg(26,-1);
        int pos=-1;
        int slen;
        int total=0;
        for(int i=0;i<sz-1;++i)
        {
            pos=-1;
            slen=min(words[i].size(),words[i+1].size());
            for(int j=0;j<slen;++j)
            {
                if(indeg[words[i][j]-'a']==-1) indeg[words[i][j]-'a']=0;
                if(indeg[words[i+1][j]-'a']==-1) indeg[words[i+1][j]-'a']=0;
                if(words[i][j]!=words[i+1][j])
                {
                    pos=j;
                    break;
                }
            }
            if(pos!=-1)
            {
                if(mapper[words[i][pos]].find(words[i+1][pos])==mapper[words[i][pos]].end())
                {
                    ++indeg[words[i+1][pos]-'a'];
                    mapper[words[i][pos]].insert(words[i+1][pos]);
                }
            }
            for(int j=pos+1;j<words[i].size();++j)
            {
                if(indeg[words[i][j]-'a']==-1) indeg[words[i][j]-'a']=0;
            }
        }
        for(int j=pos+1;j<words[sz-1].size();++j)
        {
            if(indeg[words[sz-1][j]-'a']==-1) indeg[words[sz-1][j]-'a']=0;
        }
        queue<char> q;
        string ans="";
        for(int i=0;i<26;++i)
        {
            if(indeg[i]!=-1)
            {
                ++total;
                if(indeg[i]==0)
                {
                    q.push(i+'a');
                    ans+=i+'a';
                }
            }

        }
        char c;
        while(!q.empty())
        {
            c=q.front();
            q.pop();
            for(auto& next:mapper[c])
            {
                if(indeg[next-'a']==1)
                {
                    q.push(next);
                    ans+=next;
                }
                --indeg[next-'a'];
            }
        }
        if(ans.size()!=total) return "";
        else return ans;
    }
};
