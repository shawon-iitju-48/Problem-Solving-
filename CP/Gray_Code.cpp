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
    int n, pw;
    cin >> n;
    map<ll, ll> mp;
    mp[0] = 1;
    pw = pow(2, n);

    string str;
    str.resize(n);
    str.assign(n, '0');

    cout << str << endl;
    incfor(1, pw)
    {
        int flag = 0;
        incfor(0, n)
        {
            if (str[i] == '0')
            {
                str[i] = '1';
                stringstream geek(str);
                ll x = 0;
                geek >> x;
                if (mp.find(x) == mp.end())
                {
                    mp[x]=1;
                    cout << str << endl;
                    flag = 1;
                }
                else
                    str[i] = '0';
            }
            else
            {
                str[i] = '0';
                stringstream geek(str);
                ll x = 0;
                geek >> x;
                if (mp.find(x) == mp.end())
                {
                    mp[x]=1;
                    cout << str << endl;
                    flag = 1;
                }
                else
                    str[i] = '1';
            }
            if (flag == 1)
                break;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++)
    {
        solve();
    }
    return 0;
}
/**
 *    author:  lifelessnoob
 **/