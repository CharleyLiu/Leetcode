class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans={};
        if (numRows==0) return ans;
        ans.push_back({1});
        if(numRows==1) return ans;
        ans.push_back({1,1});
        if(numRows==2) return ans;
        for(int i=2;i<numRows;++i)
        {
            int lastpos=ans.size()-1;
            int sz=ans[lastpos].size();
            vector<int> level={1};
            for(int j=0;j<sz-1;++j)
            {
                level.push_back(ans[lastpos][j]+ans[lastpos][j+1]);
            }
            level.push_back(1);
            ans.push_back(level);
        }
        return ans;
        
    }
};
