/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */

// @lc code=start
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int ln = prices.size() - 1, i = ln - 1, mx = 0, maxprice = prices[ln];
        while (i >= 0)
        {
            if (maxprice - prices[i] > 0)
                mx = max(mx, maxprice - prices[i]);
            else
                maxprice = prices[i];
            i--;
        }
        return mx;
    }
};
// @lc code=end