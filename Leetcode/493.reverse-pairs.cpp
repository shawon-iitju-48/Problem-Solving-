/*
 * @lc app=leetcode id=493 lang=cpp
 *
 * [493] Reverse Pairs
 */

// @lc code=start
class Solution
{
public:
    int ans = 0;
    void merge(int start, int mid, int end, vector<int> &nums)
    {
        int l = 0, r = 0, le = 0, ri = 0, cnt = 0;
        vector<int> left, right;

        for (int i = start; i <= mid; i++)
            left.push_back(nums[i]);

        for (int i = mid + 1; i <= end; i++)
            right.push_back(nums[i]);

        while (l < left.size() and r < right.size())
        {
            if (left[l] > 2 * right[r])
                r++;
            else
            {
                cnt += r;
                l++;
            }
        }
        if (l < left.size())
            cnt = cnt + (left.size() - l) * right.size();
        ans = ans + cnt;

        l = left.size(), r = right.size();
        while (le < l and ri < r)
        {
            if (left[le] <= right[ri])
                nums[start++] = left[le++];
            else
                nums[start++] = right[ri++];
        }
        while (le < l)
            nums[start++] = left[le++];

        while (ri < r)
            nums[start++] = right[ri++];
    }
    void mergesort(int start, int end, vector<int> &nums)
    {
        if (start >= end)
            return;
        int mid = (start + end) / 2;
        mergesort(start, mid, nums);
        mergesort(mid + 1, end, nums);
        merge(start, mid, end, nums);
    }
    int reversePairs(vector<int> &nums)
    {
        mergesort(0, nums.size() - 1, nums);
        return ans;
    }
};
// @lc code=end
