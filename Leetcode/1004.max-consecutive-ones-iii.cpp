/*
 * @lc app=leetcode id=1004 lang=cpp
 *
 * [1004] Max Consecutive Ones III
 */

// @lc code=start
class Solution
{
public:
    int longestOnes(vector<int> &nums, int k)
    {
        int i = 0, mx = 0, one = 0, zero = 0;
        for (int j = 0; j < nums.size(); j++)
        {
            if (nums[j] == 1)
                one++;
            else
                zero++;
            while (zero > k)
            {
                if (nums[i] == 1)
                    one--;
                else
                    zero--;
                i++;
            }
            mx = max(mx, j - i + 1);
        }
        return mx;
    }
};
// @lc code=end
