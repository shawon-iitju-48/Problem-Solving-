#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast,unroll-loops")
#define ll long long
#define lli long long int
#define ull unsigned long long
#define PI 3.1415926535897932384626433832795
#define sp ' '
#define precision(a, b) cout << fixed << setprecision(a) << b << endl
#define incfor(a, b) for (int i = a; i < b; i++)
#define decfor(a, b) for (int i = a; i > b; i--)
#define nincfor(a, b) for (int j = a; j < b; j++)
#define ndecfor(a, b) for (int j = a; j > b; j--)
#define input(n) incfor(0, n) cin >> a[i];
#define output(n) incfor(0, n) cout << a[i] << sp;

void solve()
{
    ll n;
    cin >> n;
    ll a[n];
    input(n);
    sort(a, a + n);
    ll cnt = 0, parbo = (a[0] * 2) - 1;
    incfor(1, n)
    {
        ll temp = a[i], tmp;
        temp = temp / parbo;
        temp--;
        if (temp < 0)
            temp = 0;
        cnt = cnt + temp;
        temp = temp * parbo;
        temp = a[i] - temp;
        while (temp > parbo)
        {
            tmp = temp / 2;
            tmp = max(tmp, temp - tmp);
            if (tmp > parbo)
                temp = temp - parbo;
            else
                temp = temp - tmp;
            cnt++;
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
        // cout<<"Case "<<t<<": ";
        solve();
    }
    return 0;
}
/**
 *    author:  shawon
 **/