#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const long long LINF = 1e18;

int solve(int idx, int currMax, int flag, vector<int>&cakes)
{
    if(idx>=cakes.size())
    return 0;

    int res;
    if(flag==0)
    {
        res=INT_MIN;
        for(int i=idx;i<cakes.size();i++)
        {
            
        }
    }
}
int main()
{
    int t,n,x;
    cin>>;
    while(t--)
    {
        cin>>n;
        vector<int>cakes;
        for(int i=0;i<n;i++)
        {
            cin>>x;
            cakes.push_back(x);
        }
        sort(begin(cakes), end(cakes));
        cout<<solve(0,-1, 0, cakes);
    }
    return 0;
}
