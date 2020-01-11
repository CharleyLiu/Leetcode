class LFUCache {
    struct Node{
        int freq;
        list<pair<int,int>> kv;
    };
    list<Node> fl;
    unordered_map<int,list<Node>::iterator> k2node;
    unordered_map<int,list<pair<int,int>>::iterator> k2kv;
    int cap;
    void erase_emtpy(list<Node>::iterator it){
        if(it->kv.empty()) fl.erase(it);
    }
    
public:
    LFUCache(int capacity) {
        cap=capacity;
    }
    void put(int key, int value) {
        if(cap==0) return;
        if(k2node.find(key)==k2node.end()){
            if(k2node.size()==cap){
                int rem_key=fl.begin()->kv.front().first;
                k2node.erase(rem_key);
                k2kv.erase(rem_key);
                fl.begin()->kv.pop_front();
                if(fl.begin()->kv.empty()) fl.pop_front();
                //delete lfu
            }
            if(fl.empty()||fl.front().freq!=1){
                Node node;
                node.freq=1;
                fl.push_front(node);
            }
            fl.front().kv.push_back({key,value});
            k2node[key]=fl.begin();
            k2kv[key]=fl.front().kv.end();
            --k2kv[key];
            //insert
        }
        else{
            //insert new;
            list<Node>::iterator newnodeit=k2node[key];
            ++newnodeit;
            if(newnodeit==fl.end()||newnodeit->freq!=k2node[key]->freq+1){
                Node node;
                node.freq=k2node[key]->freq+1;
                fl.insert(newnodeit,node);
                --newnodeit;
            }
            newnodeit->kv.push_back({key,value});
            k2node[key]->kv.erase(k2kv[key]);
            if(k2node[key]->kv.empty()) fl.erase(k2node[key]);
            //delete old;
            k2node[key]=newnodeit;
            k2kv[key]=newnodeit->kv.end();
            --k2kv[key];
        }
    }
    
    int get(int key) {
        if(k2kv.find(key)==k2kv.end()) return -1;
        int ans=k2kv[key]->second;
        put(key,ans);
        return ans;
    }
    
    
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
