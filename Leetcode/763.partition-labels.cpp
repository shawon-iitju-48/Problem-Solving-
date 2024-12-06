/*
 * @lc app=leetcode id=763 lang=cpp
 *
 * [763] Partition Labels
 */

// @lc code=start
class Solution
{
public:
    vector<int> partitionLabels(string s)
    {
        unordered_map<char, int> mp;
        for (int i = s.size() - 1; i >= 0; i--)
        {
            if (mp.find(s[i]) == mp.end())
                mp[s[i]] = i;
        }
        vector<int> ans;
        int curr = 0, cnt = 0;
        for (int i = 0; i < s.size(); i++)
        {
            cnt++;
            curr = max(curr, mp[s[i]]);
            if (i == curr)
            {
                ans.push_back(cnt);
                cnt = 0;
            }
        }
        return ans;
    }
};
// @lc code=end
