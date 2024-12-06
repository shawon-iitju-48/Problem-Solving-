/*
 * @lc app=leetcode id=981 lang=cpp
 *
 * [981] Time Based Key-Value Store
 */

// @lc code=start
class TimeMap
{
public:
    TimeMap()
    {
    }
    unordered_map<string, vector<pair<int, string>>> keymap;
    void set(string key, string value, int timestamp)
    {
        keymap[key].push_back(make_pair(timestamp, value));
    }

    string get(string key, int timestamp)
    {
        int first = 0, last = keymap[key].size() - 1, mid;
        auto &nums = keymap[key];
        while (first < last)
        {
            mid = (first + last) / 2;
            if (nums[mid].first == timestamp)
                return nums[mid].second;
            else if (nums[mid].first < timestamp)
                first = mid + 1;
            else
                last = mid - 1;
        }
        if (nums[0].first > timestamp)
            return "";
        else if (nums[first].first <= timestamp)
            return nums[first].second;
        else
            return nums[first - 1].second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
// @lc code=end
