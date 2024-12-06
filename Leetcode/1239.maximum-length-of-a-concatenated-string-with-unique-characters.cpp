/*
 * @lc app=leetcode id=1239 lang=cpp
 *
 * [1239] Maximum Length of a Concatenated String with Unique Characters
 */

// @lc code=start
class Solution
{
public:
    unordered_map<int, int> dp;
    int gensub(int i, int state, vector<string> &arr)
    {
        if (i == arr.size())
            return 0;

        if (dp.count(state))
            return dp[state];

        int take = 0, skip = 0, flag = 0, original = state;

        skip = gensub(i + 1, state, arr);

        for (auto &ch : arr[i])
        {
            int x = ch - 'a';
            x = 1 << x;
            if ((state & x) > 0)
            {
                flag = 1;
                break;
            }
            else
                state |= x;
        }
        if (flag == 0)
            take = arr[i].size() + gensub(i + 1, state, arr);

        return dp[original] = max(take, skip);
    }
    int maxLength(vector<string> &arr)
    {
        return gensub(0, 0, arr);
    }
};
// @lc code=end
