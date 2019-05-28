class Solution {
public:
    void search(vector<vector<char>>& board, int i,int j,int& height,int& width)
    {
        if(board[i][j]=='O')
        {
            board[i][j]='1';
            if(i-1>=0) search(board,i-1,j,height,width);
            if(i+1<height) search(board,i+1,j,height,width);
            if(j-1>=0) search(board,i,j-1,height,width);
            if(j+1<width) search(board,i,j+1,height,width);
        }
    }
    void solve(vector<vector<char>>& board) {
        int height=board.size();
        if(height==0) return;
        int width=board[0].size();
        if(width==0) return;
        for(int i=0;i<width;++i)
        {
            if(board[0][i]=='O') search(board,0,i,height,width);
            if(board[height-1][i]=='O') search(board,height-1,i,height,width);
        }
        for(int i=1;i<height-1;++i)
        {
            if(board[i][0]=='O') search(board,i,0,height,width);
            if(board[i][width-1]=='O') search(board,i,width-1,height,width);
        }
        for(int i=1;i<height-1;++i)
        {
            for(int j=1;j<width-1;++j)
            {
                if(board[i][j]=='O') board[i][j]='X';
            }
        }
        for(int i=0;i<height;++i)
        {
            for(int j=0;j<width;++j)
            {
                if(board[i][j]=='1') board[i][j]='O';
            }
        }
        
    }
};
