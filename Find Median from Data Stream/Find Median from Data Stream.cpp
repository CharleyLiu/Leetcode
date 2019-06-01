class MedianFinder {
private:
    priority_queue<int,vector<int>,less<int>> maxheap;
    priority_queue<int,vector<int>,greater<int>> minheap;
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(maxheap.size()==0) maxheap.push(num);
        else
        {
            if(num>maxheap.top()) minheap.push(num);
            else maxheap.push(num);
            if(maxheap.size()>1+minheap.size())
            {
                minheap.push(maxheap.top());
                maxheap.pop();
            }
            if(minheap.size()>1+maxheap.size())
            {
                maxheap.push(minheap.top());
                minheap.pop();
            }
        }
    }
    
    double findMedian() {
        if(minheap.size()==maxheap.size()) return (minheap.top()+maxheap.top())/2.0;
        else
        {
            if(maxheap.size()>minheap.size()) return maxheap.top();
            else return minheap.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
