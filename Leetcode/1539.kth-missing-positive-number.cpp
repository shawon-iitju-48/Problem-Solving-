/*
 * @lc app=leetcode id=1539 lang=cpp
 *
 * [1539] Kth Missing Positive Number
 */

// @lc code=start
class Solution
{
public:
    int findKthPositive(vector<int> &arr, int k)
    {
        int f = 0, l = arr.size() - 1, mid, missing;
        while (f <= l)
        {
            mid = f + (l - f) / 2;
            missing = arr[mid] - mid - 1;
            if (missing < k)
                f = mid + 1;
            else
                l = mid - 1;
        }
        if (l >= 0 and l < arr.size())
        {
            missing = k - (arr[l] - l - 1);
            return arr[l] + missing;
        }
        else
        {
            missing = (arr[f] - f - 1) - k;
            return arr[f] - missing - 1;
        }
    }
};
// @lc code=end
