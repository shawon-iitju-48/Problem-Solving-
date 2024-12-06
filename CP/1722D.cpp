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
    ll n, sum = 0, ordhek, index;
    cin >> n;
    string s;
    cin >> s;
    ll a[n], x = 0;
    incfor(0, n)
    {
        if (s[i] == 'L')
            sum = sum + (i + 1 - 1);
        else
            sum = sum + n - i - 1;
    }
    ordhek = n / 2;
    incfor(0, ordhek)
    {
        if (s[i] == 'L')
        {
            sum = sum - (i + 1 - 1);
            s[i] = 'R';
            sum = sum + (n - i - 1);
            a[x++] = sum;
        }
        if (s[n - i - 1] == 'R')
        {
            index = n - i - 1;
            sum = sum - (n - index - 1);
            s[n - i - 1] = 'L';
            sum = sum + (index + 1 - 1);
            a[x++] = sum;
        }
    }
    incfor(0, x)
            cout
        << a[i] << sp;
    index = n - x;
    if (x > 0)
        sum = a[x - 1];
    while (index--)
        cout << sum << sp;
    cout << endl;
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