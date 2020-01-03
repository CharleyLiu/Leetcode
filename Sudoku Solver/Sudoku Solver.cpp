class Solution {
    int box[9][10]={0};
    int row[9][10]={0};
    int col[9][10]={0};
    int boxindex(int& r,int& c){
        if(r<=2){
            if(c<=2) return 0;
            if(c<=5) return 1;
            else return 2;
        }
        if(r<=5){
            if(c<=2) return 3;
            if(c<=5) return 4;
            else return 5;
        }
        else{
            if(c<=2) return 6;
            if(c<=5) return 7;
            else return 8;
        }
    }
    void init(vector<vector<char>>& board){
        for(int i=0;i<9;++i){
            for(int j=0;j<9;++j){
                if(board[i][j]!='.'){
                    int num=board[i][j]-'0';
                    int boxi=boxindex(i,j);
                    box[boxi][num]=1;
                    row[i][num]=1;
                    col[j][num]=1;
                }
            }
        }
        for(int i=0;i<9;++i){
            box[i][0]=1;
            col[i][0]=1;
            row[i][0]=1;
        }
    }
    bool solve(vector<vector<char>>& board,int r,int c){
        if(r==0&&c==9) return true;
        if(board[r][c]=='.'){
            unordered_set<int> cand={};
            for(int i=1;i<10;++i){
                if(row[r][i]==0) cand.insert(i);
            }
            for(int i=1;i<10;++i){
                if(col[c][i]&&cand.find(i)!=cand.end()) cand.erase(i);
            }
            int boxi=boxindex(r,c);
            for(int i=1;i<10;++i){
                if(box[boxi][i]&&cand.find(i)!=cand.end()) cand.erase(i);
            }
            if(cand.empty()) return false;
            for(int const& num:cand){
                board[r][c]=num+'0';
                int newr=r+1;
                int newc=c;
                if(newr==9){
                    newr=0;
                    ++newc;
                }
                box[boxi][num]=1;
                col[c][num]=1;
                row[r][num]=1;
                bool flag=solve(board,newr,newc);
                if(flag) return true;
                box[boxi][num]=0;
                col[c][num]=0;
                row[r][num]=0;
            }
            board[r][c]='.';
            return false;
        }
        else{
            ++r;
            if(r==9){
                r=0;
                ++c;
            }
            bool f=solve(board,r,c);
            return f;
        }
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        init(board);
        bool f=solve(board,0,0);
    }
};
