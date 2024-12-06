#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast,unroll-loops")
#define ll long long
#define lli long long int
#define ull unsigned long long
#define PI 3.1415926535897932384626433832795
#define sp ' '
#define mem(a, value) memset(a, value, sizeof(a))
#define precision(a, b) cout << fixed << setprecision(a) << b << endl
#define incfor(a, b) for (int i = a; i < b; i++)
#define decfor(a, b) for (int i = a; i > b; i--)
#define nincfor(a, b) for (int j = a; j < b; j++)
#define ndecfor(a, b) for (int j = a; j > b; j--)
#define input(a, n) incfor(0, n) cin >> a[i];
#define output(a, n) incfor(0, n) cout << a[i] << sp;

void solve()
{
    int n, sum,a[25],b[25],gc;
    cin >> n;
    sum = n;
    input(a, n);
    gc = a[0];
    incfor(0, n)
    {
        gc = __gcd(a[i], gc);
        b[i] = __gcd(a[i], i + 1);
    }
    if (gc == 1)
        sum = 0;
    decfor(n - 1, -1)
    {
        int temp = b[i];
        ndecfor(n - 1, -1)
        {
            if (j != i)
                temp = __gcd(temp, a[j]);
        }
        if (temp == 1)
            sum = min(sum, n - i);
    }
    sum = min(sum, 3);
    cout << sum << endl;
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
 *    author:  shawon
 **/