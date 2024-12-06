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
int is_palindrome(int a, int b)
{
    int c, d, e, f;
    if (a < 10)
    {
        c = 0;
        d = a;
    }
    else
    {
        c = a / 10;
        d = a % 10;
    }
    if (b < 10)
    {
        e = 0;
        f = b;
    }
    else
    {
        e = b / 10;
        f = b % 10;
    }
    // cout<<c<<sp<<d<<sp<<e<<sp<<f<<endl;
    if (c == f && d == e)
        return 1;
    else
        return 0;
}
void solve()
{
    string s;
    int a, b, n, hr, min;
    cin >> s;
    a = stoi(s.substr(0, 2));
    b = stoi(s.substr(3));
    cin >> n;
    hr = n / 60;
    min = n % 60;

    int temphr = a, tempmin = b;
    temphr += hr;
    if (temphr > 23)
        temphr = temphr % 24;
    tempmin += min;
    if (tempmin > 59)
    {
        tempmin = tempmin % 60;
        temphr++;
        if (temphr > 23)
            temphr = temphr % 24;
    }
    int cnt = 0;
    if (is_palindrome(a, b))
        cnt++;
    while (temphr != a || tempmin != b)
    {
        // cout << temphr << ' ' << tempmin << endl;
        if (is_palindrome(temphr, tempmin))
            cnt++;
        temphr += hr;
        if (temphr > 23)
            temphr = temphr % 24;
        tempmin += min;
        if (tempmin > 59)
        {
            tempmin = tempmin % 60;
            temphr++;
            if (temphr > 23)
                temphr = temphr % 24;
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
        solve();
    }
    return 0;
}
/**
 *    author:  lifelessnoob
 **/