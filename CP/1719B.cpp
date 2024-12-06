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
#define output(n) incfor(0, n) cout << a[i] << sp;
#define input(n) incfor(0, n) cin >> a[i];

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

void solve()
{
    ll n, k;
    cin >> n >> k;
    ll a[n], d = 0;
    if (k == 0)
        cout << "NO\n";
    else
    {
        if (k % 2 == 1)
        {
            cout << "YES\n";
            ll x = 1;
            incfor(0, n / 2)
            {
                cout << x << sp << x + 1 << endl;
                x = x + 2;
            }
        }
        else if (k % 4 == 0)
            cout << "NO\n";
        else
        {
            cout << "YES\n";
            for (int i = 4; i <= n; i = i + 4)
                a[d++] = i;
            incfor(0, d)
                    cout
                << a[i] - 1 << sp << a[i] << endl;
            d = 0;
            for (int i = 1; i <= n; i = i + 4)
                a[d++] = i;
            incfor(0, d)
                    cout
                << a[i] + 1 << sp << a[i] << endl;
        }
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
 *    author:  lifelessnoob
 **/