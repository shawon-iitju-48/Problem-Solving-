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
    ll n, k, temp;
    cin >> n >> k;
    if (n % 2 == 0)
    {
        int flag = 0, flag1 = 0;
        temp = 2 * (k - 1);
        if (temp <= n)
        {
            temp = n - temp;
            if (temp % 2 == 0 and temp != 0)
            {
                cout << "YES\n";
                incfor(0, k - 1)
                        cout
                    << 2 << sp;
                cout << temp << endl;
            }
            else
                flag = 1;
        }
        else
            flag = 1;
        if (flag == 1)
        {
            if (k % 2 == 1)
                flag1 = 1;
            else
            {
                temp = k - 1;
                if (temp <= n)
                {
                    temp = n - temp;
                    if (temp % 2 == 1)
                    {
                        cout << "YES\n";
                        incfor(0, k - 1)
                                cout
                            << 1 << sp;
                        cout << temp << endl;
                    }
                    else
                        flag1 = 1;
                }
                else
                    flag1 = 1;
            }
        }
        if (flag == 1 and flag1 == 1)
            cout << "NO\n";
    }
    else
    {
        temp = k - 1;
        if (temp <= n)
        {
            temp = n - temp;
            if (temp % 2 == 1)
            {
                cout << "YES" << endl;
                incfor(0, k - 1)
                        cout
                    << 1 << sp;
                cout << temp << endl;
            }
            else
                cout << "NO\n";
        }
        else
            cout << "NO\n";
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