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
    ll n, a, b;
    cin >> n;
    string s = "a", t = "a";
    while (n--)
    {
        string test, sr, tr;
        cin >> a >> b >> test;
        if (a == 1)
        {
            incfor(0, b)
                s = s + test;
        }
        else
        {
            incfor(0, b)
                t = t + test;
        }
        sr.resize(s.size());
        sr = s;
        tr.resize(t.size());
        tr = t;
        sort(sr.begin(), sr.end());
        sort(tr.begin(), tr.end());
        reverse(tr.begin(), tr.end());
        // if (sr < tr)
        //     cout << "YES\n";
        // else
        //     cout << "NO\n";
        cout << sr << sp << tr << endl;
    }
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