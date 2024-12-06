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
    ll n, m;
    cin >> n >> m;
    string s[n];
    incfor(0, n)
    {
        cin >> s[i];
    }
    map<int, stack<pair<int, int>>> mp;
    incfor(0, m)
    {
        if (s[n - 1][i] == '.')
            mp[i].push(make_pair(n - 1, i));
        else
            mp[i].push(make_pair(-1, -1));
    }
    decfor(n - 2, -1)
    {
        nincfor(0, m)
        {
            int shuru = mp[j].top().first, shesh = mp[j].top().second;
            if (s[i][j] == '.' and shuru == -1)
                mp[j].push(make_pair(i, j));
            else if (s[i][j] == 'o')
                mp[j].push(make_pair(-1, -1));
            else if (s[i][j] == '*' and shuru!=-1)
            {
                s[i][j] = '.';
                s[shuru][shesh] = '*';
                mp[j].push(make_pair(shuru - 1, j));
            }
        }
    }
    incfor(0, n)
    {
        cout << s[i] << endl;
    }
    cout<<endl;
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