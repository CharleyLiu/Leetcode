class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        if(N==0) return cells;
        vector<int> cur(8,0);
        vector<int> last(8,0);
        for(int i=1;i<7;++i)
        {
            if(cells[i-1]==cells[i+1]) cur[i]=1;
            else cur[i]=0;
        }
        vector<int> original(cur.begin(),cur.end());
        swap(last,cur);
        for(int i=1;i<N;++i)
        {
            for(int j=1;j<7;++j)
            {
                if(last[j-1]==last[j+1]) cur[j]=1;
                else cur[j]=0;
            }
            if(cur==original)
            {
                if(i!=1)
                {
                    N=(N-1)%i;
                    i=-1;
                }
                else return cur;
            }
            swap(cur,last);
            
        }

        return last;
    }
};
