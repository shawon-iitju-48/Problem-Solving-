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
    ll m, n, cnt, sum = 0;
    cin >> m >> n;
    string s[m];
    int a[m + 1][n + 1] = {0};
    incfor(0, m)
    {
        cin >> s[i];
    }
    map<int, stack<pii>> mp;
    incfor(0, m - 1)
    {
        nincfor(0, n - 1)
        {
            cnt = 0;
            if (s[i][j] == '1')
                cnt++;
            if (s[i][j + 1] == '1')
                cnt++;
            if (s[i + 1][j] == '1')
                cnt++;
            if (s[i + 1][j + 1] == '1')
                cnt++;
            a[i][j] = cnt;
            if (cnt != 0)
                mp[cnt].push(make_pair(i, j));
        }
    }
    while (1)
    {
        int flag = 0;
        for (auto it = mp.begin(); it != mp.end(); it++)
        {
            if (it->second.size() != 0)
            {
                flag = 1;
                int prothom = it->second.top().first, ditio = it->second.top().second;
                it->second.pop();
                if (a[prothom][ditio] > 1)
                    sum = sum + 2;
                else
                    sum = sum + a[prothom][ditio];
                a[prothom][ditio] = 0;
                int q = 0, w = 0, e = 0, r = 0, temp;
                if (s[prothom][ditio] == '1')
                {
                    q++;
                    s[prothom][ditio] = '0';
                }
                if (s[prothom][ditio + 1] == '1')
                {
                    w++;
                    s[prothom][ditio + 1] = '0';
                }
                if (s[prothom + 1][ditio] == '1')
                {
                    e++;
                    s[prothom + 1][ditio] = '0';
                }
                if (s[prothom + 1][ditio + 1] == '1')
                {
                    r++;
                    s[prothom + 1][ditio + 1] = '0';
                }
                if (prothom - 1 >= 0)
                {
                    temp = a[prothom - 1][ditio];
                    a[prothom - 1][ditio] -= (q + w);
                    if (temp != a[prothom - 1][ditio] and a[prothom - 1][ditio] > 0)
                        mp[a[prothom - 1][ditio]].push(make_pair(prothom - 1, ditio));
                }
                if (prothom - 1 >= 0 and ditio + 1 < n - 1)
                {
                    temp = a[prothom - 1][ditio + 1];
                    a[prothom - 1][ditio + 1] -= w;
                    if (temp != a[prothom - 1][ditio + 1] and a[prothom - 1][ditio + 1] > 0)
                        mp[a[prothom - 1][ditio + 1]].push(make_pair(prothom - 1, ditio + 1));
                }
                if (ditio - 1 >= 0)
                {
                    temp = a[prothom][ditio - 1];
                    a[prothom][ditio - 1] -= (q + e);
                    if (temp != a[prothom][ditio - 1] and a[prothom][ditio - 1] > 0)
                        mp[a[prothom][ditio - 1]].push(make_pair(prothom, ditio - 1));
                }
                if (ditio - 1 >= 0 and prothom - 1 >= 0)
                {
                    temp = a[prothom - 1][ditio - 1];
                    a[prothom - 1][ditio - 1] -= q;
                    if (temp != a[prothom - 1][ditio - 1] and a[prothom - 1][ditio - 1] > 0)
                        mp[a[prothom - 1][ditio - 1]].push(make_pair(prothom - 1, ditio - 1));
                }
                if (prothom + 1 < m - 1)
                {
                    temp = a[prothom + 1][ditio];
                    a[prothom + 1][ditio] -= (e + r);
                    if (temp != a[prothom + 1][ditio] and a[prothom + 1][ditio] > 0)
                        mp[a[prothom + 1][ditio]].push(make_pair(prothom + 1, ditio));
                }
                if (prothom + 1 < m - 1 and ditio - 1 >= 0)
                {
                    temp = a[prothom + 1][ditio - 1];
                    a[prothom + 1][ditio - 1] -= e;
                    if (temp != a[prothom + 1][ditio - 1] and a[prothom + 1][ditio - 1] > 0)
                        mp[a[prothom + 1][ditio - 1]].push(make_pair(prothom + 1, ditio - 1));
                }
                if (ditio + 1 < n - 1)
                {
                    temp = a[prothom][ditio + 1];
                    a[prothom][ditio + 1] -= (r + w);
                    if (temp != a[prothom][ditio + 1] and a[prothom][ditio + 1] > 0)
                        mp[a[prothom][ditio + 1]].push(make_pair(prothom, ditio + 1));
                }
                if (ditio + 1 < n - 1 and prothom + 1 < m - 1)
                {
                    temp = a[prothom + 1][ditio + 1];
                    a[prothom + 1][ditio + 1] -= r;
                    if (temp != a[prothom + 1][ditio + 1] and a[prothom + 1][ditio + 1] > 0)
                        mp[a[prothom + 1][ditio + 1]].push(make_pair(prothom + 1, ditio + 1));
                }

                break;
            }
        }
        if (flag == 0)
            break;
    }
    cout << sum << endl;
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