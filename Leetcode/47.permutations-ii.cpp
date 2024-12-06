/*
 * @lc app=leetcode id=47 lang=cpp
 *
 * [47] Permutations II
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> ans;
    int n;
    void solve(int state, vector<int> current, vector<int> &nums)
    {
        if (state == (1 << n) - 1)
            ans.push_back(current);

        if ((state & 1) == 0)
        {
            current.push_back(nums[0]);
            solve((state | 1), current, nums);
            current.pop_back();
        }

        for (int i = 1; i < nums.size(); i++)
        {
            if (((1 << (i - 1)) & state) == 0 and nums[i] == nums[i - 1])
                continue;

            if (((1 << i) & state) == 0)
            {
                current.push_back(nums[i]);
                solve((state | (1 << i)), current, nums);
                current.pop_back();
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        n = nums.size();
        sort(nums.begin(), nums.end());
        solve(0, {}, nums);
        return ans;
    }
};
// @lc code=end
