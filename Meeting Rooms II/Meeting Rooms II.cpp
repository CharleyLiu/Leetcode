class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        if (intervals.size()==0) return 0;
        sort(intervals.begin(),intervals.end());
        priority_queue<int,vector<int>,greater<int>> pq;
        for(vector<int>& interval:intervals)
        {
            if(pq.empty()) pq.push(interval[1]);
            else
            {
                if(pq.top()<=interval[0])
                {
                    pq.pop();
                    pq.push(interval[1]);
                }
                else
                {
                    pq.push(interval[1]);
                }
            }
        }
        return pq.size();
    }
};
