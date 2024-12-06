/*
 * @lc app=leetcode id=1046 lang=cpp
 *
 * [1046] Last Stone Weight
 */

// @lc code=start
class Solution
{
public:
    int lastStoneWeight(vector<int> &stones)
    {
        priority_queue<int> ans;
        for (int i = 0; i < stones.size(); i++)
            ans.push(stones[i]);
        int a, b;
        while (ans.size() > 1)
        {
            a = ans.top();
            ans.pop();
            b = ans.top();
            ans.pop();
            if (a - b != 0)
                ans.push(a - b);
        }
        if (ans.size() == 0)
            return 0;
        else
            return ans.top();
    }
};
// @lc code=end
