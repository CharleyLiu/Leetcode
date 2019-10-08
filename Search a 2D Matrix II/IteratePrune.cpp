class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size()==0||matrix[0].size()==0) return false;
        int height=matrix.size();
        int width=matrix[0].size();
        int r=height-1;
        int c=0;
        while(c<width&&r>=0)
        {
            if(matrix[r][c]>target) --r;
            else if(matrix[r][c]==target) return true;
            else ++c;
        }
        return false;
        
    }
};
