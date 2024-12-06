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
int a[1050], b[1050], i;
void merge(int f1, int l1, int f2, int l2)
{
    int left[550], right[550], ls = 0, rs = 0, left1[550], right1[550];
    for (i = f1; i <= l1; i++)
    {
        left[ls] = a[i];
        left1[ls] = b[i];
        ls++;
    }
    for (i = f2; i <= l2; i++)
    {
        right[rs] = a[i];
        right1[rs] = b[i];
        rs++;
    }
    int j = 0;
    i = 0;
    while (i < ls && j < rs)
    {
        if (left[i] < right[j])
        {
            a[f1] = left[i];
            b[f1] = left1[i];
            f1++;
            i++;
        }
        else if (left[i] == right[j])
        {
            if (left1[i] > right1[j])
            {
                a[f1] = left[i];
                b[f1] = left1[i];
                f1++;
                i++;
            }
            else
            {
                a[f1] = right[j];
                b[f1] = right1[j];
                f1++;
                j++;
            }
        }
        else
        {
            a[f1] = right[j];
            b[f1] = right1[j];
            f1++;
            j++;
        }
    }
    while (i < ls)
    {
        a[f1] = left[i];
        b[f1] = left1[i];
        f1++;
        i++;
    }
    while (j < rs)
    {
        a[f1] = right[j];
        b[f1] = right1[j];
        f1++;
        j++;
    }
}
void mergesort(int f, int l)
{
    if (f == l)
        return;
    int m;
    m = f + ((l - f) / 2);
    mergesort(f, m);
    mergesort(m + 1, l);
    merge(f, m, m + 1, l);
}
void solve()
{
    incfor(1, 1001)
    {
        int sum = 0;
        nincfor(1, i + 1)
        {
            if (i % j == 0)
                sum++;
        }
        a[i] = sum;
        b[i] = i;
    }
    mergesort(1, 1000);
}
void sol()
{
    int xd;
    cin >> xd;
    cout << b[xd] << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc = 1;
    solve();
    cin >> tc;
    for (int t = 1; t <= tc; t++)
    {
        cout << "Case " << t << ": ";
        sol();
    }
    return 0;
}
/**
 *    author:  lifelessnoob
 **/