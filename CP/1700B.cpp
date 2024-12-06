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

bool isSmaller(string str1, string str2)
{
    int n1 = str1.length(), n2 = str2.length();

    if (n1 < n2)
        return true;
    if (n2 < n1)
        return false;

    for (int i = 0; i < n1; i++)
    {
        if (str1[i] < str2[i])
            return true;
        else if (str1[i] > str2[i])
            return false;
    }
    return false;
}

string findDiff(string str1, string str2)
{
    if (isSmaller(str1, str2))
        swap(str1, str2);
    string str = "";
    int n1 = str1.length(), n2 = str2.length();
    int diff = n1 - n2;
    int carry = 0;
    for (int i = n2 - 1; i >= 0; i--)
    {
        int sub = ((str1[i + diff] - '0') - (str2[i] - '0') - carry);
        if (sub < 0)
        {
            sub = sub + 10;
            carry = 1;
        }
        else
            carry = 0;

        str.push_back(sub + '0');
    }
    for (int i = n1 - n2 - 1; i >= 0; i--)
    {
        if (str1[i] == '0' && carry)
        {
            str.push_back('9');
            continue;
        }
        int sub = ((str1[i] - '0') - carry);
        if (i > 0 || sub > 0)
            str.push_back(sub + '0');
        carry = 0;
    }
    reverse(str.begin(), str.end());
    return str;
}

void solve()
{
    int n;
    cin >> n;
    string m, p;
    cin >> m;
    if (m[0] == '8' || m[0] == '9')
    {
        p.resize(n + 1);
        incfor(0, n + 1)
            p[i] = '1';
    }
    else
    {
        p.resize(n);
        char x;
        x = m[0] + 2;
        incfor(0, n)
            p[i] = x;
    }
    cout <<findDiff(p,m) << endl;
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
        solve();
    }
    return 0;
}
/**
 *    author:  lifelessnoob
 **/