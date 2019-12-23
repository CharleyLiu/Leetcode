class Solution {
public:
    struct Node{
        char c;
        bool end;
        Node* next[26];
        Node(){
            end=false;
            for(int i=0;i<26;++i) next[i]=NULL;
        }
        void addString(string& s,int index){
            this->c=s[index];
            if(index==s.length()-1){
                end=true;
                return;
            }
            char nextc=s[index+1];
            if(next[nextc-'a']==NULL) next[nextc-'a']=new Node;
            next[nextc-'a']->addString(s,index+1);
        }
    };
    void checkboard(Node* node, int r, int c, vector<vector<char>>& board) {
        if (node->end) {
            node->end = false;
        }
        char oldc = board[r][c];
        board[r][c] = ' ';
        if (r > 0 && board[r - 1][c] != ' '&&node->next[board[r - 1][c] - 'a'] != NULL)
        {
            checkboard(node->next[board[r - 1][c] - 'a'], r - 1, c, board);
        }
        if (r < board.size() - 1 && board[r + 1][c] != ' '&&node->next[board[r + 1][c] - 'a'] != NULL)
        {
            checkboard(node->next[board[r + 1][c] - 'a'], r + 1, c, board);
        }
        if (c > 0 && board[r][c - 1] != ' '&&node->next[board[r][c - 1] - 'a'] != NULL)
        {
            checkboard(node->next[board[r][c - 1] - 'a'], r, c - 1, board);
        }
        if (c < board[0].size() - 1 && board[r][c + 1] != ' '&&node->next[board[r][c + 1] - 'a'] != NULL)
        {
            checkboard(node->next[board[r][c + 1] - 'a'], r, c + 1, board);
        }
        board[r][c] = oldc;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Node root;
        vector<string> ans;
        for(string& w:words){
            char c=w[0];
            if(root.next[c-'a']==NULL) root.next[c-'a']=new Node;
            root.next[c-'a']->addString(w,0);
        }
        if(board.empty()||board[0].empty()) return {};
        int h=board.size();
        int w=board[0].size();
        for(int i=0;i<h;++i){
            for(int j=0;j<w;++j){
                if (root.next[board[i][j] - 'a']) checkboard(root.next[board[i][j] - 'a'], i, j, board);
            }
        }
        for(string& w:words){
            Node* cur=&root;
            for(int i=0;i<w.size();++i){
                cur=cur->next[w[i]-'a'];
            }
            if(!cur->end) ans.push_back(w);
        }
        return ans;
    }
};
