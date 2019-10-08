class Solution {
public:
    bool rowsearch(vector<int>& row, int& target,int start)
    {
        int end=row.size()-1;
        int mid;
        while(start<=end)
        {
            mid=(start+end)/2;
            if(row[mid]==target) return true;
            if(row[mid]>target) end=mid-1;
            else start=mid+1;
        }
        return false;
    }
    bool colsearch(vector<vector<int>>& matrix,int& target, int start,int index)
    {
        int end=matrix.size()-1;
        int mid;
        while(start<=end)
        {
            mid=(start+end)/2;
            if(matrix[mid][index]==target) return true;
            if(matrix[mid][index]>target) end=mid-1;
            else start=mid+1;
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size()==0||matrix[0].size()==0) return false;
        int dlen=min(matrix.size(),matrix[0].size())-1;
        for(int i=0;i<=dlen;++i)
        {
            if(matrix[i][i]==target) return true;
            if(matrix[i][i]>target) return false;
            if(rowsearch(matrix[i],target,i+1)||colsearch(matrix,target,i-1,i))
                return true;
        }
        return false;
    }
};
