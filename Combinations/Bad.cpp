class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
    vector<vector<vector<int>>> bottom;
    vector<vector<vector<int>>> head;
    bottom.resize(n+1);
    head.resize(n+1);
    for(int i=1;i<=n;++i)
    {
        bottom[i]={};
        head[i]={};
        bottom[i].push_back({});
    }
    for(int i=1;i<=k;++i)
    {
        head[i]={};
        head[i].push_back({});
        for(int m=1;m<=i;++m) head[i][0].push_back(m);
        for(int j=i+1;j<=n;++j)
        {
            head[j]=head[j-1];
            for(vector<int>& tmp:bottom[j-1]){
                tmp.push_back(j);
                head[j].push_back(tmp);
            }// bottom[j-1].append(n)
        }
        for(int m=i;m<=n;++m) bottom[m]=head[m];
    }
    return head[n];
        
    }
};
