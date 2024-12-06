/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
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
                findsum(i, sum + candidates[i], temp, candidates, target);
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        findsum(0, 0, {}, candidates, target);
        return ans;
    }
};
// @lc code=end
