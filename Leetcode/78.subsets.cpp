/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> ans;
    vector<int> orgnums;
    void gen(int pivot, vector<int> v)
    {
        if (pivot == orgnums.size())
            return;

        for (int i = pivot; i < orgnums.size(); i++)
        {
            vector<int> new_v = v;
            new_v.push_back(orgnums[i]);
            ans.push_back(new_v);
            gen(i + 1, new_v);
        }
    }
    vector<vector<int>> subsets(vector<int> &nums)
    {
        orgnums = nums;
        vector<int> v;
        ans.push_back(v);
        gen(0, {});
        return ans;
    }
};
// @lc code=end
