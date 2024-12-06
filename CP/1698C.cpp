#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast,unroll-loops")
#define ll long long
#define lli long long int
#define ld long double
#define ull unsigned long long
#define ulli unsigned long long int
#define PI 3.1415926535897932384626433832795

#define sp ' '
#define pb push_back
#define ppb pop_back
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vll vector<ll>
#define vpii vector<pii>
#define vpll vector<pll>

#define gcd(a, b) __gcd(a, b);
#define precision(a, b) cout << fixed << setprecision(a) << b << endl
#define incfor(a, b) for (int i = a; i < b; i++)
#define decfor(a, b) for (int i = a; i > b; i--)
#define nincfor(a, b) for (int j = a; j < b; j++)
#define ndecfor(a, b) for (int j = a; j > b; j--)

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

void solve()
{
    ll n, mms = 0;
    cin >> n;
    ll a[n];
    incfor(0, n)
    {
        cin >>
            a[i];
    }
    ll mx = a[0];
    incfor(1, n)
    {
        if (a[i] > mx)
            mx = a[i];
    }
    int flag = 0, i, j, k;

    for (i = 0; i < n-2; i++)
    {
        for (j = i + 1; j < n-1; j++)
        {
            for (k = j + 1; k < n; k++)
            {
                mms = a[i] + a[j] + a[k];
                if (mms > mx)
                {
                    flag = 1;
                    cout << "NO" << endl;
                }
                if (flag == 1)
                    break;
            }
            if (flag == 1)
                break;
        }
        if (flag == 1)
            break;
    }
    if (flag == 0)
        cout << "YES\n";
    // if (n == 3)
    // {
    //     ll sum = 0;
    //     map<ll, ll> mpp;
    //     incfor(0, n)
    //     {
    //         mpp[a[i]] = 1;
    //         sum += a[i];
    //     }
    //     cout<<sum<<endl;
    //     if (mpp.find(sum) == mpp.end())
    //         cout << "NO\n";
    //     else
    //         cout << "YES\n";
    // }
    // else
    // {
    //     int zero = 0, neg = 0, pos = 0;
    //     ll temp;
    //     incfor(0, n)
    //     {
    //         if (a[i] == 0)
    //         {
    //             zero = 1;
    //             break;
    //         }
    //     }
    //     incfor(0, n)
    //     {
    //         if (a[i] != 0)
    //         {
    //             temp = a[i];
    //             pos = 1;
    //             break;
    //         }
    //     }
    //     incfor(0, n)
    //     {
    //         if ((a[i] * -1) != temp)
    //         {
    //             neg = 1;
    //             break;
    //         }
    //     }
    //     if (pos == 0 and neg == 0)
    //         cout << "YES\n";
    //     else if (zero == 1 and pos == 1 and neg == 1)
    //     {
    //         int cntp = 0, cntn = 0, flag = 0;
    //         incfor(0, n)
    //         {
    //             if (a[i] == temp)
    //                 cntp++;
    //             else if (a[i] == (temp * -1))
    //                 cntn++;
    //             else if (a[i] != 0)
    //             {
    //                 flag = 1;
    //                 break;
    //             }
    //         }
    //         if (cntp > 1 or cntn > 1)
    //             flag = 1;
    //         if (flag == 1)
    //             cout << "NO" << endl;
    //         else
    //             cout << "YES" << endl;
    //     }
    //     else
    //         cout << "NO" << endl;
    // }
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
 *    author:  lifelessnoob
 **/