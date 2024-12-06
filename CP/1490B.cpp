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
    ll n, cnt = 0;
    cin >> n;
    ll a[n], c0 = 0, c1 = 0, c2 = 0;
    incfor(0, n)
    {
        cin >> a[i];
        if (a[i] % 3 == 0)
            c0++;
        else if (a[i] % 3 == 1)
            c1++;
        else if (a[i] % 3 == 2)
            c2++;
    }
    //cout<<c0<<sp<<c1<<sp<<c2<<endl;
    while (1)
    {
        //cout<<c0<<sp<<c1<<sp<<c2<<endl;
        if (c0 == c1 and c1 == c2)
        {
            cout << cnt << endl;
            break;
        }
        if (c0 >= c1 and c0 >= c2)
        {
            c0--;
            c1++;
        }
        else if (c1 >= c0 and c1 >= c2)
        {
            c1--;
            c2++;
        }
        else if (c2 >= c1 and c2 >= c0)
        {
            c2--;
            c0++;
        }
        cnt++;
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