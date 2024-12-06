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
    ll n;
    cin >> n;
    ll a[n], sum = 0, lagbe, avg = 0, temp;
    map<ll, ll> mp;
    incfor(0, n)
    {
        cin >> a[i];
        mp[a[i]]++;
        avg += a[i];
    }
    double p = avg / (n * 1.0);
    p = p * (n - 2)*1.0;
    temp = ceil(p);
    if (p != temp)
        cout << sum << endl;
    else
    {
        lagbe = avg - temp;
        incfor(0, n - 1)
        {
            temp = lagbe - a[i];
            if (temp >= 0)
            {
                if (mp.find(temp) != mp.end())
                {
                    sum += mp[temp];
                    if (temp == a[i])
                        sum--;
                }
            }
            mp[a[i]]--;
        }
        cout << sum << endl;
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