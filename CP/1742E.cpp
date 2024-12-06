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
    ll n, q;
    cin >> n >> q;
    ll a[n], step[q], sorted[q];
    input(a, n);
    input(step, q);
    incfor(0, q)
        sorted[i] = step[i];
    map<ll, ll> mp;
    sort(sorted, sorted + q);
    ll last = 0, sum, flag;
    incfor(0, q)
    {
        flag = 0;
        if (mp.size() == 0)
            sum = 0;
        else
            sum = mp[sorted[i - 1]];
        for (int j = last; j < n; j++)
        {
            if (sorted[i] < a[j])
            {
                flag = 1;
                mp[sorted[i]] = sum;
                last = j;
                break;
            }
            sum = sum + a[j];
        }
        if (flag == 0)
        {
            mp[sorted[i]] = sum;
            last = n;
        }
    }
    incfor(0, q)
            cout
        << mp[step[i]] << sp;
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
 **/