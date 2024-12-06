#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast,unroll-loops")
#define ll long long
#define ull unsigned long long
#define PI 2 * acos(0.0)
#define sp ' '
#define mem(a, value) memset(a, value, sizeof(a))
#define precision(a, b) cout << fixed << setprecision(a) << b << endl
#define incfor(a, b) for (int i = a; i < b; i++)
#define decfor(a, b) for (int i = a; i > b; i--)
#define nincfor(a, b) for (int j = a; j < b; j++)
#define ndecfor(a, b) for (int j = a; j > b; j--)
#define input(n) incfor(0, n) cin >> a[i];
#define output(n) incfor(0, n) cout << a[i] << sp;

void solve()
{
    ll n, p, sum;
    cin >> n;
    if(n%2==0)
    {
        decfor(n-2,0)
        cout<<i<<sp;
        cout<<n-1<<sp<<n<<endl;
    }
    else
    {
        cout<<1<<sp;
        decfor(n-2,1)
        cout<<i<<sp;
        cout<<n-1<<sp<<n<<endl;
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