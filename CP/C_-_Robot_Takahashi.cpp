#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast,unroll-loops")
#define ll long long
#define lli long long int
#define ld long double
#define ull unsigned long long
#define ulli unsigned long long int
#define PI 3.1415926535897932384626433832795

#define sp ' '
#define pb push_back
#define ppb pop_back
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vll vector<ll>
#define vpii vector<pii>
#define vpll vector<pll>

#define gcd(a, b) __gcd(a, b);
#define precision(a, b) cout << fixed << setprecision(a) << b << endl
#define incfor(a, b) for (int i = a; i < b; i++)
#define decfor(a, b) for (int i = a; i > b; i--)
#define nincfor(a, b) for (int j = a; j < b; j++)
#define ndecfor(a, b) for (int j = a; j > b; j--)

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

void solve()
{
    ll n, x;
    cin >> n;
    string s;
    cin >> s;
    vpll v;
    incfor(0, n)
    {
        cin >> x;
        v.pb(make_pair(x, s[i] - 48));
    }
    sort(v.begin(), v.end());
    ll comp[n + 5], cnt = 0;
    incfor(0, n)
    {
        if (v[i].second == 0)
            cnt++;
        ll tmpp;
        if (i == (n - 1))
            tmpp = v[i].first + 5;
        else
        {
            double tmp = (v[i + 1].first - v[i].first) / 2.0;
            tmpp = v[i].first + ceil(tmp);
        }
        if (v[i].first < tmpp and cnt > 0)
            comp[i] = cnt;
        else if (i == 0)
            comp[i] = 0;
        else
            comp[i] = comp[i - 1];
    }
    incfor(1, n)
        v[i]
            .second += v[i - 1].second;
    ll maxone = v[n - 1].second, maxzero = 0, one = maxone, zero = maxzero;
    if (maxzero > comp[0])
        maxzero = comp[0];
    incfor(0, n)
    {
        one = v[n - 1].second - v[i].second;
        zero = (i + 1) - v[i].second;
        if (zero > comp[i])
            zero = comp[i];
        if ((one + zero) > (maxone + maxzero))
        {
            maxone = one;
            maxzero = zero;
        }
    }
    cout << maxone + maxzero << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++)
    {
        // cout<<"Case "<<t<<": ";
        solve();
    }
    return 0;
}
/**
 *    author:  lifelessnoob
 **/