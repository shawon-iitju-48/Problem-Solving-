#include <bits/stdc++.h>
using namespace std;
int m;
unordered_map<int, unordered_map<int, int>> dp;
int solve(int i, int state, vector<pair<int, vector<int>>> &dfactor)
{
    if (i >= dfactor.size())
        return state == ((1 << m) - 1) ? 0 : INT_MIN;

    if (dp[i].count(state))
        return dp[i][state];

    int skip = solve(i + 1, state, dfactor), newstate = state;
    for (auto &x : dfactor[i].second)
        newstate ^= (1 << (x - 1));

    int take = solve(i + 1, newstate, dfactor);
    take = take == INT_MIN ? INT_MIN : take + dfactor[i].first;

    return dp[i][state] = max(skip, take);
}
int main()
{
    int t;
    cin >> t;
    for (int test = 1; test <= t; test++)
    {
        dp.clear();
        int n, d, c, temp;
        cin >> n >> m;
        vector<pair<int, vector<int>>> dfactor;
        for (int i = 0; i < n; i++)
        {
            cin >> d >> c;
            vector<int> factor;
            for (int j = 0; j < c; j++)
            {
                cin >> temp;
                factor.push_back(temp);
            }
            dfactor.push_back({d, factor});
        }
        cout << "Case #" << test << ": " << max(0, solve(0, 0, dfactor)) << endl;
    }
    return 0;
}
