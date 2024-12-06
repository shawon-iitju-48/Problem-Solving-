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
#define input(a, n) incfor(0, n) cin >> a[i];
#define output(a, n) incfor(0, n) cout << a[i] << sp;

void solve()
{
    ll n, k;
    cin >> n >> k;
    ll a[k];
    input(a, k);
    ll flag = 0, comp;
    decfor(k - 1, 0)
    {
        if (a[i] - a[i - 1] > comp and i != k - 1)
        {
            flag = 1;
            cout << "No\n";
            break;
        }
        comp = a[i] - a[i - 1];
    }
    ll aro = n - k + 1;
    if (aro * comp < a[0] and flag == 0 and k != 1)
        cout << "No\n";
    else if (flag == 0)
        cout << "Yes\n";
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