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
#define input(a, n) incfor(0, n) cin >> a[i];
#define output(a, n) incfor(0, n) cout << a[i] << sp;

void solve()
{
    ll n;
    cin >> n;
    ll a[n], b[n], mx = 0, flag = 0, mxin, agei = 0, tibbot, mn = 1e10, rektu, mnin;
    incfor(0, n)
    {
        cin >> a[i];
        if (a[i] > mx)
        {
            mx = a[i];
            rektu = i;
        }
    }
    incfor(0, n)
    {
        cin >> b[i];
        if (flag == 0 and b[i] == a[i])
        {
            mxin = i;
            flag = 1;
        }
        if (b[i] < a[i])
            agei = 1;
        if (b[i] < mn)
        {
            mn = b[i];
            mnin = i;
        }
    }
    if (flag == 0)
    {
        ll i = rektu - 1, jvalue = mx + 1;
        if (i < 0)
            i = n - 1;
        while (i != rektu)
        {
            if (jvalue >= b[i])
            {
                mxin = i;
                flag = 1;
                break;
            }
            else
            {
                jvalue++;
                i--;
                if (i < 0)
                    i = n - 1;
            }
        }
        if (flag == 0)
            mxin = mnin;
            
    }
    if (agei == 1)
        cout << "NO\n";
    else
    {
        if (mxin == 0)
            tibbot = n - 1;
        else
            tibbot = mxin - 1;
        ll porikkha = 0, age = b[mxin];
        while (tibbot != mxin)
        {
            if (b[tibbot] > age + 1 and (b[tibbot] != a[tibbot]))
            {
                porikkha = 1;
                cout << "NO\n";
                break;
            }
            else
            {
                age = b[tibbot];
                tibbot--;
                if (tibbot < 0)
                    tibbot = n - 1;
            }
        }
        if (porikkha == 0)
            cout << "YES\n";
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