class Solution {
public:

    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        nth_element(points.begin(),points.begin()+K,points.end(),[](vector<int>& lhs,vector<int>& rhs){return lhs[0]*lhs[0]+lhs[1]*lhs[1]<rhs[0]*rhs[0]+rhs[1]*rhs[1];});
        vector<vector<int>> ans={};
        for(int i=0;i<K;++i)
        {
            ans.push_back(points[i]);
        }
        return ans;
            
    }
};
