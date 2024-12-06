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
     ll n,cnt;
     cin>>n;
     string a[n] ,b[n],c[n];
     map<string,int>mp1,mp2,mp3;
     incfor(0,n)
     {
        cin>>a[i];
        mp1[a[i]]++;
     }
     incfor(0,n)
     {
        cin>>b[i];
         mp2[b[i]]++;
        }
     incfor(0,n)
     {
        cin>>c[i];
        mp3[c[i]]++;
        }
     incfor(0,n)
     {
        if(mp1.find(b[i])!=mp1.end())
        mp1[b[i]]++;
        if(mp1.find(c[i])!=mp1.end())
        mp1[c[i]]++;
     }
     incfor(0,n)
     {
        if(mp2.find(a[i])!=mp2.end())
        mp2[a[i]]++;
        if(mp2.find(c[i])!=mp2.end())
        mp2[c[i]]++;
     }
     incfor(0,n)
     {
        if(mp3.find(b[i])!=mp3.end())
        mp3[b[i]]++;
        if(mp3.find(a[i])!=mp3.end())
        mp3[a[i]]++;
     }
      int m1=0,m2=0,m3=0;
     for(auto it=mp1.begin();it!=mp1.end();it++)
     {
        if(it->second==1)
        m1+=3;
        else if(it->second==2)
        m1+=1;
     }
     for(auto it=mp2.begin();it!=mp2.end();it++)
     {
        if(it->second==1)
        m2+=3;
        else if(it->second==2)
        m2+=1;
     }
     for(auto it=mp3.begin();it!=mp3.end();it++)
     {
        if(it->second==1)
        m3+=3;
        else if(it->second==2)
        m3+=1;
     }
     cout<<m1<<sp<<m2<<sp<<m3<<endl;
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