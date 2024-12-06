/*
 * @lc app=leetcode id=1838 lang=cpp
 *
 * [1838] Frequency of the Most Frequent Element
 */

// @lc code=start
class Solution
{
public:
    int maxFrequency(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        long long mx = 1, cnt = 1, sum = 0, j = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] == nums[i - 1])
                cnt++;
            else
            {
                sum = sum + (nums[i] - nums[i - 1]) * cnt;
                cnt++;
                while (sum > k and cnt > 0)
                {
                    cnt--;
                    sum = sum - (nums[i] - nums[j++]);
                }
            }
            mx = max(mx, cnt);
        }
        return mx;
    }
};
// @lc code=end
