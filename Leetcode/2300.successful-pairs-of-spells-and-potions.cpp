/*
 * @lc app=leetcode id=2300 lang=cpp
 *
 * [2300] Successful Pairs of Spells and Potions
 */

// @lc code=start
class Solution
{
public:
    int pairs(long long spell, vector<int> &potions, long long &success)
    {
        int f = 0, l = potions.size() - 1, mid;
        while (f <= l)
        {
            mid = f + (l - f) / 2;
            long long num = (long long)potions[mid] * spell;

            if (num >= success)
                l = mid - 1;
            else
                f = mid + 1;
        }
        return potions.size() - l - 1;
    }
    vector<int> successfulPairs(vector<int> &spells, vector<int> &potions, long long success)
    {
        vector<int> ans;
        sort(begin(potions), end(potions));
        for (auto &spell : spells)
            ans.push_back(pairs(spell, potions, success));
        return ans;
    }
};
// @lc code=end
