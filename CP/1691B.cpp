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
#define incfor(a, b) for (int i = a; i < b; i++)
#define decfor(a, b) for (int i = a; i > b; i--)
#define nincfor(a, b) for (int j = a; j < b; j++)
#define ndecfor(a, b) for (int j = a; j > b; --j)

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

void solve()
{
    ll n;
    cin >> n;
    ll a[n];
    incfor(0, n)
    {
        cin >>
            a[i];
    }
    map<ll, ll> mp;
    mp[a[0]] = 1;
    incfor(1, n)
    {
        if (mp.find(a[i]) == mp.end())
            mp[a[i]] = 1;
        else
            mp[a[i]] += 1;
    }
    int flag = 0;
    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        if (it->second == 1)
        {
            flag = 1;
            break;
        }
    }
    if (flag == 1)
        cout << -1 << endl;
    else
    {
        vector<int> v;
        v.pb(0);
        incfor(1, n)
        {
            if (a[i] != a[i - 1])
                v.pb(i);
        }
        v.pb(n);
        incfor(1, v.size())
        {
            cout << v[i] << sp;
            nincfor(v[i - 1] + 1, v[i])
                    cout
                << j << sp;
        }
        cout << endl;
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
        solve();
    }
    return 0;
}
/**
 *    author:  lifelessnoob
 **/