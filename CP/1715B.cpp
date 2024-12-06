#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define incfor(a, b) for (int i = a; i < b; i++)
#define decfor(a, b) for (int i = a; i > b; i--)
#define nincfor(a, b) for (int j = a; j < b; j++)

void solve()
{
    ll n, k, b, sum, dilam;
    cin >> n >> k >> b >> sum;
    ll a[n], x = 1;
    if (k * b <= sum)
    {
        if ((k * b) + k - 1 <= sum)
        {
            dilam = sum - ((k * b) + k - 1);
            a[0] = (k * b) + k - 1;
        }
        else
        {
            dilam = 0;
            a[0] = sum;
        }
        incfor(0, n - 1)
        {
            if (dilam <= 0)
                a[x++] = 0;
            else
            {
                if (dilam - k + 1 >= 0)
                {
                    a[x++] = k - 1;
                    dilam = dilam - k + 1;
                }
                else
                {
                    a[x++] = dilam;
                    dilam = dilam - k + 1;
                }
            }
        }
        if (dilam > 0)
            cout << -1 << endl;
        else
        {
            incfor(0, x)
            {
                cout << a[i] << ' ';
            }
            cout << endl;
        }
    }
    else
        cout << -1 << endl;
}

int main()
{
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++)
        solve();
    return 0;
}