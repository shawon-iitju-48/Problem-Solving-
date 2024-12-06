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
    ll n;
    cin >> n;
    string s, r;
    cin >> s;
    int flag = 0;
    incfor(0, n - 1)
    {
        r = s.substr(i, 2);
        if (r == "aa")
        {
            flag = 1;
            break;
        }
    }
    if (flag == 1)
        cout << 2 << endl;
    else
    {
        if (n == 2)
            cout << -1 << endl;
        else if (n > 2)
        {
            int fl = 0;
            incfor(0, n - 2)
            {
                r = s.substr(i, 3);
                if (r == "aba" or r == "aca")
                {
                    fl = 1;
                    cout << 3 << endl;
                    break;
                }
            }
            if (fl == 0)
            {
                if (n > 3)
                {
                    incfor(0, n - 3)
                    {
                        r = s.substr(i, 4);
                        if (r == "abca" or r == "acba")
                        {
                            fl = 1;
                            cout << 4 << endl;
                            break;
                        }
                    }
                }
                if (fl == 0)
                {
                    if (n > 6)
                    {
                        incfor(0, n - 6)
                        {
                            r = s.substr(i, 7);
                            if (r == "abbacca" or r == "accabba")
                            {
                                fl = 1;
                                cout << 7 << endl;
                                break;
                            }
                        }
                    }
                    if (fl == 0)
                        cout << -1 << endl;
                }
            }
        }
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
        // cout<<"Case "<<t<<": ";
        solve();
    }
    return 0;
}
/**
 *    author:  lifelessnoob
 **/