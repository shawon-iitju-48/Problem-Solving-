class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int m = nums1.size(), n = nums2.size(), koyta = (m + n + 1) / 2;
        if (m > n)
            return findMedianSortedArrays(nums2, nums1);
        int f = 0, l = m, mid;
        while (f <= l)
        {
            mid = (f + l) / 2;
            int la = INT_MIN, ra = INT_MAX, lb = INT_MIN, rb = INT_MAX, xd = koyta - mid;
            if (mid - 1 < m and mid - 1 >= 0)
                la = nums1[mid - 1];
            if (mid < m and mid >= 0)
                ra = nums1[mid];
            if (xd - 1 < n and xd - 1 >= 0)
                lb = nums2[xd - 1];
            if (xd < n and xd >= 0)
                rb = nums2[xd];

            if (lb > ra)
                f = mid + 1;
            else if (la > rb)
                l = mid - 1;
            else
            {
                if ((m + n) % 2 == 0)
                {
                    double ans;
                    ans = (max(lb, la) + min(ra, rb)) / 2.0;
                    return ans;
                }
                else
                    return max(la, lb);
            }
        }
        return 0;
    }
};