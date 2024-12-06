/*
 * @lc app=leetcode id=1802 lang=cpp
 *
 * [1802] Maximum Value at a Given Index in a Bounded Array
 */

// @lc code=start
class Solution
{
public:
    int n, index, maxSum;
    long long doSum(long long start, long long total)
    {
        return (2 * start + (total - 1)) * total / 2;
    }
    bool check(int mxVal)
    {
        long long leftCount = index, rightCount = n - index - 1, sum = mxVal;
        if (mxVal - leftCount > 0)
            sum += doSum(mxVal - leftCount, leftCount);
        else
        {
            sum += doSum(1, mxVal - 1);
            sum -= (mxVal - leftCount - 1);
        }

        if (mxVal - rightCount > 0)
            sum += doSum(mxVal - rightCount, rightCount);
        else
        {
            sum += doSum(1, mxVal - 1);
            sum -= (mxVal - rightCount - 1);
        }
        return sum <= maxSum;
    }
    int maxValue(int nn, int in, int sum)
    {
        n = nn, index = in, maxSum = sum;
        int f = 1, l = 1e9, mid, ans;
        while (f <= l)
        {
            mid = f + (l - f) / 2;
            if (check(mid))
            {
                ans = mid;
                f = mid + 1;
            }
            else
                l = mid - 1;
        }
        return ans;
    }
};
// @lc code=end
