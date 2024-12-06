/*
 * @lc app=leetcode id=1201 lang=cpp
 *
 * [1201] Ugly Number III
 */

// @lc code=start
class Solution
{
public:
    long long lcm(long long a, long long b)
    {
        return (a / gcd(a, b)) * b;
    }
    int check(int x, int a, int b, int c)
    {
        long long sum = (x / a) + (x / b) + (x / c);
        return sum - (x / lcm(a, b)) - (x / lcm(b, c)) - (x / lcm(c, a)) + (x / lcm(lcm(a, b), c));
    }
    int nthUglyNumber(int n, int a, int b, int c)
    {
        long long f = 1, l = n * min({a, b, c}), mid, ans;
        while (f <= l)
        {
            mid = f + (l - f) / 2;
            int x = check(mid, a, b, c);
            if (x >= n)
            {
                l = mid - 1;
                ans = mid;
            }
            else
                f = mid + 1;
        }
        return ans;
    }
};
// @lc code=end
