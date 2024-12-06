#include <bits/stdc++.h>
using namespace std;

#define INF INT_MAX
#define MOD 1000000007

int solve(int i, int j, int k, string &a, string &b, string &c, unordered_map<int, unordered_map<int, unordered_map<int, int>>> &dp)
{
    if (k >= c.size())
        return 0;

    if (dp[i][j].count(k))
        return dp[i][j][k];

    int mn = INT_MAX;

    if (i < a.size())
    {
        if (a[i] == c[k])
            mn = min(mn, solve(i + 1, j, k + 1, a, b, c, dp));
        mn = min(mn, 1 + solve(i + 1, j, k + 1, a, b, c, dp));
    }
    if (j < b.size())
    {
        if (b[j] == c[k])
            mn = min(mn, solve(i, j + 1, k + 1, a, b, c, dp));
        mn = min(mn, 1 + solve(i, j + 1, k + 1, a, b, c, dp));
    }
    return dp[i][j][k] = mn;
}

void start()
{
    string a, b, c;
    cin >> a >> b >> c;
    unordered_map<int, unordered_map<int, unordered_map<int, int>>> dp;
    cout << solve(0, 0, 0, a, b, c, dp) << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    for (int casenum = 1; casenum <= t; casenum++)
    {
        // cout << "Case #" << casenum << ": ";
        start();
    }

    return 0;
}

/**
 *    author:  Md. Bokhtiar Nadeem Shawon
 *    created: 05-Dec-2024 22:41:54
 **/