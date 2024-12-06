/*
 * @lc app=leetcode id=1438 lang=cpp
 *
 * [1438] Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit
 */

// @lc code=start
class Solution
{
public:
    int longestSubarray(vector<int> &nums, int limit)
    {
        deque<int> inc, dec;
        int i = 0, mxlen = 0;
        for (int j = 0; j < nums.size(); j++)
        {
            while (!inc.empty() and nums[inc.back()] >= nums[j])
                inc.pop_back();

            inc.push_back(j);

            while (!dec.empty() and nums[dec.back()] <= nums[j])
                dec.pop_back();

            dec.push_back(j);

            while (!inc.empty() and !dec.empty() and abs(nums[inc.front()] - nums[dec.front()]) > limit)
            {
                while (!inc.empty() and inc.front() <= i)
                    inc.pop_front();

                while (!dec.empty() and dec.front() <= i)
                    dec.pop_front();
                i++;
            }
            mxlen = max(mxlen, j - i + 1);
        }
        return mxlen;
    }
};
// @lc code=end
