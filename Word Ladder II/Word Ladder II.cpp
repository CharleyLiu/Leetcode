class Solution {
private:
    unordered_map<string, pair<vector<string>, int>> visited;
    void dfs(vector<vector<string>>& ans,vector<string>& v,string& word,string& target)
    {
        if(word==target)
        {
            reverse(v.begin(),v.end());
            ans.push_back(v);
            reverse(v.begin(),v.end());
            return;
        }
        for(string& w:visited[word].first)
        {
            v.push_back(w);
            dfs(ans,v,w,target);
            v.pop_back();
        }
    }
    
public:
        vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        int slen = beginWord.length();
        queue<string> q;
        unordered_map<string, vector<string>> mapper;

        string tmp;
        for (string& word : wordList)
        {
            if(word!=beginWord)
            {
                for (int i = 0; i < slen; ++i)
                {
                    tmp = word.substr(0, i);
                    tmp += "*";
                    tmp += word.substr(i + 1, slen - i - 1);
                    mapper[tmp].push_back(word);
                }
            }
        }
        q.push(beginWord);
        string front;
        int lastcount = 1;
        int level = 1;
        int ccount = 0;
        bool found=false;
        while (!q.empty())
        {
            for (int i = 0; i < lastcount; ++i)
            {
                front = q.front();
                q.pop();
                for (int j = 0; j < slen; ++j)
                {
                    tmp = front.substr(0, j);
                    tmp += "*";
                    tmp += front.substr(j + 1, slen - 1 - j);
                    if (mapper.find(tmp) != mapper.end())
                    {
                        for (string& word : mapper[tmp])
                        {
                            if(word==endWord) found=true;
                            if (visited.find(word) == visited.end())
                            {
                                visited[word] = { { front }, level };
                                q.push(word);
                                ++ccount;
                            }
                            else
                            {
                                if (visited[word].second == level)
                                {
                                    visited[word].first.push_back(front);
                                    // q.push(word);
                                    // ++ccount;
                                }

                            }
                        }
                    }
                }
            }
            if(found) break;
            lastcount = ccount;
            ccount = 0;
            ++level;
        }
        if(visited.find(endWord)==visited.end()) return {};
        vector<vector<string>> ans={};
        vector<string> v={endWord};
        dfs(ans,v,endWord,beginWord);
        return ans;
        
            
        
        
        
    }
};
