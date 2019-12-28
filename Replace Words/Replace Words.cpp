class Solution {
    struct Node{
        int end;
        Node* next[26];
        Node(){
            end=-1;
            for(int i=0;i<26;++i) next[i]=NULL;
        }
        void addStr(string& s,int pos,int& d){
            if(pos==s.size()){end=d;return;}
            int index=s[pos]-'a';
            if(!next[index]) next[index]=new Node;
            next[index]->addStr(s,pos+1,d);
        }
        int find(string&s, int pos){
            if(end>-1) return end;
            if(pos==s.size()) return -1;
            int index=s[pos]-'a';
            if(!next[index]) return -1;
            else return next[index]->find(s,pos+1);
        }
    };
public:
    string replaceWords(vector<string>& dict, string sentence) {
        if(dict.empty()) return sentence;
        Node* root=new Node;
        for(int i=0;i<dict.size();++i){
            root->addStr(dict[i],0,i);
        }
        int len=sentence.size();
        string ans="";
        int left=0;
        int right=sentence.find(' ',left);
        while(right!=-1){
            string sub=sentence.substr(left,right-left);
            int index=root->find(sub,0);
            if(index==-1) ans+=sub;
            else ans+=dict[index];
            ans.push_back(' ');
            left=right+1;
            right=sentence.find(' ',left);
        }
        string sub=sentence.substr(left,-1);
        int index=root->find(sub,0);
        if(index==-1) ans+=sub;
        else ans+=dict[index];
        return ans;
        
        
    }
};
