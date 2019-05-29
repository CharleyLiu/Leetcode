class Solution {
public:
    class mycomparison
    {
    public:
      bool operator() (const pair<vector<int>,int>& lhs, const pair<vector<int>,int>&rhs) const
      {
        return lhs.second<rhs.second;
      }
    };
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        priority_queue<pair<vector<int>,int>,vector<pair<vector<int>,int>>, mycomparison> pq;
        vector<vector<int>> ans={};
        for(vector<int>& point:points)
        {
            int val=point[0]*point[0]+point[1]*point[1];
            if(pq.size()<K)
            {
                pq.push(make_pair(point,val));
            }
            else
            {
                if(val<pq.top().second)
                {
                    pq.pop();
                    pq.push(make_pair(point,val));
                }
            }
        }
        for(int i=0;i<K;++i)
        {
            ans.push_back(pq.top().first);
            pq.pop();
        }
        return ans;
            
    }
};
