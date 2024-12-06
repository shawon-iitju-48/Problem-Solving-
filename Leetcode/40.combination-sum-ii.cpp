/*
 * @lc app=leetcode id=40 lang=cpp
 *
 * [40] Combination Sum II
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> ans;
    void findsum(int j, int sum, vector<int> v, vector<int> &candidates, int target)
    {
        for (int i = j; i < candidates.size(); i++)
        {
            if (i > j and candidates[i] == candidates[i - 1])
                continue;
            if (sum + candidates[i] == target)
            {
                v.push_back(candidates[i]);
                ans.push_back(v);
                return;
            }
            else if (sum + candidates[i] > target)
                return;
            else
            {
                vector<int> temp = v;
                temp.push_back(candidates[i]);
                findsum(i + 1, sum + candidates[i], temp, candidates, target);
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        findsum(0, 0, {}, candidates, target);
        return ans;
    }
};
// @lc code=end
