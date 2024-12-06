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
    ll n;
    cin >> n;
    ll a[n], minus[n], plus[n], mm = 0, pp = 0;
    incfor(0, n)
    {
        cin >> a[i];
        if (a[i] < 0)
            minus[mm++] = a[i];
        else
            plus[pp++] = a[i];
    }
    sort(plus, plus + pp, greater<>());
    sort(minus, minus + mm);
    ll result = 1;
    if (pp == 0)
    {
        sort(minus,minus+mm,greater<>());
        incfor(0, 5)
            result = result * minus[i];
        cout << result << endl;
    }
    else if (pp <= 2)
    {
        if (n == 5)
        {
            incfor(0, 5)
                result = result * a[i];
            cout << result << endl;
        }
        else
        {
            incfor(0, 4)
                result = result * minus[i];
            result *= plus[0];
            cout << result << endl;
        }
    }
    else if (mm <= 1)
    {
        if (n == 5)
        {
            incfor(0, 5)
                result = result * a[i];
            cout << result << endl;
        }
        else
        {
            incfor(0, 5)
                result = result * plus[i];
            cout << result << endl;
        }
    }
    else
    {
        ll sub = minus[0] * minus[1];
        if (sub >= plus[0] * plus[1])
        {
            result = sub;
            if (mm > 3)
                cout << result * max(minus[2] * minus[3] * plus[0], plus[0] * plus[1] * plus[2]) << endl;
            else
                cout << sub * plus[0] * plus[1] * plus[2] << endl;
        }
        else
        {
            result = plus[0] * plus[1];
            if (pp == 3 or pp == 4)
                cout << result * sub * plus[2] << endl;
            else
                cout << result * max(minus[0] * minus[1] * plus[2], plus[2] * plus[3] * plus[4]) << endl;
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