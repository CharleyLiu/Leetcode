class LRUCache {
public:
    unordered_map<int,list<pair<int,int>>::iterator> mapper;
    list<pair<int,int>> lst;
    int capacity;
    LRUCache(int capacity) {
        this->capacity=capacity;
    }
    
    int get(int key) {
        if(mapper.find(key)==mapper.end()) return -1;
        else
        {
            int ans=mapper[key]->second;
            lst.erase(mapper[key]);
            lst.push_back(make_pair(key,ans));
            mapper[key]=--lst.end();
            return ans;
        }
    }
    
    void put(int key, int value) {
        if(mapper.find(key)==mapper.end())
        {
            if(lst.size()>=capacity)
            {
                int popkey=lst.front().first;
                lst.erase(lst.begin());
                mapper.erase(popkey);
            }
        }
        else
            lst.erase(mapper[key]);
        lst.push_back(make_pair(key,value));
        mapper[key]=--lst.end();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
