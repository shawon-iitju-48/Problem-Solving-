#include <bits/stdc++.h>
using namespace std;

#define INF INT_MAX
#define MOD 1e9 + 7

int solve(int k, string &s)
{
    int i = 0, start = 0, mx = 0;
    for (int j = k; j < s.size(); i++, j++)
    {
        if (s[i] != s[j])
            start = i + 1;

        int x = (j - start + 1) / k;

        if (k * x > k)
            mx = max(mx, k * x);
    }
    return mx;
}
void start()
{
    string s;
    cin >> s;

    int mxLen = s.size() / 2, ans = 0;

    for (int i = 1; i <= mxLen; i++)
        ans = max(ans, solve(i, s));

    cout << ans << endl;
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
 *    created: 28-Nov-2024 17:03:44
 **/