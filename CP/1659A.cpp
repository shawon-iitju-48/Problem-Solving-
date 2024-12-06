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
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vll vector<ll>
#define vpii vector<pii>
#define vpll vector<pll>

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
    int n, r, b, bp, final, temp, x = 0;
    cin >> n >> r >> b;
    string s;
    s.resize(120);
    bp=b+1;
    final = r / bp;
    temp = r % bp;
    r=r-temp;
    int cnt = 0;
    while (r > 0)
    {
        bp = final;
        while (bp--)
            s[x++] = 'R';
        r = r - final;
        if (b > 0)
        {
            s[x++] = 'B';
            b--;
        }
    }
    incfor(0, x)
    {
        cout << s[i];
        if (s[i] == 'R')
            cnt++;
        if (cnt == final and temp > 0)
        {
            cout << 'R';
            temp--;
            cnt = 0;
        }
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