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
    string s[10], emp;
    int done = 0;
    incfor(0, 8)
            cin >>
        s[i];
    incfor(0, 8)
    {
        int flag = 0;
        if (s[i][0] != '.')
        {
            nincfor(1, 8)
            {
                if (s[i][j] != s[i][0])
                {
                    flag = 1;
                    break;
                }
            }
            if (flag == 0)
            {
                cout << s[i][0] << endl;
                done = 1;
                break;
            }
        }
    }
    if (done == 0)
    {
        incfor(0, 8)
        {
            int flag = 0;
            if (s[0][i] != '.')
            {
                nincfor(1, 8)
                {
                    if (s[j][i] != s[0][i])
                    {
                        flag = 1;
                        break;
                    }
                }
                if (flag == 0)
                {
                    cout << s[0][i] << endl;
                    break;
                }
            }
        }
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
 *    author:  shawon
 **/