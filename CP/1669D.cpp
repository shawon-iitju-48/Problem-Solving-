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
#define ndecfor(a, b) for (int j = a; j > b; j--)

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

void solve()
{
    int n, flag = 0;
    cin >> n;
    string s;
    cin >> s;
    vi v;
    incfor(0, n)
    {
        if (s[i] == 'W')
        {
            v.pb(i);
            flag = 1;
        }
    }
    if (flag == 1)
        v.pb(n);
    if (v.size() == 0)
    {
        int flagb = 0, flagr = 0;
        incfor(0, n)
        {
            if (s[i] == 'R')
                flagr = 1;
            else if (s[i] == 'B')
                flagb = 1;
        }
        if (flagr == 1 and flagb == 1)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    else
    {
        int balok = 0;
        incfor(0, v.size() - 1)
        {
            int flagr = 0, flagb = 0;
            if (v[i + 1] - v[i] > 1)
            {
                nincfor(v[i], v[i + 1])
                {
                    if (s[j] == 'R')
                        flagr = 1;
                    else if (s[j] == 'B')
                        flagb = 1;
                }
                if (flagr == 0 or flagb == 0)
                {
                    balok = 1;
                    cout << "NO\n";
                    break;
                }
            }
        }
        if (balok == 0 and v[0] > 0)
        {
            int flagr = 0, flagb = 0;
            incfor(0, v[0])
            {
                if (s[i] == 'R')
                    flagr = 1;
                else if (s[i] == 'B')
                    flagb = 1;
            }
            if (flagr == 1 and flagb == 1)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
        else if (balok == 0)
            cout << "YES\n";
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