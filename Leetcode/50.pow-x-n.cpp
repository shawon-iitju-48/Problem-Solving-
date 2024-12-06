/*
 * @lc app=leetcode id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

// @lc code=start
class Solution
{
public:
    double okpow(double x, int m)
    {
        int extra = m / 2;
        double a, ans;
        if (m == 1)
            return x;
        else if (m == 0)
            return 1;

        a = okpow(x, extra);

        if (extra == (m - extra))
            ans = a * a;
        else
            ans = a * a * x;
        return ans;
    }
    double myPow(double x, int n)
    {
        if (n >= 0)
            return okpow(x, n);
        else
        {
            double xd;
            xd = (1 * 1.00) / okpow(x, abs(n));
            return xd;
        }
    }
};
// @lc code=end
