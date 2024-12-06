class LFUCache
{
public:
    unordered_map<int, list<vector<int>>::iterator> mp;
    unordered_map<int, list<vector<int>>> countmap;
    int sz, mncnt = 0;

    LFUCache(int capacity)
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
            int val = (*it)[1], fr = (*it)[2];

            countmap[fr].erase(it);
            if (countmap[fr].empty())
            {
                countmap.erase(fr);
                mncnt++;
            }

            countmap[fr + 1].push_front({key, val, fr + 1});
            mp[key] = countmap[fr + 1].begin();

            return val;
        }
    }

    void put(int key, int value)
    {
        if (mp.find(key) == mp.end())
        {
            if (mp.size() == sz)
            {
                auto &targetlist = countmap[mncnt];
                auto it = --targetlist.end();
                int k = (*it)[0];
                mp.erase(k);
                targetlist.pop_back();
                if (targetlist.empty())
                    countmap.erase(mncnt);
            }
            countmap[1].push_front({key, value, 1});
            mp[key] = countmap[1].begin();
            mncnt = 1;
        }
        else
        {
            auto it = mp[key];
            (*it)[1] = value;
            get(key);
        }
    }
};
