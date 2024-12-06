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

void solve(int t)
{
    int n, s, sum = 0, bum;
    cin >> n >> s;
    int a[n];
    incfor(0, n)
    {
        cin >> a[i];
        sum += a[i];
    }
    bum = sum;
    if (s > sum)
        cout << -1 << endl;
    else
    {
        int xd = 0, xdd = 0;
        int cnt = 0, start = 0, end = n - 1, shuru = 0, shesh = 0, flag1 = 0, flag2 = 0;
        while (1)
        {
            if (s == sum)
            {
                xd = cnt;
                break;
            }
            if (flag1 == 0)
            {
                if (a[start] == 0)
                {
                    shuru++;
                    start++;
                }
                else
                {
                    flag1 = 1;
                    start++;
                }
            }
            if (flag2 == 0)
            {
                if (a[end] == 0)
                {
                    shesh++;
                    end--;
                }
                else
                {
                    flag2 = 1;
                    end--;
                }
            }
            if (flag1 == 1 and flag2 == 1)
            {
                if (shuru < shesh)
                {
                    cnt = cnt + shuru + 1;
                    shuru = 0;
                    sum--;
                    flag1 = 0;
                }
                else
                {
                    cnt = cnt + shesh + 1;
                    shesh = 0;
                    sum--;
                    flag2 = 0;
                }
            }
        }
        cnt = 0, start = 0, end = n - 1, shuru = 0, shesh = 0, flag1 = 0, flag2 = 0, sum = bum;
        while (1)
        {
            if (s == sum)
            {
                xdd = cnt;
                break;
            }
            if (flag1 == 0)
            {
                if (a[start] == 0)
                {
                    shuru++;
                    start++;
                }
                else
                {
                    flag1 = 1;
                    start++;
                }
            }
            if (flag2 == 0)
            {
                if (a[end] == 0)
                {
                    shesh++;
                    end--;
                }
                else
                {
                    flag2 = 1;
                    end--;
                }
            }
            if (flag1 == 1 and flag2 == 1)
            {
                if (shuru <= shesh)
                {
                    cnt = cnt + shuru + 1;
                    shuru = 0;
                    sum--;
                    flag1 = 0;
                }
                else
                {
                    cnt = cnt + shesh + 1;
                    shesh = 0;
                    sum--;
                    flag2 = 0;
                }
            }
        }
        cout << min(xd, xdd) << endl;
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
        solve(t);
    }
    return 0;
}
/**
 *    author:  lifelessnoob
 **/