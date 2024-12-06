/*
 * @lc app=leetcode id=1552 lang=cpp
 *
 * [1552] Magnetic Force Between Two Balls
 */

// @lc code=start
class Solution
{
public:
    bool check(int mn, vector<int> &position, int m)
    {
        int j = 0;
        m--;
        for (int i = 1; i < position.size(); i++)
        {
            if (position[i] - position[j] >= mn)
            {
                m--;
                j = i;
            }
        }
        return m <= 0;
    }
    int maxDistance(vector<int> &position, int m)
    {
        sort(begin(position), end(position));
        int f = 1, l = 1e9, mid, ans;
        while (f <= l)
        {
            mid = f + (l - f) / 2;
            cout<<mid<<" ";
            if (check(mid, position, m))
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
