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
    int n;
    cin >> n;
    char s[n][n];
    memset(s, 'X', sizeof s);
    queue<pii> q;
    q.push(make_pair(0, 0));
    s[0][0] = 'W';
    while (!q.empty())
    {
        int x = q.front().first, y = q.front().second;
        // cout<<x<<sp<<y<<endl;
        q.pop();
        char c;
        if (s[x][y] == 'W')
            c = 'B';
        else
            c = 'W';
        if (x - 1 > -1 and y - 2 > -1)
        {
            if (s[x - 1][y - 2] == 'X')
            {
                s[x - 1][y - 2] = c;
                q.push(make_pair(x - 1, y - 2));
            }
        }
        if (x - 1 > -1 and y + 2 < n)
        {
            if (s[x - 1][y + 2] == 'X')
            {
                s[x - 1][y + 2] = c;
                q.push(make_pair(x - 1, y + 2));
            }
        }
        if (x + 1 < n and y - 2 > -1)
        {
            if (s[x + 1][y - 2] == 'X')
            {
                s[x + 1][y - 2] = c;
                q.push(make_pair(x + 1, y - 2));
            }
        }
        if (x + 1 < n and y + 2 < n)
        {
            if (s[x + 1][y + 2] == 'X')
            {
                s[x + 1][y + 2] = c;
                q.push(make_pair(x + 1, y + 2));
            }
        }
        if (x - 2 > -1 and y - 1 > -1)
        {
            if (s[x - 2][y - 1] == 'X')
            {
                s[x - 2][y - 1] = c;
                q.push(make_pair(x - 2, y - 1));
            }
        }
        if (x - 2 > -1 and y + 1 < n)
        {
            if (s[x - 2][y + 1] == 'X')
            {
                s[x - 2][y + 1] = c;
                q.push(make_pair(x - 2, y + 1));
            }
        }
        if (x + 2 < n and y - 1 > -1)
        {
            if (s[x + 2][y - 1] == 'X')
            {
                s[x + 2][y - 1] = c;
                q.push(make_pair(x + 2, y - 1));
            }
        }
        if (x + 2 < n and y + 1 < n)
        {
            if (s[x + 2][y + 1] == 'X')
            {
                s[x + 2][y + 1] = c;
                q.push(make_pair(x + 2, y + 1));
            }
        }
    }
    incfor(0, n)
    {
        nincfor(0, n)
        {
            if(s[i][j]=='X')
            cout<<'B';
            else cout<< s[i][j];
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