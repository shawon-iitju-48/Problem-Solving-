/*
 * @lc app=leetcode id=162 lang=cpp
 *
 * [162] Find Peak Element
 */

// @lc code=start
class Solution
{
public:
    // modified binary search. jekhane one halves baad
    //  dibo tokhoni jokhon eta guranteed hobe je other half
    //  eamar answer thakte pare eta sure ami.
    int findPeakElement(vector<int> &nums)
    {
        nums.push_back(INT_MIN);
        int f = 0, l = nums.size() - 2, mid, agerta;
        while (f <= l)
        {
            mid = f + (l - f) / 2;
            agerta = INT_MIN;
            if (mid - 1 >= 0)
                agerta = nums[mid - 1];
            if (nums[mid] > agerta and nums[mid] > nums[mid + 1])
                return mid;
            if (nums[mid] < nums[mid + 1])
                f = mid + 1;
            else
                l = mid - 1;
        }
        return 0;
    }
};
// @lc code=end
