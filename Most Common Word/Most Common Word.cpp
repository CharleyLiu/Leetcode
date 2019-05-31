class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        int len=paragraph.size();
        unordered_map<string,int> mapper;
        unordered_set<string> ban;
        for(int i=0;i<banned.size();++i)
            ban.insert(banned[i]);
        int beg=0;
        while(beg<len)
        {
            string sub="";
            while(beg<len)
            {
                if(paragraph[beg]==' '||ispunct(paragraph[beg]))
                {
                    while(beg<len&&(paragraph[beg]==' '||ispunct(paragraph[beg]))) ++beg;
                    break;
                }
                if(isalpha(paragraph[beg])) sub+=tolower(paragraph[beg]);
                ++beg;
            }
            // string sub=paragraph.substr(beg,end-beg);
            if(ban.find(sub)==ban.end())
            {
                if(mapper.find(sub)==mapper.end())
                mapper[sub]=1;
                else mapper[sub]+=1;
            }
        }

        unordered_map<string,int>::iterator itr=mapper.begin();
        int maxcount=0;
        unordered_map<string,int>::iterator maxstr=mapper.begin();
        while(itr!=mapper.end())
        {
            if((*itr).second>maxcount)
            {
                maxcount=(*itr).second;
                maxstr=itr;
            }
            ++itr;
        }
        return (*maxstr).first;
    }
};
