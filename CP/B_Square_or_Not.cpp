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
    int n, ok;
    cin >> n;
    string s;
    cin >> s;
    ok = sqrt(n);
    if (ok * ok != n)
        cout << "No" << endl;
    else
    {
        int flag = 0, cnt;
        for (int i = 0; i < ok; i++)
        {
            if (s[i] == '0')
            {
                flag = 1;
                cout << "No" << endl;
                break;
            }
        }
        if (flag == 0)
        {
            for (int i = n - ok; i < n; i++)
            {
                if (s[i] == '0')
                {
                    flag = 1;
                    cout << "No" << endl;
                    break;
                }
            }
            if (flag == 0)
            {
                for (int i = ok; i < n - ok; i++)
                {
                    if (i % ok == 0 or i % ok == (ok - 1))
                    {
                        if (s[i] == '0')
                        {
                            flag = 1;
                            cout << "No" << endl;
                        }
                    }
                    else
                    {
                        if (s[i] == '1')
                        {
                            flag = 1;
                            cout << "No" << endl;
                        }
                    }
                    if(flag==1)
                    break;
                }
                if(flag==0)
                cout<<"Yes"<<endl;
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
 *    created: 30.11.2022 21:21:39
 **/