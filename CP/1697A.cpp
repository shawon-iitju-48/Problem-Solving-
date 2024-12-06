#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t, n, m;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        int a[n],i,sum=0;
        for(i=0;i<n;i++)
        {
            cin>>a[i];
            sum+=a[i];
        }
        if(m>=sum)
        {
            cout<<'0'<<endl;
        }
        else cout<<sum-m<<endl;
    }
    return 0;
}