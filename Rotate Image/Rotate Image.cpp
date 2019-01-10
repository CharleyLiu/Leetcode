class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int len=matrix.size()-1;
        for(int j=0;j<=len/2;++j)
        {
            for(int i=j;i<len-j;++i)
            {
                int temp=matrix[j][i];
                matrix[j][i]=matrix[len-i][j];
                matrix[len-i][j]=matrix[len-j][len-i];
                matrix[len-j][len-i]=matrix[i][len-j];
                matrix[i][len-j]=temp;
            }
        }
        
    }
};
