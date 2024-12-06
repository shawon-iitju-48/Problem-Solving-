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
#define mkpr make_pair
#define pii pair<int, int>
#define pll pair<ll, ll>
#define xx first
#define yy second
#define vi vector<int>
#define vll vector<ll>
#define vpii vector<pii>
#define vpll vector<pll>

#define gcd(a, b) __gcd(a, b);
#define incfor(a, n) for (int i = a; i < n; i++)
#define decfor(a, b) for (int i = a; i > b; i--)
#define nincfor(a, b) for (int j = a; j < b; j++)
#define ndecfor(a, b) for (int j = b; j > a; --j)

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

void solve()
{
    string s;
    cin >> s;
    int a[200] = {0};
    char blog = s[0];
    int onek = 0;
    incfor(0, s.length())
    {
        a[s[i]]++;
        if (blog != s[i])
            onek = 1;
    }
    int flag = 0, temp = -1;
    if (onek == 0)
        cout << s << endl;
    else
    {
        incfor(65, 91)
        {
            if (a[i] %2==1)
            {
                flag++;
                if (flag == 1)
                    temp = i;
            }
            if (flag == 2)
            {
                cout << "NO SOLUTION" << endl;
                break;
            }
        }
        if (flag < 2)
        {
            flag = 0;
            incfor(65, 91)
            {
                if (i != temp and a[i] % 2 != 0)
                {
                    cout << "NO SOLUTION" << endl;
                    flag = 1;
                    break;
                }
            }
            if (flag == 0)
            {
                incfor(65, 91)
                {
                    int x;
                    x = a[i] / 2;
                    char c = i;
                    while (x--)
                        cout << c;
                }
                if (temp != -1)
                {
                    char c = temp;
                    cout << c;
                }
                decfor(90, 64)
                {
                    int x;
                    x = a[i] / 2;
                    char c = i;
                    while (x--)
                        cout << c;
                }
                cout << endl;
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
    // cin >> tc;
    for (int t = 1; t <= tc; t++)
    {
        solve();
    }
    return 0;
}
/**
 *    author:  lifelessnoob
 **/