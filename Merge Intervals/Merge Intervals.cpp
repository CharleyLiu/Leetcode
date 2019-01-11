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
        vector<Interval> ans={};
        int len=intervals.size();
        if(len==0) return ans;
        int f=intervals[0].start;
        int e=intervals[0].end;
        for(int i=1;i<len;++i)
        {
            if(intervals[i].start<=e)
            {
                e=max(e,intervals[i].end);
            }
            else
            {
                Interval in(f,e);
                ans.push_back(in);
                f=intervals[i].start;
                e=intervals[i].end;
            }
        }
        Interval in(f,e);
        ans.push_back(in);
        return ans;
        
    }
};
