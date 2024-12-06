/*
 * @lc app=leetcode id=90 lang=cpp
 *
 * [90] Subsets II
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> ans;
    void findsum(int i, vector<int> v, vector<int> &nums)
    {
        if (i >= nums.size())
            return;
        vector<int> temp = v;
        temp.push_back(nums[i]);
        ans.push_back(temp);
        findsum(i + 1, temp, nums);
        for (int j = i + 1; j < nums.size(); j++)
        {
            vector<int > t = v;
            if (nums[j] != nums[j - 1])
            {
                t.push_back(nums[j]);
                ans.push_back(t);
                findsum(j + 1, t, nums);
            }
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        ans.push_back({});
        findsum(0, {}, nums);
        return ans;
    }
};
// @lc code=end
