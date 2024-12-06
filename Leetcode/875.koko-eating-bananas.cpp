/*
 * @lc app=leetcode id=875 lang=cpp
 *
 * [875] Koko Eating Bananas
 */

// @lc code=start
class Solution
{
public:
    int minEatingSpeed(vector<int> &piles, int h)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        int mx = 0;
        for (int i = 0; i < piles.size(); i++)
            mx = max(piles[i], mx);
        int first = 1, last = mx, mid, flag, sum;
        while (first < last)
        {
            mid = (first + last) / 2;
            flag = 0, sum = 0;
            for (int i = 0; i < piles.size(); i++)
            {
                sum = sum + (piles[i] - 1) / mid + 1; // ceiling er bikolpo
                if (sum > h)
                {
                    flag = 1;
                    break;
                }
            }
            if (flag == 0)
                last = mid;
            else
                first = mid + 1;
        }
        return first;
    }
};
// @lc code=end
