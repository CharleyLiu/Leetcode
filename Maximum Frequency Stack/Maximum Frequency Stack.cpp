class FreqStack {
    unordered_map<int,int> freq;
    int maxfreq;
    unordered_map<int,stack<int>> stacks;
public:
    FreqStack() {
        maxfreq=0;
    }
    
    void push(int x) {
        if(freq.find(x)==freq.end()) freq[x]=1;
        else ++freq[x];
        maxfreq=max(freq[x],maxfreq);
        stacks[freq[x]].push(x);
    }
    
    int pop() {
        int ans=stacks[maxfreq].top();
        stacks[maxfreq].pop();
        if(stacks[maxfreq].empty()) --maxfreq;
        --freq[ans];
        return ans;
        
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 */
