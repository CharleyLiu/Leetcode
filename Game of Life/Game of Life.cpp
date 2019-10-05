class Solution {
public:
    bool check(vector<vector<int>>& board, int a,int b)
    {
        if(board[a][b]==1||board[a][b]==-1) return true;
        return false;
    }
    void gameOfLife(vector<vector<int>>& board) {
        if(board.size()==0||board[0].size()==0) return;
        int height=board.size();
        int width=board[0].size();
        for(int i=0;i<height;++i)
        {
            for(int j=0;j<board[0].size();++j)
            {
                int num=0;
                if(i>0&&check(board,i-1,j)) ++num;
                if(i<height-1&&check(board,i+1,j)) ++num;
                if(j>0&&check(board,i,j-1)) ++num;
                if(j<width-1&&check(board,i,j+1))++num;
                if(i>0&&j>0&&check(board,i-1,j-1))++num;
                if(i>0&&j<width-1&&check(board,i-1,j+1)) ++num;
                if(i<height-1&&j>0&&check(board,i+1,j-1))++num;
                if(i<height-1&&j<width-1&&check(board,i+1,j+1))++num;
                if(board[i][j]==1)
                {
                    if(num<2) board[i][j]=-1;
                    if(num>3) board[i][j]=-1;
                }
                else
                {
                    if(num==3) board[i][j]=2;
                }
            }
        }
        for(int i=0;i<height;++i)
        {
            for(int j=0;j<width;++j)
            {
                if(board[i][j]==-1) board[i][j]=0;
                else if(board[i][j]==2) board[i][j]=1;
            }
        }
        
    }
};
