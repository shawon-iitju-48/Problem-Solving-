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
    ll n, m;
    cin >> n>>m;
    ll a[n], b[n], c[n];
    incfor(0, n)
            cin >>
        a[i];
    b[0] = c[n - 1] = 0;
    incfor(1, n)
    {
        if (a[i] < a[i - 1])
            b[i] = b[i - 1] + (a[i - 1] - a[i]);
        else
            b[i] = b[i - 1];
    }
    decfor(n - 2, -1)
    {
        if (a[i] < a[i + 1])
            c[i] = c[i + 1] + (a[i + 1] - a[i]);
        else
            c[i] = c[i + 1];
    }
    while (m--)
    {
        ll xx, yy;
        cin >> xx >> yy;
        xx--, yy--;
        if (xx < yy)
            cout << b[yy] - b[xx] << endl;
        else
            cout << c[yy] - c[xx] << endl;
    }
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