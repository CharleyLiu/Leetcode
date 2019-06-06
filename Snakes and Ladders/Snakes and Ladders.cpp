class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        queue<int> q;
        unordered_set<int> visited;
        visited.insert(1);
        int len=board.size();
        int target=len*len;
        q.push(1);
        int count=0;
        int lastcount=1;
        int curcount=0;
        while(!q.empty())
        {
            for(int i=0;i<lastcount;++i)
            {
                int cur=q.front();
                q.pop();
                for(int j=1;j<=6;++j)
                {
                    int next=cur+j;
                    if(visited.find(next)==visited.end())
                    {
                        visited.insert(next);
                        if(next==target) return count+1;
                        if(next<target)
                        {
                            int r=(next-1)/len;
                            int c= r%2==0? (next-1)%len:len-1-(next-1)%len;
                            if(board[len-r-1][c]!=-1)
                            {
                                if(board[len-r-1][c]==target) return count+1;
                                q.push(board[len-r-1][c]);
                                //visited.insert(board[len-r-1][c]);
                                ++curcount;
                            }
                            else 
                            {
                                q.push(next);
                                ++curcount;
                            }
                        }
                    }
                    
                }
            }
            lastcount=curcount;
            curcount=0;
            ++count;
        }
        return -1;
    }
};
