#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t, a[4];
    cin>>t;
    for (int i=1;i<=t;i++)
    {
        for(int j=0;j<3;j++)
        cin>>a[j];
        sort(a,a+3);
        int sum=abs(a[0]-a[1])+abs(a[2]-a[1]);
        cout<<sum<<endl;
    }

}