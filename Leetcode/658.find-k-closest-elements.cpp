/*
 * @lc app=leetcode id=658 lang=cpp
 *
 * [658] Find K Closest Elements
 */

// @lc code=start
class Solution
{
public:
    vector<int> findClosestElements(vector<int> &arr, int k, int x)
    {
        auto it = lower_bound(arr.begin(), arr.end(), x);
        vector<int> ans;
        int cnt = 0, left = it - arr.begin() - 1, right = left + 1;

        while (left >= 0 and right < arr.size() and cnt <= k)
        {
            if (abs(x - arr[left]) <= abs(x - arr[right]))
            {
                ans.push_back(arr[left]);
                cnt++;
                left--;
            }
            else
            {
                ans.push_back(arr[right]);
                cnt++;
                right++;
            }
        }
        while (left >= 0 and cnt <= k)
        {
            ans.push_back(arr[left]);
            cnt++;
            left--;
        }
        while (right < arr.size() and cnt <= k)
        {
            ans.push_back(arr[right]);
            cnt++;
            right++;
        }
        sort(begin(ans), end(ans));
        return ans;
    }
};
// @lc code=end
