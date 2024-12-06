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
    string s[n], srev[n], swing = "12";
    int a[13][25] = {0}, b[13][25] = {0}, x, y;
    incfor(0, n)
    {
        cin >> s[i];
        swing[0] = s[i][1], swing[1] = s[i][0];
        srev[i] = swing;
    }
    incfor(0, n)
    {
        x = (s[i][0] % 97) + 1, y = (s[i][1] % 97) + 1;
        a[x][x + y]++;
        a[x][23]++;
    }
    incfor(0, n)
    {
        x = (srev[i][0] % 97) + 1, y = (srev[i][1] % 97) + 1;
        b[x][x + y]++;
        b[x][23]++;
    }
    ll uttor = 0;
    incfor(0, n - 1)
    {
        x = (s[i][0] % 97) + 1, y = (s[i][1] % 97) + 1;
        uttor = uttor + a[x][23] - a[x][x + y];
        if (a[x][x + y] > 0)
            a[x][x + y]--, a[x][23]--;
        uttor = uttor + b[y][23] - b[y][x + y];
        if (b[y][x + y] > 0)
            b[y][x + y]--, b[y][23]--;
    }
    cout << uttor << endl;
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