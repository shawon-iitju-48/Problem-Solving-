#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast,unroll-loops")
#define ll long long
#define lli long long int
#define ull unsigned long long
#define PI 3.1415926535897932384626433832795
#define sp ' '
#define mem(a, value) memset(a, value, sizeof(a))
#define precision(a, b) cout << fixed << setprecision(a) << b << endl
#define incfor(a, b) for (int i = a; i < b; i++)
#define decfor(a, b) for (int i = a; i > b; i--)
#define nincfor(a, b) for (int j = a; j < b; j++)
#define ndecfor(a, b) for (int j = a; j > b; j--)
#define input(a, n) incfor(0, n) cin >> a[i];
#define output(a, n) incfor(0, n) cout << a[i] << sp;

void solve()
{
    int n;
    cin >> n;
    int a[n], b[1010] = {0};
    vector<pair<int, int>> v;
    input(a, n);
    decfor(n - 1, -1)
    {
        if (b[a[i]] == 0)
        {
            b[a[i]] = 1;
            v.push_back(make_pair(a[i], i + 1));
        }
    }
    int mx = -1;
    incfor(0, v.size())
    {
        nincfor(i, v.size())
        {
            if (__gcd(v[i].first, v[j].first) == 1)
                mx = max(mx, v[i].second + v[j].second);
        }
    }
    cout << mx << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++)
    {
        // cout<<"Case "<<t<<": ";
        solve();
    }
    return 0;
}
/**
 *    author:  shawon
 **/