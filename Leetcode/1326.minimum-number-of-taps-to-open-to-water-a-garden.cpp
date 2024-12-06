/*
 * @lc app=leetcode id=1326 lang=cpp
 *
 * [1326] Minimum Number of Taps to Open to Water a Garden
 */

// @lc code=start
class Solution
{
public:
    int minTaps(int n, vector<int> &ranges)
    {
        vector<int> jump(n + 1, 0);
        for (int i = 0; i < ranges.size(); i++)
        {
            int lower = max(0, i - ranges[i]);
            int upper = min(i + ranges[i], n);
            jump[lower] = max(jump[lower], upper - lower);
        }
        int near = 0, far = 0, cnt = 0;
        for (int i = 0; i < jump.size(); i++)
        {
            if (near == n)
                return cnt;

            far = max(far, i + jump[i]);
            if (i == near)
            {
                cnt++;
                near = far;
            }
        }
        return -1;
    }
};
// @lc code=end
