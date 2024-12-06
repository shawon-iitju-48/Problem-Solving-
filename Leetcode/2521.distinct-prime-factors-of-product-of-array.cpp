/*
 * @lc app=leetcode id=2521 lang=cpp
 *
 * [2521] Distinct Prime Factors of Product of Array
 */

// @lc code=start
class Solution
{
public:
    int distinctPrimeFactors(vector<int> &nums)
    {
        int n = 1;
        for (auto &num : nums)
            n *= num;
        int cnt = 0, last = 1;
        for (int i = 2; i * i <= n; i++)
        {
            if (n % i == 0)
            {
                cnt++;
                while (n % i == 0)
                    n /= i;
            }
            last = n;
        }
        if (last != 1)
            cnt++;
        return cnt;
    }
};
// @lc code=end
