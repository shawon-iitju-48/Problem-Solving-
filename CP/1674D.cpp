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
    ll n;
    cin >> n;
    ll a[n], mn = INF;
    incfor(0, n)
    {
        cin >> a[i];
        if (a[i] < mn)
            mn = a[i];
    }
    if (n % 2 == 1)
    {
        if (a[0] == mn)
        {
            int flag = 0;
            for (int i = n - 3; i >= 1; i = i - 2)
            {
                if (min(a[i + 1], a[i + 2]) < max(a[i], a[i - 1]))
                {
                    flag = 1;
                    break;
                }
            }
            if (flag == 0)
                cout << "YES\n";
            else
                cout << "NO\n";
        }
        else
            cout << "NO\n";
    }
    else
    {
        int flag = 0;
        for (int i = n - 3; i >= 0; i = i - 2)
        {
            if (min(a[i + 1], a[i + 2]) < max(a[i], a[i - 1]))
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
            cout << "YES\n";
        else
            cout << "NO\n";
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