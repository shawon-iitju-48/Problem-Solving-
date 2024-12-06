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
    ll n;
    cin >> n;
    ll a[n], cnt = 0, x = -1;
    input(n);
    incfor(0, n - 1)
    {
        if (a[i] == a[i + 1])
            cnt++;
    }
    if (cnt <= 1)
        cout << 0 << endl;
    else
    {
        cnt = 0;
        incfor(0, n - 2)
        {
            if ((i == n - 4 and ((a[n - 1] == a[n - 2] and a[n - 3] == a[n - 4]) or (a[n - 1] == a[n - 2] and a[n - 2] == a[n - 3]) or (a[n - 4] == a[n - 3] and a[n - 3] == a[n - 2]))) or i < n - 4 or (i == n - 3 and a[n - 1] == a[n - 2] and a[n - 2] == a[n - 3]))
            {
                if (a[i] == a[i + 1])
                {
                    a[i + 1] = a[i + 2] = x;
                    x--;
                    cnt++;
                }
            }
            // output(n);
            // cout << endl;
        }
            cout << cnt << endl;
    }
    // output(n);
    // cout << endl;
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