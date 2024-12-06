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
bool sortbysec(const pair<char, int> &a, const pair<char, int> &b)
{
    return (a.second < b.second);
}
void solve()
{
    string s;
    vector<pair<char, int>> v;
    ll p, sum = 0, x;
    cin >> s >> p;
    incfor(0, s.length())
    {
        x = s[i];
        sum = sum + (x % 97) + 1;
        v.pb(make_pair(s[i], i));
    }
    if (sum <= p)
        cout << s << endl;
    else
    {
        sort(v.begin(), v.end(), greater<>());
        ll temp = 0, flag;
        incfor(0, s.length())
        {
            x = (v[i].first % 97) + 1;
            temp = temp + x;
            if (sum - temp <= p)
            {
                flag = i + 1;
                break;
            }
        }
        sort(v.begin() + flag, v.end(), sortbysec);
        incfor(flag, s.length())
                cout
            << v[i].first;
        cout << endl;
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