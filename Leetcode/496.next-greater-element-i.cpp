/*
 * @lc app=leetcode id=496 lang=cpp
 *
 * [496] Next Greater Element I
 */

// @lc code=start
class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        stack<int> stk;
        unordered_map<int, int> mp;
        mp[nums2[nums2.size() - 1]] = -1;
        stk.push(nums2[nums2.size() - 1]);
        for (int i = nums2.size() - 2; i >= 0; i--)
        {
            int x = -1;
            while (!stk.empty())
            {
                if (nums2[i] < stk.top())
                {
                    x = stk.top();
                    break;
                }
                stk.pop();
            }
            mp[nums2[i]] = x;
            stk.push(nums2[i]);
        }
        vector<int> ans;
        for (int i = 0; i < nums1.size(); i++)
            ans.push_back(mp[nums1[i]]);
        return ans;
    }
};
// @lc code=end
