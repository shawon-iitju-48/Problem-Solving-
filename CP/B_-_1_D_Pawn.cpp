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
    int n, k, q, x;
    cin >> n >> k >> q;
    map<int, int> mp;
    int ache[n+5] = {0};
    incfor(0, k)
    {
        cin >> x;
        ache[x] = 1;
        mp[i + 1] = x;
    }
    while (q--)
    {
        cin >> x;
        int dekhi = mp.find(x)->second;
        if (dekhi < n)
        {
            if (ache[dekhi + 1] == 0)
            {
                ache[dekhi] = 0;
                ache[dekhi + 1] = 1;
                mp[x] = dekhi + 1;
            }
        }
    }
    for (auto it = mp.begin(); it != mp.end(); it++)
        cout << it->second << sp;
    cout << endl;
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