class Solution {
public:
    struct pair_hash{
        size_t operator()(pair<int,int> const& p) const{
            size_t h1=hash<int>()(p.first);
            size_t h2=hash<int>()(p.second);
            return h1^h2;
        }
    };
    int gcd(int a, int b){
        if(b==0) return a;
        else return gcd(b,a%b);
    }
    int maxPoints(vector<vector<int>>& points) {
        int sz=points.size();
        int ans=0;
        for(int i=0;i<sz;++i)
        {
            unordered_map<pair<int,int>,int,pair_hash> count;
            int dup=1;
            for(int j=i+1;j<sz;++j)
            {
                if(points[i]==points[j]) ++dup;
                else{
                    int dx=points[i][0]-points[j][0];
                    int dy=points[i][1]-points[j][1];
                    int g=gcd(dx,dy);
                    dx=dx/g;
                    dy=dy/g;
                    if(dx==0) dy=1;
                    if(dy==0) dx=1;
                    pair<int,int> key={dx,dy};
                    if(count.find(key)==count.end()) count[key]=1;
                    else ++count[key];
                }
            }
            ans=max(ans,dup);
            for(auto& p:count) ans=max(ans,dup+p.second);
        }
        return ans;

        
    }
};
