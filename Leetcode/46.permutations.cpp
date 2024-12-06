/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> ans;
    void gen(int pivot, vector<int> nums)
    {
        if (pivot == nums.size() - 1)
        {
            ans.push_back(nums);
            return;
        }
        for (int i = pivot; i < nums.size(); i++)
        {
            vector<int> v = nums;
            swap(v[pivot], v[i]);
            gen(pivot + 1, v);
        }
    }
    vector<vector<int>> permute(vector<int> &nums)
    {
        gen(0, nums);
        return ans;
    }
};
// @lc code=end
