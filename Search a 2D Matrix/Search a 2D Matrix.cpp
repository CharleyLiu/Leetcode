class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size()==0||matrix[0].size()==0) return false;
        int col=matrix[0].size();
        int lo=0;
        int hi=matrix.size()*col-1;
        int mid;
        while(lo<=hi)
        {
            mid=(lo+hi)/2;
            int r=mid/col;
            int c=mid%col;
            if(matrix[r][c]==target) return true;
            else if(matrix[r][c]<target) lo=mid+1;
            else hi=mid-1;
        }
        return false;
        
    }
};
