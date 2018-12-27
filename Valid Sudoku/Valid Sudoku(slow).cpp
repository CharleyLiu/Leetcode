class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<string,bool> hash;
        unordered_map<string,bool>::iterator got=hash.end();
        for(int i=0;i<9;++i)
        {
            for(int j=0;j<9;++j)
            {
                if(board[i][j]!='.')
                {
                    string row="row"+to_string(i)+board[i][j];
                    string col="col"+to_string(j)+board[i][j];
                    string cube="cub"+to_string(i/3)+to_string(j/3)+board[i][j];
                            if(hash.find(row)!=got||hash.find(col)!=got||hash.find(cube)!=got)
                            {
                                return false;
                            }
                    else
                    {
                        hash[row]=true;
                        hash[col]=true;
                        hash[cube]=true;
                    }
                }
            }
        }
        return true;
    }
};
