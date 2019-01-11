class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans={};
        int row=0;
        int col=0;
        int limit=0;
        int height=matrix.size();
        if(height==0) return ans;
        int width=matrix[0].size();
        while(1)
        {
            if(col>=width-limit) break;
            for(;col<width-limit;++col)
            {
                ans.push_back(matrix[row][col]);
            }
            --col;
            ++row;
            if(row>=height-limit) break;
            for(;row<height-limit;++row)
            {
                ans.push_back(matrix[row][col]);
            }
            --row;
            --col;
            if(col<limit) break;
            for(;col>=limit;--col)
            {
                ans.push_back(matrix[row][col]);
            }
            ++col;
            --row;
            if(row<=limit) break;
            for(;row>limit;--row) ans.push_back(matrix[row][col]);
            ++row;
            ++col;
            ++limit;
        }
        return ans;
        
    }
};
