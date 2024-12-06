/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<int> v;
        set<vector<int>> st;
        for (int i = 0; i < nums.size() - 2; i++)
        {
            int target = -1 * nums[i], front = i + 1, back = nums.size() - 1;
            while (front < back)
            {
                int nxt = target - nums[back], flag = 0;
                while (nums[front] <= nxt and front < back)
                {
                    if (nums[front] == nxt)
                    {
                        v = {nums[i], nums[front], nums[back]};
                        sort(v.begin(), v.end());
                        st.insert(v);
                        flag = 1;
                        break;
                    }
                    else
                        front++;
                }
                back--;
                if (flag == 1)
                    front++;
            }
        }
        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }
};
// @lc code=end
