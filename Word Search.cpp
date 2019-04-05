class Solution {
public:
    bool helper(vector<vector<char>>& board,string& word,int i,int j,int index,bool** flag)
    {
        if(index==word.length()) return true;
        if(i>0&&!flag[i-1][j]&&board[i-1][j]==word[index]){
            flag[i-1][j]=true;
            if(helper(board,word,i-1,j,index+1,flag))
                return true;
            flag[i-1][j]=false;
        }
        if(j+1<board[0].size()&&!flag[i][j+1]&&board[i][j+1]==word[index]){
            flag[i][j+1]=true;
            if(helper(board,word,i,j+1,index+1,flag))
                return true;
            flag[i][j+1]=false;
        }
        if(i+1<board.size()&&!flag[i+1][j]&&board[i+1][j]==word[index]){
            flag[i+1][j]=true;
            if(helper(board,word,i+1,j,index+1,flag))
                return true;
            flag[i+1][j]=false;
        }
        if(j>0&&!flag[i][j-1]&&board[i][j-1]==word[index]){
            flag[i][j-1]=true;
            if(helper(board,word,i,j-1,index+1,flag))
                return true;
            flag[i][j-1]=false;
        }
        return false;
        
    }
    bool exist(vector<vector<char>>& board, string word) {
        int height=board.size();
        int width=board[0].size();
        bool** flag=new bool*[height];
        for(int k=0;k<height;++k)
        {
            flag[k]=new bool[width];
            for(int m=0;m<width;++m) flag[k][m]=false;
        }
        for(int i=0;i<height;++i){
            for(int j=0;j<width;++j){
                if(board[i][j]==word[0]){
                    flag[i][j]=true;
                    if(helper(board,word,i,j,1,flag)) return true;
                    flag[i][j]=false;
                    }
            }
        }
        for(int k=0;k<height;++k) delete[] flag[k];
        delete[] flag;
        return false;
    }
        
};
