#include <bits/stdc++.h>
using namespace std;

string solve(vector<int> &nums)
{
    for (int i = 0; i < nums.size(); i++)
    {
        if (abs(nums[i] - i - 1) > 1)
            return "NO";
    }
    return "YES";
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n;
        vector<int> nums;
        for (int i = 0; i < n; i++)
        {
            cin >> x;
            nums.push_back(x);
        }
        cout << solve(nums) << endl;
    }
    return 0;
}
