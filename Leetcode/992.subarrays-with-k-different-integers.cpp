/*
 * @lc app=leetcode id=992 lang=cpp
 *
 * [992] Subarrays with K Different Integers
 */

// @lc code=start
class Solution
{
public:
    int subarraysWithKDistinct(vector<int> &nums, int k)
    {
        int pre = 0, next = 0, cnt = 0;
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++)
        {
            mp[nums[i]]++;
            if (mp.size() > k)
                pre = next;
            while (mp.size() > k)
            {
                mp[nums[pre]]--;
                if (mp[nums[pre]] == 0)
                    mp.erase(nums[pre]);
                pre++;
                next = pre;
            }
            while (mp[nums[next]] > 1)
            {
                mp[nums[next]]--;
                next++;
            }
            if (mp.size() == k)
                cnt += next - pre + 1;
        }
        return cnt;
    }
};
// @lc code=end
