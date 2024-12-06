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
    int n, m;
    cin >> n >> m;
    ll a[202][202], bn = -1;
    //ll b[202][202];
    incfor(0, n)
    {
        nincfor(0, m)
                cin >>
            a[i][j];
    }
    if (n == 1 || m == 1)
    {
        incfor(0, n)
        {
            nincfor(0, m)
            {
                if (a[i][j] > bn)
                    bn = a[i][j];
            }
        }
        cout << bn << endl;
    }
    else
    {
        incfor(0, n)
        {
            nincfor(0, m)
            {
                ll sum = 0;
                int start = i, end = j, temp;
                while (start != 0)
                {
                    start--;
                    end = i - start;
                    if ((j + end) >= 0 and (j + end) <= (m - 1))
                        sum = sum + a[start][j + end];
                    if ((j - end) >= 0 and (j - end) <= (m - 1))
                        sum += a[start][j - end];
                }
                start = i, end = j;
                while (start != (n - 1))
                {
                    start++;
                    end = start - i;
                    if ((j + end) >= 0 and (j + end) <= (m - 1))
                        sum = sum + a[start][j + end];
                    if ((j - end) >= 0 and (j - end) <= (m - 1))
                        sum += a[start][j - end];
                }
                sum += a[i][j];
                // b[i][j]=sum;
                if (bn < sum)
                    bn = sum;
            }
        }
        cout << bn << endl;
        // incfor(0, n)
        // {
        //     nincfor(0, m)
        //     {
        //         cout << b[i][j] << ' ';
        //     }
        //     cout << endl;
        // }
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