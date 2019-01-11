/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> ans;
        int len=intervals.size();
        int i;
        for(i=0;i<len;++i)
        {
            if(newInterval.end<intervals[i].start)
            {
                break;
            }
            if(newInterval.start>intervals[i].end)
            {
                ans.push_back(intervals[i]);
            }
            else
            {
                newInterval.start=min(newInterval.start,intervals[i].start);
                newInterval.end=max(newInterval.end,intervals[i].end);
            }
        }
        ans.push_back(newInterval);
        for(;i<len;++i)
        {
            ans.push_back(intervals[i]);
        }
        return ans;
    }
};
