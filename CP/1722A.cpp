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
      int n;
      cin>>n;
      string s;
      cin>>s;
      if(n==5)
      {
        int a[300]={0},b[300]={0},flag=0;
        incfor(0,5)
        a[s[i]]++;
        string p="Timur";
        incfor(0,5)
        b[p[i]]++;
        incfor(0,300)
        if(a[i]!=b[i])
        {
            flag=1;
            cout<<"NO\n";
            break;
        }
        if(flag==0)
        cout<<"YES\n";
      }
      else cout<<"NO\n";
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
        //cout<<"Case "<<t<<": ";
        solve();
    }
    return 0;
}
/**
 *    author:  shawon
 **/