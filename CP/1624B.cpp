#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast,unroll-loops")
#define ll long long
#define gcd(a, b) __gcd(a, b);
#define precision(a, b) cout << fixed << setprecision(a) << b << endl
#define incfor(a, b) for (int i = a; i < b; i++)
#define decfor(a, b) for (int i = a; i > b; i--)
#define nincfor(a, b) for (int j = a; j < b; j++)
#define ndecfor(a, b) for (int j = a; j > b; j--)
#define output(n) incfor(0, n) cout << a[i] << sp;
#define input(n) incfor(0, n) cin >> a[i];

void solve()
{
    ll a,b,c,temp;
    cin>>a>>b>>c;
    if(abs(a-b)==abs(b-c))
    cout<<"YES\n";
    else if(a>=b and a>=c)
    {
         if((b+b-a)>=0 and (b+b-a)%c==0)
         cout<<"YES\n";
         else if((a+c)%b==0 and (a+c)/b!=b)
         cout<<"YES\n";
         else cout<<"NO\n";
    }
    else if(b>=c and b>=a)
    {
        temp=b-a;
        if((temp+b)%c==0)
        cout<<"YES\n";
        else if((b+b-c)%a==0)
        cout<<"YES\n";
        else cout<<"NO\n";
    }
    else
    {
        if((b+b-c)>=0 and (b+b-c)%a==0)
        cout<<"YES\n";
        else if((a+c)%b==0 and (a+c)/b!=b)
        cout<<"YES\n";
        else cout<<"NO\n";
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