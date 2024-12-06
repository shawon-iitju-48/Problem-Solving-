/*
 * @lc app=leetcode id=2044 lang=cpp
 *
 * [2044] Count Number of Maximum Bitwise-OR Subsets
 */

// @lc code=start
class Solution
{
public:
    unordered_map<int,int>preans;
    int mx=0;
    vector<int> orgnums;
    void gen(int pivot, int current)
    {
        if (pivot == orgnums.size())
            return;

        for (int i = pivot; i < orgnums.size(); i++)
        {
            int cur = current;
            cur = cur | orgnums[i];
            mx=max(cur,mx);
            preans[cur]++;
            gen(i + 1, cur);
        }
    }
    int countMaxOrSubsets(vector<int> &nums)
    {
        orgnums = nums;
        gen(0, 0);
        return preans[mx];
    }
};
// @lc code=end
