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
    ll n, m, x, y;
    cin >> n >> m;
    ll a[n];
    incfor(0, n)
            cin >>
        a[i];
    while (m--)
    {
        char s;
        cin >> s;
        if (s == 'P')
        {
            cin >> x >> y;
            swap(a[x], a[y]);
        }
        else if (s == 'S')
        {
            cin >> x;
            incfor(0, n)
                a[i] += x;
        }
        else if (s == 'M')
        {
            cin >> x;
            incfor(0, n)
                a[i] *= x;
        }
        else if (s == 'D')
        {
            cin >> x;
            incfor(0, n)
                a[i] /= x;
        }
        else if (s == 'R')
        {
            ll b[n], index = 0;
            incfor(0, n)
                b[i] = a[i];

            decfor(n - 1, -1)
                a[index++] = b[i];
        }
    }
    incfor(0, n)
    {
        cout << a[i];
        if (i != (n - 1))
            cout << sp;
    }
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
        cout << "Case " << t << ":\n";
        solve();
    }
    return 0;
}
/**
 *    author:  lifelessnoob
 **/