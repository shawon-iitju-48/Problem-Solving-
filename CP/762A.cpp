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
    ll n, k, x = 0;
    cin >> n>>k;
    vector<ll> v,d;
    for (ll i = 1; i*i<=n; i++)
    {
        if (n % i == 0)
            v.push_back(i);
    }
    decfor(v.size()-1,-1)
    {
        if(n/v[i]!=v[i])
        d.push_back(n/v[i]);
    }
    if(k>(d.size()+v.size()))
    cout<<-1<<endl;
    else 
    {
        if(k<=v.size())
        cout<<v[k-1]<<endl;
        else cout<<d[k-v.size()-1]<<endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc = 1;
    // cin >> tc;
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