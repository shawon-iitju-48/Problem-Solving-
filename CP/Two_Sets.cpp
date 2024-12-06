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
#define mkpr make_pair
#define pii pair<int, int>
#define pll pair<ll, ll>
#define xx first
#define yy second
#define vi vector<int>
#define vll vector<ll>
#define vpii vector<pii>
#define vpll vector<pll>

#define gcd(a, b) __gcd(a, b);
#define incfor(a, n) for (int i = a; i < n; i++)
#define decfor(a, b) for (int i = a; i > b; i--)
#define nincfor(a, b) for (int j = a; j < b; j++)
#define ndecfor(a, b) for (int j = b; j > a; --j)

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

void solve()
{
    ll n, temp;
    cin >> n;
    double x = n / 2.0;
    temp = ceil(x);
    if (n == 1)
        cout << "NO" << endl;
    else if (n % 4 == 0)
    {
        cout << "YES" << endl;
        ll c[n], d[n], cc = 0, dd = 0;
        incfor(0, n / 2)
        {
            if (i % 2 == 0)
            {
                c[cc++] = i + 1;
                c[cc++] = n - i;
            }
            else
            {
                d[dd++] = i + 1;
                d[dd++] = n - i;
            }
        }
        cout << cc << endl;
        incfor(0, cc)
                cout
            << c[i] << sp;
        cout << endl;
        cout << dd << endl;
        incfor(0, dd)
                cout
            << d[i] << sp;
    }
    else if (temp % 2 == 0)
    {
        cout << "YES" << endl;
        ll a[n], b[n], x = 0, c[n], d[n], cc = 0, dd = 0;
        decfor(n, temp - 1)
            a[x++] = i;
        incfor(0, temp - 1)
            b[i] = i + 1;
        incfor(0, x)
        {
            if (i == 0)
                c[cc++] = a[i];
            else if (i % 2 == 0)
            {
                c[cc++] = a[i];
                c[cc++] = b[i - 1];
            }
            else
            {
                d[dd++] = a[i];
                d[dd++] = b[i - 1];
            }
        }
        cout << cc << endl;
        incfor(0, cc)
                cout
            << c[i] << sp;
        cout << endl;
        cout << dd << endl;
        incfor(0, dd)
                cout
            << d[i] << sp;
    }
    else
        cout << "NO" << endl;
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
        solve();
    }
    return 0;
}
/**
 *    author:  lifelessnoob
 **/