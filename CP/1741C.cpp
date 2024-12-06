#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast,unroll-loops")
#define ll long long
#define lli long long int
#define ull unsigned long long
#define PI 3.1415926535897932384626433832795
#define sp ' '
#define mem(a, value) memset(a, value, sizeof(a))
#define precision(a, b) cout << fixed << setprecision(a) << b << endl
#define incfor(a, b) for (int i = a; i < b; i++)
#define decfor(a, b) for (int i = a; i > b; i--)
#define nincfor(a, b) for (int j = a; j < b; j++)
#define ndecfor(a, b) for (int j = a; j > b; j--)
#define input(a, n) incfor(0, n) cin >> a[i];
#define output(a, n) incfor(0, n) cout << a[i] << sp;

void solve()
{
    ll n, faul, flag, sum, cnt, presum = 0, fk;
    cin >> n;
    ll a[n];
    input(a, n);
    ll ans = n;
    decfor(n - 1, -1)
    {
        faul = n - i;
        flag = 0, sum = 0, cnt = 0, presum += a[i];
        ndecfor(i - 1, -1)
        {
            sum += a[j];
            cnt++;
            fk = 0;
            if (sum == presum)
            {
                faul = max(faul, cnt);
                sum = 0;
                cnt = 0;
                fk = 1;
            }
            if (sum > presum)
            {
                flag = 1;
                break;
            }
        }
        if (fk == 1 and flag == 0)
            ans = min(ans, faul);
    }
    cout << ans << endl;
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