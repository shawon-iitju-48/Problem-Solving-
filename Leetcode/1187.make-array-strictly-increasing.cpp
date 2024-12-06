
class Solution
{
public:
    unordered_map<int, unordered_map<int, int>> dp;
    int solve(int i, int prev, vector<int> &arr1, vector<int> &arr2)
    {
        if (i >= arr1.size())
            return 0;

        if (dp.count(i) and dp[i].count(prev))
            return dp[i][prev];

        int result = INT_MAX, sec = INT_MAX;

        if (arr1[i] > prev)
            result = min(result, solve(i + 1, arr1[i], arr1, arr2));

        int idx = upper_bound(arr2.begin(), arr2.end(), prev) - arr2.begin();

        if (idx < arr2.size())
            sec = solve(i + 1, arr2[idx], arr1, arr2);

        if (sec != INT_MAX)
            result = min(result, 1 + sec);

        return dp[i][prev] = result;
    }

    int makeArrayIncreasing(vector<int> &arr1, vector<int> &arr2)
    {
        if (arr1.size() == 1)
            return 0;

        sort(arr2.begin(), arr2.end());
        arr2.erase(unique(arr2.begin(), arr2.end()), arr2.end());

        int result = solve(0, INT_MIN, arr1, arr2);

        return result == INT_MAX ? -1 : result;
    }
};
