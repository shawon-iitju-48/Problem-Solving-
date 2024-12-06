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
#define output(n) incfor(0, n) cout << a[i] << sp;
#define input(n) incfor(0, n) cin >> a[i];

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

void solve()
{
    string s;
    cin >> s;
    int a[200] = {0}, ch = 0;
    incfor(0, s.length())
    {
        if (a[s[i]] == 0)
            ch++;
        a[s[i]]++;
    }
    if (ch == 1)
        cout << "YES\n";
    else if (ch == 2)
    {
        int flag = 0;
        incfor(1, s.length())
        {
            if (s[i] == s[i - 1])
            {
                flag = 1;
                cout << "NO\n";
                break;
            }
        }
        if (flag == 0)
            cout << "YES\n";
    }
    else
    {
        int cnt = 0, konta;
        incfor(97, 123)
        {
            if (a[i] > 1)
            {
                cnt++;
                konta = i;
            }
        }
        if (cnt == 0)
            cout << "YES\n";
        else
        {
            string sd;
            sd.resize(30);
            int x = 0, prog[200] = {0}, flag = 0, kottheke;
            char c = s[0];
            incfor(1, s.length())
            {
                if (s[i] == c)
                {
                    kottheke = i + 1;
                    break;
                }
                if (prog[s[i]] > 0)
                {
                    flag = 1;
                    break;
                }
                else
                    sd[x++] = s[i];
                prog[s[i]]++;
            }
            if (flag == 1)
                cout << "NO\n";
            else
            {
                int br = 0;
                incfor(kottheke, s.length())
                {
                    if (br == x and s[i] == c)
                    {
                        br=0;
                        continue;
                    }
                    if (s[i] != sd[br++])
                    {
                        cout<<"NO\n";
                        flag = 1;
                        break;
                    }
                }
                if(flag==0)
                cout<<"YES\n";
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
 *    author:  lifelessnoob
 **/