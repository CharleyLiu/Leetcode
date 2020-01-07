class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        priority_queue<int,vector<int>, greater<int>> pq;
        for(int& n:sticks) pq.push(n);
        int ans=0;
        while(pq.size()!=1){
            int n=pq.top();
            pq.pop();
            ans+=n+pq.top();
            pq.push(pq.top()+n);
            pq.pop();
        }
        return ans;
        
    }
};
