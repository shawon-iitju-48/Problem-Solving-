/*
 * @lc app=leetcode id=410 lang=cpp
 *
 * [410] Split Array Largest Sum
 */

// @lc code=start
class Solution
{
public:
    bool check(int minsum, vector<int> &nums, int &k)
    {
        int cnt = 1, sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            if (sum > minsum)
            {
                sum = nums[i];
                cnt++;
            }
        }
        if (cnt > k)
            return false;
        else
            return true;
    }
    int splitArray(vector<int> &nums, int k)
    {
        int f = INT_MIN, l = 0, mid, ans;
        for (int i = 0; i < nums.size(); i++)
        {
            f = max(f, nums[i]);
            l += nums[i];
        }
        while (f <= l)
        {
            mid = f + (l - f) / 2;
            if (check(mid, nums, k))
            {
                ans = mid;
                l = mid - 1;
            }
            else
                f = mid + 1;
        }
        return ans;
    }
};
// @lc code=end
