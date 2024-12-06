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
    ll n, q;
    cin >> n >> q;
    ll a[n];
    incfor(0, n)
            cin >>
        a[i];
    sort(a, a + n, greater<int>());
    incfor(1, n)
        a[i] = a[i] + a[i - 1];
    while (q--)
    {
        ll x, temp = 0, flag = 0;
        cin >> x;
        if (x > a[n - 1])
            cout << -1 << endl;
        else
        {
            int start = 0, end = n - 1;
            while (start <= end)
            {
                int mid = start + (end - start) / 2;
                if (x < a[mid])
                    end = mid - 1;
                else if (x > a[mid])
                    start = mid + 1;
                else if (x == a[mid])
                {
                    flag = 1;
                    cout << mid + 1 << endl;
                    break;
                }
            }
            if (flag == 0)
                cout << start + 1 << endl;

            // incfor(0, n)
            // {
            //     temp++;
            //     if (x <= a[i])
            //     {
            //         flag = 1;
            //         cout << temp << endl;
            //         break;
            //     }
            // }
            // if (flag == 0)
            //     cout << -1 << endl;
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
        solve();
    }
    return 0;
}
/**
 *    author:  lifelessnoob
 **/