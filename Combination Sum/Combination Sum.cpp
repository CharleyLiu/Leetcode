class Solution {
public:
    void mySum(vector<vector<int>>& ans, vector<int>& candidates, vector<int> s, int target, int id)
    {
        if(target==0) ans.push_back(s);
        else if(id==candidates.size()||candidates[id]>target) return;
        else
        {
            mySum(ans,candidates,s,target,id+1);
            s.push_back(candidates[id]);
            mySum(ans, candidates, s,target-candidates[id],id);
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        sort(candidates.begin(),candidates.end());
        mySum(ans, candidates, vector<int>() = {}, target, 0);
        return ans;
    }
};
