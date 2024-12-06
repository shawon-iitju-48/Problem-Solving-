/*
 * @lc app=leetcode id=264 lang=cpp
 *
 * [264] Ugly Number II
 */

// @lc code=start
class Solution
{
public:
    int nthUglyNumber(int n)
    {
        vector<int> ans(n + 1, 1);
        int i1 = 1, i2 = 1, i3 = 1, target = 2, mn, x, y, z;
        while (target < ans.size())
        {
            x = ans[i1] * 2, y = ans[i2] * 3, z = ans[i3] * 5;
            mn = min({x, y, z});
            ans[target++] = mn;
            if (x == mn)
                i1++;
            if (y == mn)
                i2++;
            if (z == mn)
                i3++;
        }
        return ans[n];
    }
};
// @lc code=end
