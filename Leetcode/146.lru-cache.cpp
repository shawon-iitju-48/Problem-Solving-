class LRUCache
{
public:
    int sz;
    list<vector<int>> lrulist;
    unordered_map<int, list<vector<int>>::iterator> mp;
    LRUCache(int capacity)
    {
        sz = capacity;
    }

    int get(int key)
    {
        if (mp.find(key) == mp.end())
            return -1;
        else
        {
            auto it = mp[key];
            int value = (*it)[1];
            lrulist.erase(it);
            lrulist.push_front({key, value});
            mp[key] = lrulist.begin();
            return value;
        }
    }

    void put(int key, int value)
    {
        if (mp.find(key) == mp.end())
        {
            if (mp.size() == sz)
            {
                auto addr = lrulist.back();
                int k = (*addr)[0];
                mp.erase(k);
                lrulist.pop_back();
            }
            lrulist.push_front({key, value});
            mp[key] = lrulist.begin();
        }
        else
        {
            auto it = mp[key];
            (*it)[1] = value;
            get(key);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */