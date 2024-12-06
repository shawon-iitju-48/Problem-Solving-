/*
 * @lc app=leetcode id=1863 lang=cpp
 *
 * [1863] Sum of All Subset XOR Totals
 */

// @lc code=start
class Solution
{
public:
    int ans = 0;
    vector<int> orgnums;
    void gen(int pivot, int current)
    {
        if (pivot == orgnums.size())
            return;

        for (int i = pivot; i < orgnums.size(); i++)
        {
            int cur = current;
            cur = cur ^ orgnums[i];
            ans = ans + cur;
            gen(i + 1, cur);
        }
    }
    int subsetXORSum(vector<int> &nums)
    {

        orgnums = nums;
        gen(0, 0);
        return ans;
    }
};
// @lc code=end
