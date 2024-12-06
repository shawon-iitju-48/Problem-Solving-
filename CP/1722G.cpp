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
ll countBits(ll number)
{
    return (ll)log2(number) + 1;
}
void solve()
{
    ll n, temp, xd, limit;
    cin >> n;
    temp = n / 2;
    limit = countBits(temp);
    ll jor[temp + 2], bejor[temp + 2], jc = 0, bc = 0;
    for (int i = 1; i <= temp; i++)
        jor[jc++] = i;
    if (n == 3)
        cout << "2 1 3\n";
    else if (temp % 2 == 0)
    {
        for (int i = 1; i <= temp; i++)
        {
            xd = i;
            xd = xd | (1 << limit);
            bejor[bc++] = xd;
        }
        if (n % 2 == 1)
            cout << 0 << sp;
        for (int i = 0; i < jc; i++)
            cout << jor[i] << sp << bejor[i] << sp;
        cout << endl;
    }
    else
    {
        for (int i = 1; i <= temp; i++)
        {
            xd = i;
            if (i == 1)
                xd = xd | (1 << limit);
            else if (i == temp)
                xd = xd | (1 << (limit + 1));
            else
            {
                xd = xd | (1 << limit);
                xd = xd | (1 << (limit + 1));
            }
            bejor[bc++] = xd;
        }
        if (n % 2 == 1)
            cout << 0 << sp;
        for (int i = 0; i < jc; i++)
            cout << jor[i] << sp << bejor[i] << sp;
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
 *    author:  shawon
 **/