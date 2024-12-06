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
    map<ll, ll> mp;
    ll n, k;
    cin >> n >> k;
    mp.clear();
    incfor(0, n)
    {
        ll x;
        cin >> x;
        auto pos = mp.find(x);
        if (pos == mp.end())
            mp[x] = 1;
        else
            pos->second++;
    }
    ll start = 0, finals = 0, end = 0, l = 0, mx = -1, flag = 0, dd;
    map<ll, ll>::iterator temp;

    for (auto itr = mp.begin(); itr != mp.end(); itr++)
    {
        if (l == 0)
            dd = itr->first - 1;
        if (itr->second >= k and abs(itr->first - dd) == 1)
        {
            flag = 1;
            if (l == 0)
                start = itr->first;
            l++;
            temp = itr;
            dd = itr->first;
        }
        else
        {
            if (mx < l and l != 0)
            {
                mx = l;
                finals = start;
                end = temp->first;
                l = 0;
            }
            if (itr->second >= k and abs(itr->first - dd) != 1)
            {
                flag = 1;
                start = itr->first;
                l = 1;
                temp = itr;
                dd = itr->first;
            }
        }
        //  cout<<itr->first<<sp<<itr->second<<endl;
    }

    if (mx < l and l != 0)
    {
        mx = l;
        finals = start;
        end = temp->first;
        l = 0;
    }

    if (flag == 0)
        cout << -1 << endl;
    else
        cout << finals << sp << end << endl;
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