#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define incfor(a, b) for (int i = a; i < b; i++)
#define decfor(a, b) for (int i = a; i > b; i--)
#define input(n) incfor(0, n) cin >> a[i];


void solve()
{
    ll n;
    cin >> n;
    ll a[n], i = 0, j = n - 1, sum = 0;
    input(n);
    ll left = a[0], right = a[n - 1];
    while (i < j)
    {
        if (left < right)
        {
            i++;
            if(i<j)
            left += a[i];
        }
        else if (left > right)
        {
            j--;
            if(i<j)
            right += a[j];
        }
        else
        {
            i++;
            j--;
            sum = max(sum, left);
            if (i < j)
            {
                left += a[i];
                right += a[j];
            }
        }
    }
    cout<<sum<<endl;
}

int main()
{
    int tc = 1;
    for (int t = 1; t <= tc; t++)
    solve();
    return 0;
}
