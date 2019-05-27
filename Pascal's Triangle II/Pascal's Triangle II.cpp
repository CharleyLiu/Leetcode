class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if(rowIndex==0) return {1};
        if(rowIndex==1) return {1,1};
        vector<int> ans={1,2,1};
        for(int i=2;i<rowIndex;++i)
        {
            int sz=ans.size();
            for(int j=0;j<sz-1;++j)
            {
                ans[j]=ans[j]+ans[j+1];
            }
            ans.insert(ans.begin(),1);
        }
        return ans;
    }
};
