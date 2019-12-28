class Solution {
public:
    int len(vector<int>& p){
        return p[0]*p[0]+p[1]*p[1];
    }
    void quickSel(vector<vector<int>>& points,int left,int right,int K){
        if(left==right) return;
        int pvt=len(points[right]);
        int index=left;
        for(int i=left;i<right;++i){
            if(len(points[i])<pvt){
                swap(points[i],points[index]);
                ++index;
            }
        }
        swap(points[right],points[index]);
        if(index+1==K||index==K) return;
        if(index>K) quickSel(points,left,index-1,K);
        else quickSel(points,index+1,right,K);
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        quickSel(points,0,points.size()-1,K);
        vector<vector<int>> ans;
        for(int i=0;i<K;++i){
            ans.push_back(points[i]);
        }
        return ans;
    }
};
