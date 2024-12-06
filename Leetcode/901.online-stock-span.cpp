/*
 * @lc app=leetcode id=901 lang=cpp
 *
 * [901] Online Stock Span
 */

// @lc code=start
class StockSpanner
{
public:
    deque<pair<int, int>> dq;
    StockSpanner()
    {
    }

    int next(int price)
    {
        if (dq.empty())
            dq.push_back({price, 1});
        else
        {
            int cnt = 0;
            while (!dq.empty() and dq.back().first <= price)
            {
                cnt += dq.back().second;
                dq.pop_back();
            }
            dq.push_back({price, cnt + 1});
        }
        return dq.back().second;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
// @lc code=end
