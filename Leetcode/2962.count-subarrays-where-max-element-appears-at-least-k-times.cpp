/*
 * @lc app=leetcode id=2962 lang=cpp
 *
 * [2962] Count Subarrays Where Max Element Appears at Least K Times
 */

// @lc code=start
class Solution
{
public:
    long long countSubarrays(vector<int> &nums, int k)
    {
        queue<int> q;
        auto max_ele = max_element(nums.begin(), nums.end());
        int mx = *max_ele;
        long long cnt = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == mx)
                q.push(i);

            while (q.size() > k)
                q.pop();

            if (q.size() == k)
                cnt += 1 + q.front();
        }
        return cnt;
    }
};
// @lc code=end
