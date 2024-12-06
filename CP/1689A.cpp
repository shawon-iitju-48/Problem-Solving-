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
    int n, m, k;
    cin >> n >> m >> k;
    string a, b;
    cin >> a >> b;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int aexceed = 0, bexceed = 0;
    while (a.length() != 0 && b.length() != 0)
    {
        if (a[0] <= b[0])
        {
            if (aexceed < k)
            {
                bexceed = 0;
                cout << a[0];
                aexceed++;
                a.erase(0, 1);
            }
            else
            {
                aexceed = 0;
                cout << b[0];
                bexceed++;
                b.erase(0, 1);
            }
        }
        else if (a[0] > b[0])
        {
            if (bexceed < k)
            {
                aexceed = 0;
                cout << b[0];
                bexceed++;
                b.erase(0, 1);
            }
            else
            {
                bexceed = 0;
                cout << a[0];
                aexceed++;
                a.erase(0, 1);
            }
        }
    }
    cout << endl;
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