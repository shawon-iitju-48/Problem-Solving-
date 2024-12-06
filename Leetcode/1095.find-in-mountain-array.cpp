/*
 * @lc app=leetcode id=1095 lang=cpp
 *
 * [1095] Find in Mountain Array
 */

// @lc code=start
/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution
{
public:
    int findInMountainArray(int target, MountainArray &mountainArr)
    {
        int f = 0, l = mountainArr.length() - 1, mid, topPoint;
        while (f < l)
        {
            mid = f + (l - f) / 2;
            if (mountainArr.get(mid) < mountainArr.get(mid + 1))
                f = mid + 1;
            else
                l = mid;
        }
        topPoint = f;

        f = 0, l = topPoint;
        while (f <= l)
        {
            mid = f + (l - f) / 2;
            int x = mountainArr.get(mid);

            if (x == target)
                return mid;
            if (x < target)
                f = mid + 1;
            else
                l = mid - 1;
        }

        f = topPoint + 1, l = mountainArr.length() - 1;
        while (f <= l)
        {
            mid = f + (l - f) / 2;
            int x = mountainArr.get(mid);

            if (x == target)
                return mid;
            if (x < target)
                l = mid - 1;
            else
                f = mid + 1;
        }
        return -1;
    }
};
// @lc code=end
