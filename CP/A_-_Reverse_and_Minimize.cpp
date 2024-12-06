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
int pal(ll x)
{
    ll a[15] = {0}, it = 0, b[15] = {0}, bt = 0;
    while (x != 0)
    {
        a[it++] = x % 10;
        x = x / 10;
    }
    decfor(it - 1, -1)
        b[bt++] = a[i];
    incfor(0, it)
    {
        if (a[i] != b[i])
            return 0;
    }
    return 1;
}
ll reverse(ll in)
{
    ll out = 0;
    while (in)
    {
        out *= 10;
        out += in % 10;
        in /= 10;
    }
    return out;
}
void solve()
{
    ll n, k;
    cin >> n >> k;
    if (n < k)
        cout << 0 << endl;
    else
    {
        ll rev = reverse(k);
        if (k % 10 != 0)
        {
            ll sum = 0, temp = k;
            while (1)
            {
                if (temp <= n)
                {
                    sum++;
                    temp *= 10;
                }
                else
                    break;
            }
            if (pal(k) == 0)
            {
                while (1)
                {
                    if (rev <= n)
                    {
                        sum++;
                        rev *= 10;
                    }
                    else
                        break;
                }
            }
            cout << sum << endl;
        }
        else
            cout << 1<< endl;
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
        solve();
    }
    return 0;
}
/**
 *    author:  lifelessnoob
 **/