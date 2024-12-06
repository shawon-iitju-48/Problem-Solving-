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
    ll n, k;
    cin >> n >> k;
    ll a[n];
    map<ll, int> mp, np;
    incfor(0, n)
    {
        cin >>
            a[i];
        if (mp.find(a[i]) == mp.end())
            mp[a[i]] = i;
    }
    decfor(n - 1, -1) if (np.find(a[i]) == np.end())
        np[a[i]] = i;
    ll xx, yy;
    while (k--)
    {
        cin >> xx >> yy;
        int flag = 0, index;
        auto it = mp.find(xx);
        if (it == mp.end())
            cout << "NO\n";
        else
        {
            flag = 0;
            index = it->second;
            auto it = np.find(yy);
            if (it == np.end())
                cout << "NO\n";
            else
            {
                if (it->second >= index)
                    cout << "YES\n";
                else
                    cout << "NO\n";
            }
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