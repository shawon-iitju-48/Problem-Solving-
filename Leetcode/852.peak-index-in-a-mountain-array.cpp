class Solution
{
public:
    int peakIndexInMountainArray(vector<int> &arr)
    {
        int f = 0, l = arr.size() - 1, mid;
        while (f < l)
        {
            mid = f + (l - f) / 2;
            if (arr[mid] > arr[mid + 1])
                l = mid;
            else
                f = mid + 1;
        }
        return f;
    }
};