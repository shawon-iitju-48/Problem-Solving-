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
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vll vector<ll>
#define vpii vector<pii>
#define vpll vector<pll>

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
    string a, s;
    cin >> a >> s;
    int arr[50] = {0}, x = 0;
    int i = a.length() - 1, j = s.length() - 1, flag = 0;
    while (1)
    {
        if (i == -1 and j == -1)
            break;
        if (i >= 0 and j < 0)
        {
            flag = 1;
            cout << -1 << endl;
            break;
        }
        if (i < 0 and j >= 0)
        {
            for (int k = j; k >= 0; k--)
                arr[x++] = s[k] - 48;
            break;
        }
        int sbit = s[j] - 48, abit = a[i] - 48;
        if (sbit >= abit)
        {
            arr[x++] = sbit - abit;
            i--;
            j--;
        }
        else
        {
            j--;
            sbit = (10 * (s[j] - 48)) + sbit;
            int check = (sbit - abit) / 10;
            if (check == 0 and (sbit - abit) >= 0)
            {
                arr[x++] = sbit - abit;
                i--;
                j--;
            }
            else
                flag = 1;
        }
        if (flag == 1)
        {
            cout << -1 << endl;
            break;
        }
    }
    if (flag == 0)
    {
        int index = 0;
        decfor(x - 1, -1)
        {
            if (arr[i] != 0)
                index = 1;
            if (index == 1)
                cout << arr[i];
        }
        cout << endl;
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