/*
 * @lc app=leetcode id=167 lang=cpp
 *
 * [167] Two Sum II - Input Array Is Sorted
 */

// @lc code=start
class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        int last=numbers.size()-1, init = 0, flag = 0;
        while (init < last)
        {
            int khojo = target - numbers[last];
            while (khojo >= numbers[init])
            {
                if (khojo == numbers[init])
                {
                    flag = 1;
                    break;
                }
                else
                    init++;
            }
            if (flag == 1)
                break;
            else
                last--;
        }
        vector<int> ans;
        ans.push_back(init + 1), ans.push_back(last + 1);
        return ans;
    }
};
// @lc code=end
