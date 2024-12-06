#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int a[4];
        int cnt=0;
        for(int i=0;i<4;i++)
        {
            cin>>a[i];
            if(i!=0 && a[i]>a[0])
            cnt++;
        }
        cout<<cnt<<endl;
    }
    return 0;
}