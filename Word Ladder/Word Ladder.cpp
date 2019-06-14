class Solution {
    
public:
    
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string,vector<string>> mapper;
        unordered_set<string> used;
        int slen;
        string tmp;
        for(string& word:wordList)
        {
            slen=word.length();
            for(int i=0;i<slen-1;++i)
            {
                tmp=word.substr(0,i);
                tmp+="*";
                tmp+=word.substr(i+1,slen-i-1);
                mapper[tmp].push_back(word);
            }
            tmp=word.substr(0,slen-1);
            tmp+="*";
            mapper[tmp].push_back(word);
        }
        queue<string> q;
        q.push(beginWord);
        int ans=1;
        int lvlcount=0;
        int lastcount=1;
        while(!q.empty())
        {
            for(int j=0;j<lastcount;++j)
            {
                if(q.front()==endWord)
                {
                    return ans;
                }
                for(int i=0;i<slen;++i)
                {

                    tmp=q.front().substr(0,i);
                    tmp+="*";
                    tmp+=q.front().substr(i+1,slen-i-1);

                    if(mapper.find(tmp)!=mapper.end())
                    {
                        for(string& s:mapper[tmp])
                        {
                            if(used.find(s)==used.end())
                            {
                                q.push(s);
                                used.insert(s);
                                ++lvlcount;
                            }
                        }
                    }
                }
                q.pop();
            }
            lastcount=lvlcount;
            lvlcount=0;
            ++ans;
        }
        return 0;
        
    }
};
