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
    int n, temp, sum = 0;
    cin >> n;
    string s[n];
    incfor(0, n)
            cin >>
        s[i];
    temp = n / 2;
    int a = -1, b = -1, c = -1, d = n, e = n, f = -1, g = n, h = n, koybar = n + 1;
    while (temp--)
    {
        a++, b++, c++, d--, e--, f++, g--, h--, koybar -= 2;
        int aa = a, bb = b, cc = c, dd = d, ee = e, ff = f, gg = g, hh = h;
        incfor(0, koybar)
        {
            int one = 0, zero = 0;
            if (s[aa][bb] == '0')
                zero++;
            else
                one++;
            if (s[cc][dd] == '0')
                zero++;
            else
                one++;
            if (s[ee][ff] == '0')
                zero++;
            else
                one++;
            if (s[gg][hh] == '0')
                zero++;
            else
                one++;
            sum += min(one, zero);
            bb++, cc++, ee--, hh--;
        }
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