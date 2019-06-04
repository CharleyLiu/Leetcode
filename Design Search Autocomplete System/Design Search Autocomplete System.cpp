class AutocompleteSystem {
private:
    class Node
    {
    public:
        unordered_map<char,Node*> next;
        int count;
        Node():next({}),count(0){}
    };
    class comp{
    public:
      bool operator()(const pair<string,int>& lhs, const pair<string,int>& rhs){
          if (lhs.second==rhs.second) return lhs.first>rhs.first;
          return lhs.second<rhs.second;
      }  
    };
    void dfs(Node* root,string s)
    {
        if(root->count!=0)
        {
            pq.push(make_pair(s,root->count));
        }
        unordered_map<char,Node*>::iterator mapit=root->next.begin();
        while(mapit!=root->next.end())
        {
            dfs(mapit->second,s+mapit->first);
            ++mapit;
        }
    }
    priority_queue<pair<string,int>,vector<pair<string,int>>,comp> pq;
    Node* root;
    Node*  cur;
    string lastinput;
    bool exist;
public:
    AutocompleteSystem(vector<string>& sentences, vector<int>& times) {
        pq={};
        exist=true;
        lastinput="";
        root=new Node;
        for(int i=0;i<sentences.size();++i)
        {
            cur=root;
            string& sentence=sentences[i];
            int slen=sentence.size();
            for(int j=0;j<slen;++j)
            {
                if(cur->next.find(sentence[j])==cur->next.end())
                {
                    cur->next[sentence[j]]=new Node;
                }
                cur=cur->next[sentence[j]];
            }
            cur->count=times[i];
        }
        cur=root;
    }
    
    vector<string> input(char c) {
        pq={};
        if(c!='#')
        {
            lastinput+=c;
            if(exist)
            {
                if(cur->next.find(c)==cur->next.end())
                {
                    exist=false;
                    return {};
                }
                else
                {
                    cur=cur->next[c];
                    dfs(cur,lastinput);
                    vector<string> ans={};
                    for(int i=0;i<3;++i)
                    {
                        if(pq.empty()) break;   
                        ans.push_back(pq.top().first);
                        pq.pop();
                    }
                    return ans;
                }
            }
            else return {};
        }
        else
        {
            cur=root;
            exist=true;
            int slen=lastinput.size();
            for(int j=0;j<slen;++j)
            {
                if(cur->next.find(lastinput[j])==cur->next.end())
                {
                    cur->next[lastinput[j]]=new Node;
                }
                cur=cur->next[lastinput[j]];
            }
            cur->count+=1;
            cur=root;
            lastinput="";
            return {};
        }
    }
        
};

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem* obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj->input(c);
 */
