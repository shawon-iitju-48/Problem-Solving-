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
    ll a, b, temp = 3, x, flaga = 0, flagb = 0, sola, solb, lagbe;
    cin >> a >> b;
    lagbe = a;
    if (a == 1)
        sola = 0;
    else
    {
        while (temp--)
        {
            if ((a - 2) % 3 == 0)
            {
                x = (a - 2) / 3;
                break;
            }
            else
            {
                a++;
                flaga = 1;
            }
        }
        temp = 3;
        sola = 1 + (x * 2);
        if (flaga == 1)
            sola--;
    }
    if (b == 1)
        solb = 0;
    else
    {
        while (temp--)
        {
            if ((b - 2) % 3 == 0)
            {
                x = (b - 2) / 3;
                break;
            }
            else
            {
                b++;
                flagb = 1;
            }
        }
        solb = 1 + (x * 2);
        if (flagb == 1)
            solb--;
    }
    ll ans = solb - sola;
    lagbe = (lagbe * (lagbe + 1)) / 2;
    if (lagbe % 3 == 0)
        ans++;
    cout << ans << endl;
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
        cout << "Case " << t << ": ";
        solve();
    }
    return 0;
}
/**
 *    author:  lifelessnoob
 **/