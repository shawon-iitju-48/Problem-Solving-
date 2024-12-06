/*
 * @lc app=leetcode id=42 lang=cpp
 *
 * [42] Trapping Rain Water
 */

// @lc code=start
class Solution
{
public:
    int trap(vector<int> &height)
    {
        int j, ans = 0;
        for (j = 0; j < height.size(); j++)
        {
            if (height[j] != 0)
                break;
        }
        if (j == height.size())
            return ans;
        else
        {
            int mx = j;
            for (int i = j + 1; i < height.size(); i++)
            {
                if (height[i] <= height[i - 1] and height[i] < height[mx])
                    height[i] = height[i];
                else
                {
                    if (height[i] >= height[mx])
                    {
                        int dd = i - 1;
                        while (dd >= mx)
                        {
                            ans = ans + (height[mx] - height[dd]);
                            dd--;
                        }
                        mx = i;
                    }
                    else if (height[i] > height[i - 1])
                    {
                        int dd = i - 1;
                        while (height[dd] < height[i])
                        {
                            ans = ans + (height[i] - height[dd]);
                            height[dd] = height[i];
                            dd--;
                        }
                    }
                }
            }
            return ans;
        }
    }
};
// @lc code=end
