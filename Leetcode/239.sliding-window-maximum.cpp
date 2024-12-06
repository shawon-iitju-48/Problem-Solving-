/*
 * @lc app=leetcode id=239 lang=cpp
 *
 * [239] Sliding Window Maximum
 */

// @lc code=start
class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        vector<int> ans;
        deque<int> dq;
        for (int i = 0; i < nums.size(); i++)
        {
            while (!dq.empty() and nums[dq.back()] <= nums[i])
                dq.pop_back();
            while (!dq.empty() and dq.front() <= i - k)
                dq.pop_front();
            dq.push_back(i);
            if (i + 1 >= k)
                ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};
// @lc code=end
