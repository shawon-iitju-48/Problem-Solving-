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
    int n, length;
    cin >> n;
    int a[n] = {0};
    map<string, int> mp;
    string s[n], pida;
    incfor(0, n)
    {
        cin >> s[i];
        mp[s[i]] = i;
    }
    string fh, lh;
    // for(auto it=mp.begin();it!=mp.end();it++)
    // cout<<it->first<<endl;
    incfor(0, n)
    {
        pida = s[i];
        length = pida.length() - 1;
        int di = 1;
        while (length--)
        {
            fh = pida.substr(0, di);
            lh = pida.substr(di, pida.length() - di);
            int flag = 0, flagg = 0;
            // cout<<fh<<sp<<lh<<endl;
            if (mp.find(fh) != mp.end())
            {
                flag = 1;
                if (fh == lh)
                    flagg = 1;
            }
            if (mp.find(lh) != mp.end())
            {
                flagg = 1;
                if (fh == lh)
                    flag = 1;
            }
            if (flag == 1 and flagg == 1)
            {
                a[i] = 1;
                break;
            }
            di++;
        }
    }
    incfor(0, n)
            cout
        << a[i];
    cout << endl;
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