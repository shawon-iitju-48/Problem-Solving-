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
    ll n, plus, minus, mx, cons, cnt = 0, lagbe;
    cin >> n;
    string s;
    cin >> s;
    for (int i = 0; i < n; i++)
    {
        plus = 0, minus = 0, cons = 1;
        for (int j = i; j < n; j++)
        {
            if (s[j] == '+')
                plus++;
            else if (s[j] == '-')
            {
                minus++;
                if (j > i)

                {
                    if (s[j] == s[j - 1])
                        cons++;
                }
            }
            mx = cons / 2;
            if (plus <= minus)
            {
                lagbe = minus - plus;
                if (lagbe % 3 == 0)
                {
                    ll temp = lagbe / 2;
                    if (temp <= mx)
                        cnt++;
                }
            }
        }
    }
    cout << cnt << endl;
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