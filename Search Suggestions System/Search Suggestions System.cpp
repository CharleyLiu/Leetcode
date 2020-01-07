class Solution {
    struct Node{
        Node* next[26]={NULL};
        bool end=false;
        void addStr(string& s,int index){
            if(s.size()==index){
                end=true;
                return;
            }
            int p=s[index]-'a';
            if(!next[p]) next[p]=new Node;
            next[p]->addStr(s,index+1);
        }
        bool search(vector<string>& tmpans,string& s){
            if(end) tmpans.push_back(s);
            if(tmpans.size()==3) return true;
            for(int i=0;i<26;++i){
                if(next[i]){
                    s+=i+'a';
                    bool f= next[i]->search(tmpans,s);
                    s.pop_back();
                    if(f) return true;
                }
            }
            return false;
        }
    };
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        Node* root=new Node;
        for(string& s: products){
            root->addStr(s,0);
        }
        Node* cur=root;
        vector<vector<string>> ans={};
        string slice="";
        bool f=false;
        for(char& c:searchWord){
            slice+=c;
            int index=c-'a';
            vector<string> tmpans={};
            if(!cur->next[index]) f=true;
            if(f) ans.push_back(tmpans);
            else{
                cur=cur->next[index];
                cur->search(tmpans,slice);
                ans.push_back(tmpans);
            }
        }
        return ans;
    }
};
