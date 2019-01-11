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
    struct myclass {
  bool operator() (Interval i,Interval j) 
  { 
      return (i.start<j.start);
  }
} myobject;
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        sort(intervals.begin(),intervals.end(),myobject);
        for(int i=1;i<intervals.size();++i)
        {
            if(intervals[i].start<=intervals[i-1].end)
            {
                int e=max(intervals[i].end,intervals[i-1].end);
                intervals[i-1].end=e;
                intervals.erase(intervals.begin()+i);
                --i;
            }
        }
        return intervals;
        
    }
};
