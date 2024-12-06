/*
 * @lc app=leetcode id=621 lang=cpp
 *
 * [621] Task Scheduler
 */

// @lc code=start
class Solution
{
public:
    int leastInterval(vector<char> &tasks, int n)
    {
        priority_queue<int> pq;
        unordered_map<char, int> mp;
        for (int i = 0; i < tasks.size(); i++)
            mp[tasks[i]]++;
        for (auto it = mp.begin(); it != mp.end(); it++)
            pq.push(it->second);
        int ans = 0, x;
        while (!pq.empty())
        {
            int cnt = 0;
            vector<int> temp;
            while (!pq.empty())
            {
                cnt++;
                x = pq.top() - 1;
                if (x > 0)
                    temp.push_back(x);
                pq.pop();
                if (cnt == n + 1)
                    break;
            }
            for (int i = 0; i < temp.size(); i++)
                pq.push(temp[i]);
            if (cnt - 1 < n and !pq.empty())
                ans += n - cnt + 1;
        }
        return ans + tasks.size();
    }
};
// @lc code=end
