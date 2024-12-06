/*
 * @lc app=leetcode id=1425 lang=cpp
 *
 * [1425] Constrained Subsequence Sum
 */

// @lc code=start
class Solution
{
public:
    int constrainedSubsetSum(vector<int> &nums, int k)
    {
        deque<int> q;
        q.push_back(0);
        int mx = nums[0];

        for (int i = 1; i < nums.size(); i++)
        {
            while (!q.empty() and q.front() < i - k)
                q.pop_front();

            nums[i] = max(nums[i], nums[i] + nums[q.front()]);
            mx = max(mx, nums[i]);

            while (!q.empty() and nums[q.back()] < nums[i])
                q.pop_back();

            q.push_back(i);
        }
        return mx;
    }
};
// @lc code=end
