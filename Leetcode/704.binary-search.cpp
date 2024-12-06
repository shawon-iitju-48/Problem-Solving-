/*
 * @lc app=leetcode id=704 lang=cpp
 *
 * [704] Binary Search
 */

// @lc code=start
int init = []
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ofstream out("user.out");
    cout.rdbuf(out.rdbuf());

    for (string s; getline(cin, s); cout << '\n')
    {
        string t;
        getline(cin, t);
        int tar = stoi(t);

        for (int i = 0, _i = 1, _n = s.length(); _i < _n; ++i, ++_i)
        {
            bool _neg = 0;
            if (s[_i] == '-')
                ++_i, _neg = 1;
            int v = s[_i++] & 15;
            while ((s[_i] & 15) < 10)
                v = v * 10 + (s[_i++] & 15);
            if (_neg)
                v = -v;
            if (v == tar)
            {
                cout << i;
                goto next;
            }
            if (v > tar)
                break;
        }
        cout << -1;
    next:;
    }
    exit(0);
    return 0;
}();
class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int ln = nums.size(), mid, first = 0, last = nums.size() - 1;
        while (first <= last)
        {
            mid = (last + first) / 2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] > target)
                last = mid - 1;
            else
                first = mid + 1;
        }
        return -1;
    }
};
// @lc code=end
