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
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    string s;
    cin >> s;

    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        if (mp.find(a[i]) == mp.end())
        {
            int xd = a[i] - 1, cnt = 0;
            if (s[i] == '0')
                cnt++;
            while (a[xd] != a[i])
            {
                if (s[xd] == '0')
                    cnt++;
                xd = a[xd] - 1;
            }
            xd = a[i] - 1;
            mp[a[i]] = cnt;
            while (a[xd] != a[i])
            {
                mp[a[xd]] = cnt;
                xd = a[xd] - 1;
            }
        }
    }
    for (int i = 0; i < n; i++)
        cout << mp[a[i]] << ' ';
    cout << endl;
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
 *    created: 30.11.2022 21:21:39
 **/